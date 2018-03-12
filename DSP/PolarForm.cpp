#include "PolarForm.h"

int PolarForm::generatedID = 0;

PolarForm::PolarForm(double r, const Angle & radianW) : m_r(r), m_w(radianW.Radian()) { Init(); }
PolarForm::PolarForm(double r, double radianW) : m_r(r), m_w(radianW) { Init(); }

PolarForm::~PolarForm()
{
}

std::complex<double> PolarForm::Get(double r, const Angle & theta)
{
	return r * std::exp(std::complex<double>(0, theta.Radian()));
}

std::complex<double> PolarForm::Get(const Angle& offset)
{
	return m_r * std::exp(std::complex<double>(0, m_w + offset.Radian()));
}

double PolarForm::GetReal(double r, const Angle & theta)
{
	return r * std::exp(std::complex<double>(0, theta.Radian())).real();
}

double PolarForm::GetReal(const Angle & offset)
{
	return m_r * std::exp(std::complex<double>(0, m_w + offset.Radian())).real();
}

double PolarForm::GetImag(double r, const Angle & theta)
{
	return r * std::exp(std::complex<double>(0, theta.Radian())).imag();
}

double PolarForm::GetImag(const Angle & offset)
{
	return m_r * std::exp(std::complex<double>(0, m_w + offset.Radian())).imag();
}

PolarForm PolarForm::operator^(double power) const
{
	return PolarForm(std::pow(m_r, power), m_w * power);
}

PolarForm & PolarForm::operator^=(double power)
{
	m_r = std::pow(m_r, power);
	m_w *= power;
	return *this;
}

void PolarForm::BeginDraw()
{
	// window
	ImGui::SetNextWindowCollapsed(!m_windowOpened);
	sprintf_s(m_windowName, "PolarForm##%d", m_id);
	m_windowOpened = ImGui::Begin(m_windowName);
}

void PolarForm::InnerDraw()
{
	if(m_windowOpened)
	{
		bool isPlaying = Variable("play", false);
		ImGui::Checkbox("PlaySound", &Variable<bool>("play"));
		ImGui::Separator();
		if (isPlaying != Variable<bool>("play"))
		{
			if (isPlaying)
				StopStream();
			else
				PlayStream();
		}

		float &r = Variable("r", 1.0f);
		float &period = Variable("period", 1.0f/256.0f/*c tone*/);

		float bit = 1;
		switch (m_soundInfo.format)
		{
		case FMOD_SOUND_FORMAT_PCM8: bit = 7.0f; break;
		case FMOD_SOUND_FORMAT_PCM16: bit = 15.0f; break;
		case FMOD_SOUND_FORMAT_PCM24: bit = 23.0f; break;
		case FMOD_SOUND_FORMAT_PCM32: bit = 31.0f; break;
		default: break;
		}

		float MAX_R = std::pow(2.0f, bit) -1;
		ImGui::SliderFloat("r", &r, FLT_MIN, MAX_R);
		m_r = r;
		ImGui::Separator();
		ImGui::InputFloat("period", &period, 0.1f, 1.0f);
		float frequency = 1 / period;
		ImGui::InputFloat("frequency", &frequency, 0.1f, 1.0f);
		period = 1 / frequency;

		ImGui::Separator();
		// animation
		// n period per 1sec
		// 1 / n*period
		float theta = Variable("theta_animation", 0.0f);
		ImGui::SliderFloat("theta", &theta, -1, 361);
		if (theta < 0)
		{
			theta = 360;
		}
		if (theta > 360)
		{
			theta = 0;
		}
		std::complex<double> c(0, theta * 0.0174533);
		auto result = std::exp(c);

		float &zoom = Variable("zoom", 50.0f);

		ImGui::InputFloat("zoom", &zoom);

		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		if (draw_list)
		{
			
			Vector2 pos = ImGui::GetCursorScreenPos();

			auto left_top = ImGui::GetWindowContentRegionMin();
			auto right_bottom = ImGui::GetWindowContentRegionMax();


			float proportionalR = zoom;
			//float proportionalR = zoom * std::log2((r + MAX_R) / MAX_R);

			pos += zoom;

			draw_list->AddCircle(pos, proportionalR, ImGui::ColorConvertFloat4ToU32(ImVec4(1, 1, 1, 1)), 30);

			auto target = pos;
			target.x += proportionalR * float(result.real());
			target.y -= proportionalR * float(result.imag());
			draw_list->AddCircleFilled(target, 3, ImGui::ColorConvertFloat4ToU32(ImVec4(0, 1, 0, 1)));

			pos += proportionalR;
			pos.x -= proportionalR + zoom;

			ImGui::SetCursorScreenPos(pos);

		}
	}
	ImGui::End();
	// slide bar for theta
	// slide for factor
	// check for auto play
	// check for wave draw
	// circle
	//		dot
	//	if wave draw
	//		line
	//		plot
}

void PolarForm::EndDraw()
{
	// window
}

FMOD_RESULT PolarForm::StreamReadCallback(void *pData, unsigned int datalen)
{
	signed short *pBuffer = (signed short *)pData;
	unsigned int len = datalen / (m_soundInfo.numchannels * sizeof(signed short));

	float &theta = Variable("theta", 0.0f);
	// 360 in 1sec = sampling rate 44100 in 1sec
	// per sample = 360degree / 44100sample = 0.00816326530612244897959183673469 angle per sample
	// 360 in Nsec = sampling rate 44100 in 1sec
	// per sample = 360degree / (44100sample*N) = 0.00816326530612244897959183673469 / N angle per sample
	float delta = 0.00816326530612244897959183673469f / Variable<float>("period");

	for (unsigned int count = 0; count < len; count++)     // >>2 = 16bit stereo (4 bytes per sample)
	{
	  double sinT = GetImag(FromDegree(theta));
		for (int channel = 0; channel < m_soundInfo.numchannels ; ++channel)
		{
			*pBuffer++ = (signed short)(sinT);    // bit for channel
		}
		theta += delta;
	}

	//	static float  t1 = 0, t2 = 0;        // time
	//	static float  v1 = 0, v2 = 0;        // velocity
	//	signed short *stereo16bitbuffer = (signed short *)data;
	//
	//	for (unsigned int count = 0; count < (datalen >> 2); count++)     // >>2 = 16bit stereo (4 bytes per sample)
	//	{
	//		*stereo16bitbuffer++ = (signed short)(Common_Sin(t1) * 32767.0f);    // left channel
	//		*stereo16bitbuffer++ = (signed short)(Common_Sin(t2) * 32767.0f);    // right channel
	//
	//		t1 += 0.01f + v1;
	//		t2 += 0.0142f + v2;
	//		v1 += (float)(Common_Sin(t1) * 0.002f);
	//		v2 += (float)(Common_Sin(t2) * 0.002f);
	//	}
	//
	//	return FMOD_OK;

	return FMOD_OK;
}

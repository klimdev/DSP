#include "PolarForm.h"

int PolarForm::generatedID = 0;

PolarForm::PolarForm(double r, const Angle & radianW) : r(r), w(radianW.Radian()) { Init(); }
PolarForm::PolarForm(double r, double radianW) : r(r), w(radianW) { Init(); }

PolarForm::~PolarForm()
{
}

std::complex<double> PolarForm::Get(double r, const Angle & theta)
{
	return r * std::exp(std::complex<double>(0, theta.Radian()));
}

std::complex<double> PolarForm::Get(const Angle& offset)
{
	return r * std::exp(std::complex<double>(0, w + offset.Radian()));
}

std::complex<double> PolarForm::GetReal(double r, const Angle & theta)
{
	return r * std::exp(std::complex<double>(0, theta.Radian())).real();
}

double PolarForm::GetReal(const Angle & offset)
{
	return r * std::exp(std::complex<double>(0, w + offset.Radian())).real();
}

std::complex<double> PolarForm::GetImag(double r, const Angle & theta)
{
	return r * std::exp(std::complex<double>(0, theta.Radian())).imag();
}

double PolarForm::GetImag(const Angle & offset)
{
	return r * std::exp(std::complex<double>(0, w + offset.Radian())).imag();
}

PolarForm PolarForm::operator^(double power) const
{
	return PolarForm(std::pow(r, power), w * power);
}

PolarForm & PolarForm::operator^=(double power)
{
	r = std::pow(r, power);
	w *= power;
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
	//if (ImGui::Begin("PolarFormTest"))
	{
		//m_windowMode = !ImGui::IsWindowCollapsed();
			
		//if (m_windowMode)
		{
			ImDrawList* draw_list = ImGui::GetWindowDrawList();
			if (draw_list)
			{
				static bool animate = true;
				ImGui::Checkbox("Animate", &animate);

				float &r = Variable("r", 1.0f);
				float &theta = Variable("theta", 0.0f);
				float &delta = Variable("delta", 0.1f);


				ImGui::SliderFloat("r", &r, 0, 2);
				ImGui::SliderFloat("theta", &theta, -1, 361);
				ImGui::SliderFloat("delta", &delta, -1, 1);
				if (animate)
				{
					theta += delta;
				}
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

				float &zoom = Variable("zoom", 25.0f);
				
				ImGui::InputFloat("zoom", &zoom);

				Vector2 pos = ImGui::GetCursorScreenPos();

				static ImVec2 size(50, 50);
				static ImVec2 center(25, 25);
				auto left_top = ImGui::GetWindowContentRegionMin();
				auto right_bottom = ImGui::GetWindowContentRegionMax();

				pos += r*zoom;

				draw_list->AddCircle(pos, r*zoom, ImGui::ColorConvertFloat4ToU32(ImVec4(1, 1, 1, 1)), 30);

				auto target = pos;
				target.x += r * zoom * result.real();
				target.y -= r * zoom * result.imag();
				draw_list->AddCircleFilled(target, 3, ImGui::ColorConvertFloat4ToU32(ImVec4(0, 1, 0, 1)));

				pos += r * zoom;
				pos.x -= 2 * r * zoom;

				ImGui::SetCursorScreenPos(pos);


			}
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

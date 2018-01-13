#include "PolarForm.h"



PolarForm::PolarForm()
{
}


PolarForm::~PolarForm()
{
}

void PolarForm::BeginDraw()
{
	// window
}

void PolarForm::InnerDraw()
{
	if (ImGui::Begin("PolarFormTest"))
	{

		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		if (draw_list)
		{
			static bool animate = true;
			ImGui::Checkbox("Animate", &animate);

			static float r = 1;
			static float theta = 0;
			static float delta = 0.1;
			

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

			auto pos = ImGui::GetWindowPos();

			static ImVec2 size(50, 50);
			static ImVec2 center(25, 25);
			auto left_top = ImGui::GetWindowContentRegionMin();
			auto right_bottom = ImGui::GetWindowContentRegionMax();

			pos.x += left_top.x + size.x;
			pos.y += left_top.y + size.y + 50;

			draw_list->AddCircle(pos, 50, ImGui::ColorConvertFloat4ToU32(ImVec4(1,1,1,1)), 30);

			auto target = pos;
			target.x += 50 * result.real();
			target.y -= 50 * result.imag();
			draw_list->AddCircleFilled(target, 3, ImGui::ColorConvertFloat4ToU32(ImVec4(0, 1, 0, 1)));

		}

		ImGui::End();
	}

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

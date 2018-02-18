#include "ImGuiBaseWindow.h"

ImGuiBaseWindow::ImGuiBaseWindow()
{
}


ImGuiBaseWindow::~ImGuiBaseWindow()
{
}

void ImGuiBaseWindow::BeginDraw()
{
	ImGui::Begin(m_windowName.c_str(), &m_windowOpened);
}

void ImGuiBaseWindow::EndDraw()
{
	if (m_windowOpened)
		ImGui::End();
}

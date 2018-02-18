#pragma once
#include "ImGuiBase.h"

#include <string>

class ImGuiBaseWindow :
	public ImGuiBase
{
public:
	ImGuiBaseWindow();
	virtual ~ImGuiBaseWindow();

	// Inherited via ImGuiBase
	virtual void BeginDraw() override;
	virtual void InnerDraw() = 0;
	virtual void EndDraw() override;

protected:
	std::string				m_windowName;
	bool							m_windowOpened = false;
	ImGuiWindowFlags	m_windowFlag = 0;
};


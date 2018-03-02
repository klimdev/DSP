#pragma once

#include <imgui.h>
#include "ImGuiVariable.h"

#define MAX_WINDOW_NAME_LENGTH 100

class ImGuiBase : public ImGuiVarialbeUser
{
public:
	ImGuiBase() { }
	virtual ~ImGuiBase() { };

	virtual void BeginDraw() = 0;
	virtual void InnerDraw() = 0;
	virtual void EndDraw() = 0;

protected:
	char m_windowName[MAX_WINDOW_NAME_LENGTH] = {0};
};

//window
	//childs window

#pragma once

#include <imgui.h>

class ImGuiBase
{
public:
	ImGuiBase() { }
	virtual ~ImGuiBase() { };

	virtual void BeginDraw() = 0;
	virtual void InnerDraw() = 0;
	virtual void EndDraw() = 0;
};

//window
	//childs window

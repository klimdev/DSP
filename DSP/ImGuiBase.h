#pragma once

#include <imgui.h>
#include "ImGuiVariable.h"

#define MAX_WINDOW_NAME_LENGTH 128

class ImGuiBase : public ImGuiVarialbeUser
{
public:
	ImGuiBase() { }
	virtual ~ImGuiBase() { };

	virtual void BeginDraw() = 0;
	virtual void InnerDraw() = 0;
	virtual void EndDraw() = 0;

	virtual char* GetNameWithId(std::string name, int64_t id);
	virtual char* GetNameWithAlias(std::string name, std::string alias);
	virtual char* GetNamePerInstance(std::string name);
	virtual char* GetNamePerClass(std::string name);

protected:
	char m_windowName[MAX_WINDOW_NAME_LENGTH] = {0};
};

//window
	//childs window

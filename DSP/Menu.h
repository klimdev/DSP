#pragma once
#include "ImGuiBase.h"
class MainMenu :
	public ImGuiBase
{
public:
	MainMenu();
	virtual ~MainMenu();

	// Inherited via ImGuiBase
	virtual void BeginDraw() override;
	virtual void InnerDraw() override;
	virtual void EndDraw() override;

	bool menuOpened;
};


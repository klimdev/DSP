#pragma once
#include "ImGuiBase.h"
class EquationComponent :
	public ImGuiBase
{
public:
	EquationComponent();
	virtual ~EquationComponent();

	// Inherited via ImGuiBase
	virtual void BeginDraw() override;
	virtual void InnerDraw() override;
	virtual void EndDraw() override;
};


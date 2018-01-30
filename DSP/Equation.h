#pragma once
#include "ImGuiBase.h"

//template type +-*/ 
//		   lhs
//         rhs
class Equation :
	public ImGuiBase
{
public:
	Equation();
	~Equation();

	// Inherited via ImGuiBase
	virtual void BeginDraw() override;
	virtual void InnerDraw() override;
	virtual void EndDraw() override;

	//tempate get <arg1,arg2 ....>
};


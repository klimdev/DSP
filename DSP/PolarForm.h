#pragma once

#include <complex>
#include "ImGuiBase.h"

// cos
// sin

class PolarForm : public ImGuiBase
{
public:
	PolarForm();
	virtual ~PolarForm();

	double r; // radius
	double w; // angular speed

	//get realFun(cos class)
	//get imgFun

	//get (theta)
	//get real(theta)
	//get img(theta)

	//operator^ double
	//operator/ polarform
	//conj
	//length

	// Inherited via ImGuiBase
	virtual void BeginDraw() override;
	virtual void InnerDraw() override;
	virtual void EndDraw() override;

};

// Vector
//{
//	conj
//	operator* Vector
//}


// Vector operator* complex Vector
// Vector operator* double Vector


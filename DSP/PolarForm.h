#pragma once

#include <complex>
#include <vector>
#include "ImGuiBase.h"
#include "Angle.h"

// cos
// sin

class PolarForm : public ImGuiBase
{
public:
	PolarForm() { };
	PolarForm(double r, const Angle& radianW);
	PolarForm(double r, double radianW);
	virtual ~PolarForm();


	//get realFun(cos class)
	//get imgFun

	//get (theta)
	static std::complex<double> Get(double r, const Angle& theta);
	std::complex<double> Get(const Angle& offset);
	//get real(theta)
	static std::complex<double> GetReal(double r, const Angle& theta);
	double GetReal(const Angle& offset);
	//get img(theta)
	static std::complex<double> GetImag(double r, const Angle& theta);
	double GetImag(const Angle& offset);

	//operator^ double
	PolarForm operator^(double power) const;
	PolarForm& operator^=(double power);

	//operator/ polarform
	//conj
	//length

	// Inherited via ImGuiBase
	virtual void BeginDraw() override;
	virtual void InnerDraw() override;
	virtual void EndDraw() override;

protected:
	double r = 1; // radius
	double w = 1; // angular speed

	bool m_windowMode = false;
	bool m_windowOpened = false;


};

// Vector
//{
//	conj
//	operator* Vector
//}


// Vector operator* complex Vector
// Vector operator* double Vector


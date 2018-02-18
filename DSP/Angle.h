#pragma once
#ifndef __K_ANGLE_H
#define __K_ANGLE_H

#define PI 3.1415926f

struct Angle
{
public:
	Angle(bool isRadian, float angle) : m_angle(angle), m_isRadian(isRadian) {	}
	float Radian() const { return m_isRadian ? m_angle : m_angle * PI / 180.0f; }
	float Degree() const { return m_isRadian ? m_angle * 180.0f / PI : m_angle; }
private:
	float m_angle;
	bool  m_isRadian;
};

inline Angle FromRadian(float RadianAngle) { return Angle(true, RadianAngle); }
inline Angle FromDegree(float DegreeAngle) { return Angle(false, DegreeAngle); }

#endif
/* Start Header ------------------------------------------------------- 
Copyright (C) 2013 DigiPen Institute of Technology. 
Reproduction or disclosure of this file or its contents without the prior written 
consent of DigiPen Institute of Technology is prohibited. 
File Name: Vector3.h
Purpose: Vector3 class
Language: C++ / Microsoft cl compiler(visual studio)
Platform: Microsoft (R) C/C++ Optimizing Compiler Version 17.00.60610.1 for x86 /
          Intel(R) Core(TM) i5-3210M CPU/ Windows 8 64bit
Project: kikyeong.lim_CS300_1
Author: KiKyeong Lim / kikyeong.lim / 180010713
End Header --------------------------------------------------------*/ 

/******************************************************************************/
/*!
\file   Vector3.h
\author KiKyeong Lim
\par    Project : Evolution Striker - Cataclysm
\par    email: dlaking\@naver.com
\par    GAM200,250  
\copyright All content ¨Ï2012-2013 DigiPen(USA) Corporation, all right reserved.
*/
/******************************************************************************/

#pragma once
#pragma warning(disable:4201)

#ifndef __K_VECTOR2_H
#define __K_VECTOR2_H

/******************************************************************************/
/*!
  \struct Vector2
  \brief  
    Class of Vector2

    Operations include:
    - default constructor 
    - Vector2( float X, float Y, float Z = 0.0f)
    - Vector2( const Vector2& v ) 
  - Vector2( const Matrix3& v ) conversion operator
    - operator+ for float ,Vector2
    - operator- for float ,Vector2
    - operator* for float
    - operator/ for float
    - operator+= for float ,Vector2
    - operator-= for float ,Vector2
    - operator* for Vector2 : DotProduct
    - operator/ for Vector2 : CrossProduct
    - operator/= for Vector2 : CrossProduct
    - Nomalize
    - Length
    - LengthSquare
    - Normal
    - Distance
    - DistanceSquare
    - ToD3D
    - GetAngle
    - SetAngle

  \bug  


*/
/******************************************************************************/
struct Vector2 
{
  union
  {
    struct
    {
      float x,y;
    };

    struct
    {
      float r,w;
    };

    float v2[2];

  };
  Vector2( void );
  Vector2( float X, float Y);
  Vector2( const Vector2& v );
  Vector2( const float v[2]);
 

  //asignment opperator
  Vector2& operator= (const Vector2& rhs);

  Vector2& operator() (float X, float Y, float Z = 0.0f);

  //do calculation about rhs*(1,1,0) vector
  const Vector2 operator+ (float rhs) const;
  const Vector2 operator- (float rhs) const;
  Vector2& operator+= (float rhs);
  Vector2& operator-= (float rhs);

  const Vector2 operator* (float rhs) const;
  const Vector2 operator/ (float rhs) const;
  Vector2& operator*= (float rhs);
  Vector2& operator/= (float rhs);

  //do calculation about other Vector2
  const Vector2 operator+ (const Vector2& rhs) const;
  const Vector2 operator- (const Vector2& rhs) const;
  Vector2& operator+= (const Vector2& rhs);
  Vector2& operator-= (const Vector2& rhs);

  float operator* (const Vector2& rhs) const;//dot product
  float operator/ (const Vector2& rhs) const;//cross product

  Vector2& Normalize(void);

  float Length(void) const;
  float LengthSquare(void) const;
  Vector2 Normal(bool m90/*minius 90 degree roation else 90 degree rotation*/ = false) const;
  float Distance(const Vector2& rhs) const;
  float DistanceSquare(const Vector2& rhs) const;
  float Cross(const Vector2& rhs) const;

#ifdef GV_DX
  const D3DXVector2 ToD3D(void) const;
#endif
#ifdef GV_GL
  void ToGL(GLfloat in[3]) const;
#endif

  float GetAngle(void) const;
  Vector2& SetAngle(float angle);

};

const Vector2 operator+ (float lhs,const Vector2& rhs);
const Vector2 operator- (float lhs,const Vector2& rhs);
const Vector2 operator* (float lhs,const Vector2& rhs);
const Vector2 operator/ (float lhs,const Vector2& rhs);

#endif
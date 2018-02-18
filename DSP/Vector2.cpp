/* Start Header ------------------------------------------------------- 
Copyright (C) 2013 DigiPen Institute of Technology. 
Reproduction or disclosure of this file or its contents without the prior written 
consent of DigiPen Institute of Technology is prohibited. 
File Name: Vector2.cpp
Purpose: Vector2 class
Language: C++ / Microsoft cl compiler(visual studio)
Platform: Microsoft (R) C/C++ Optimizing Compiler Version 17.00.60610.1 for x86 /
          Intel(R) Core(TM) i5-3210M CPU/ Windows 8 64bit
Project: kikyeong.lim_CS300_1
Author: KiKyeong Lim / kikyeong.lim / 180010713
End Header --------------------------------------------------------*/ 
/******************************************************************************/
/*!
\file   Vector2.cpp
\author KiKyeong Lim
\par    Project : Evolution Striker - Cataclysm
\par    email: dlaking\@naver.com
\par    GAM200,250  
\copyright All content ¨Ï2012-2013 DigiPen(USA) Corporation, all right reserved.
*/
/******************************************************************************/

#include "Trigonometric.h"
#include "Vector2.h"
#include <cmath>

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Default constructor
*/
/******************************************************************************/
Vector2::Vector2( void ) : x(0.0f) , y(0.0f) {}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Constructor take 3 float
  \param X
  \param Y
  \param Z
    default value is 0
*/
/******************************************************************************/
Vector2::Vector2( float X, float Y ) : x(X),y(Y) {}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Constructor take vector
  \param v
*/
/******************************************************************************/
Vector2::Vector2( const Vector2& v ) : x(v.x),y(v.y) {}

Vector2::Vector2( const float v[2]) : x(v[0]) , y(v[1]) {}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    assignment operator
  \param rhs

  \return
    Vector2& - return itself
*/
/******************************************************************************/
Vector2& Vector2::operator= (const Vector2& rhs)
{
  if( this != &rhs )
  {
    x = rhs.x;
    y = rhs.y;
  }
    return *this;
}


/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    operator() to assignemnt from 3 float
  \param X
  \param Y
  \param Z

  \return
    Vector2& - return itself
*/
/******************************************************************************/
Vector2& Vector2::operator() (float X, float Y, float Z)
{
  x = X;
  y = Y;
  return *this;
}


/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector + float(*UnitVector(1,1))
  \param rhs

  \return
    const Vector2 - result vector
*/
/******************************************************************************/
const Vector2 Vector2::operator+ (float rhs) const
{
    Vector2 newOne( this->x + rhs , this->y + rhs );
    return newOne;
}


/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector - float(*UnitVector(1,1))
  \param rhs
    
  \return
    const Vector2 - result vector
*/
/******************************************************************************/
const Vector2 Vector2::operator- (float rhs) const
{
    Vector2 newOne( this->x - rhs , this->y - rhs );
    return newOne;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector * float
  \param rhs
    
  \return
    const Vector2 - result vector  
*/
/******************************************************************************/
const Vector2 Vector2::operator* (float rhs) const
{
    Vector2 newOne( this->x * rhs , this->y * rhs );
    return newOne;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector / float
  \param rhs
    
  \return
    const Vector2 - result vector
*/
/******************************************************************************/
const Vector2 Vector2::operator/ (float rhs) const
{
    //handle devided by 0 -> throw error
    if( rhs < EPSILON && rhs >  -EPSILON ) 
    { 
      //throw(std::string("Vector2 :: Devided by 0"));
    }
    else 
    { 
        Vector2 newOne( this->x / rhs , this->y / rhs ); 
        return newOne; 
    }
}


/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector = Vector + float
  \param rhs
    
  \return
    Vector2& - return itself
*/
/******************************************************************************/
Vector2& Vector2::operator+= (float rhs)
{
    *this = *this + rhs;
    return *this;

}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector = Vector - float
  \param rhs
    
  \return
    Vector2& - return itself
*/
/******************************************************************************/
Vector2& Vector2::operator-= (float rhs)
{
    *this = *this - rhs;
    return *this;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector = Vector*float
  \param rhs
    
  \return
    Vector2& - return itself
*/
/******************************************************************************/
Vector2& Vector2::operator*= (float rhs)
{
    *this = *this * rhs;
    return *this;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector = Vector / float
  \param rhs
    
  \return
    Vector2& - return itself
*/
/******************************************************************************/
Vector2& Vector2::operator/= (float rhs)
{
    *this = *this / rhs;
    return *this;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector + Vector
  \param rhs
    
  \return
    const Vector2 - result vector
*/
/******************************************************************************/
const Vector2 Vector2::operator+ (const Vector2& rhs) const
{
    Vector2 newOne( this->x + rhs.x, this->y + rhs.y );
    return newOne;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector - Vector
  \param rhs
    
  \return
    const Vector2 - result vector
*/
/******************************************************************************/
const Vector2 Vector2::operator- (const Vector2& rhs) const
{
    Vector2 newOne( this->x - rhs.x, this->y - rhs.y );
    return newOne;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector1 = Vector1 + Vector2
  \param rhs
    
  \return
    Vector2& - return itself
*/
/******************************************************************************/
Vector2& Vector2::operator+= (const Vector2& rhs)
{
    *this = *this + rhs;
    return *this;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Vector1 = Vector1 - Vector2
  \param rhs
    
  \return
    Vector2& - return itself
*/
/******************************************************************************/
Vector2& Vector2::operator-= (const Vector2& rhs)
{
    *this = *this - rhs;
    return *this;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    DotProduct(*)
  \param rhs
    
  \return
    float - dotProduct
*/
/******************************************************************************/
float Vector2::operator* (const Vector2& rhs) const
{
    float dotProduct = this->x * rhs.x + this->y * rhs.y;
    return dotProduct;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    CrossProduct(/)
  \param rhs
    
  \return
    float - result length
*/
/******************************************************************************/
float Vector2::operator/ (const Vector2& rhs) const
{
    return this->x * rhs.y - this->y * rhs.x;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Make vector as normal
  \return
    Vector2& - return itself
*/
/******************************************************************************/
Vector2& Vector2::Normalize(void)
{
    *this /= this->Length();
    return *this;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Calculate Legnth
  \return
    float - Length of vector
*/
/******************************************************************************/
float Vector2::Length(void) const
{
    return sqrt(*this * *this);
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    calculate Length Square
  \return
    float - Length square of vector
*/
/******************************************************************************/
float Vector2::LengthSquare(void) const
{
    return *this * *this;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Calculate normal of vector
  \return
    Vector2 - result vector
*/
/******************************************************************************/
Vector2 Vector2::Normal(bool m90) const
{
	if (m90)
	{
		Vector2 newOne(-(this->y), this->x);
		return newOne;
	}
	else
	{
    Vector2 newOne(this->y,-(this->x));
    return newOne;
	}
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    distance from this to taken vector
  \param rhs
    
  \return
    float - distance from this to taken vector
*/
/******************************************************************************/
float Vector2::Distance(const Vector2& rhs) const
{
    float distance = this->DistanceSquare(rhs);
    return sqrt(distance);
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    distance square from this to taken vector
  \param rhs
    
  \return
    float - DistanceSquare from this to taken vector
*/
/******************************************************************************/
float Vector2::DistanceSquare(const Vector2& rhs) const
{
    Vector2 newOne(*this);
    newOne -= rhs;
    return newOne*newOne;
}

float Vector2::Cross(const Vector2& rhs) const
{
  return v2[0] * rhs.v2[1] - v2[1] * rhs.v2[0];
}

#ifdef GV_DX
/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Convert myVector to D3DVector
  \return
    const D3DXVector2 - converted D3D vector
*/
/******************************************************************************/
const D3DXVector2 Vector2::ToD3D(void) const
{
    D3DXVector2 d3dVector(this->x,this->y,this->z);
    return d3dVector;
}
#endif

#ifdef GV_GL
void Vector2::ToGL(GLfloat in[3]) const
{
  memcpy(in,v2,3*sizeof(float));
}
#endif


/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    Calculate angle from vector's direction
    find 0~90 angle using symmetry and then calculate real rangle for direction
  \return
    float - angle
*/
/******************************************************************************/
float Vector2::GetAngle(void) const
{
  // index range[real range]
  // 0 ~ 90
  
  const int ORIGIN_ANGLE = 0;
  // over 180 angle is same as 360 - (angle in 0~180)
  const int ORIGIN_REVERSE_ANGLE = 360;

  //slide is one
  const float M_IS_ONE = 1.0f + EPSILON;
  //const tangent table which is pre-calculated by other code
  const float TANGENT[] = 
  {
    0.000000f,0.017455f,0.034921f,0.052408f,0.069927f,
    0.087489f,0.105104f,0.122785f,0.140541f,0.158384f,
    0.176327f,0.194380f,0.212557f,0.230868f,0.249328f,
    0.267949f,0.286745f,0.305731f,0.324920f,0.344328f,
    0.363970f,0.383864f,0.404026f,0.424475f,0.445229f,
    0.466308f,0.487732f,0.509525f,0.531709f,0.554309f,
    0.577350f,0.600860f,0.624869f,0.649407f,0.674508f,
    0.700207f,0.726542f,0.753554f,0.781285f,0.809784f,
    0.839099f,0.869286f,0.900404f,0.932515f,0.965688f,
    1.000000f,1.035530f,1.072368f,1.110612f,1.150368f,
    1.191753f,1.234897f,1.279941f,1.327044f,1.376381f,
    1.428147f,1.482560f,1.539864f,1.600334f,1.664279f,
    1.732050f,1.804047f,1.880725f,1.962609f,2.050303f,
    2.144506f,2.246035f,2.355851f,2.475085f,2.605087f,
    2.747475f,2.904208f,3.077681f,3.270849f,3.487411f,
    3.732047f,4.010776f,4.331470f,4.704623f,5.144546f,
    5.671272f,6.313739f,7.115354f,8.144325f,9.514335f,
    11.430009f,14.300598f,19.081015f,28.635975f,57.288834f,
    340282346638528860000000000000000000000.0f
    //Max float because sometimes it can not be caugth by 90degree check
  };

  //tangent value
  float tangent;
  //origin of angle, sign(upside = 1 / downside = -1), and angle in 0~180
  int originAngle,sign,angle;
  //check it is x Symmetry
  bool xSymmetry;

  //y < 0 -> tangent is - , 360 - (angle in 0~180)
  ( y < 0 )?( originAngle = ORIGIN_REVERSE_ANGLE , sign = -1 ):
            ( originAngle = ORIGIN_ANGLE , sign = 1 );
  
  //if x = 0 mean 90 degree or 270
  if( x >= -EPSILON && x <= EPSILON )
    return float(originAngle + sign*90);

  //if y = 0 mean 0 or 180 degree
  if( y >= -EPSILON && y <= EPSILON )
    return float(( x > 0 )?(0):(180));

  //calculate tangent
  tangent = sign*y/x;
  //if tangent is minus -> 91~179 use xSymmetry
  ( tangent < 0 )?( tangent *= -1, xSymmetry = true ):
                  ( xSymmetry = false );    


  //devide tangent value two part 0~44,45~90
  if(tangent < M_IS_ONE )
    angle = 0;
  else
    angle = 45;

  //until TANGENT[angle] be larger than tangent value
  //that mean angle find correct position in table
  while( tangent > TANGENT[angle] ){ ++angle; }


  //if calculated angle is 91~179
  if( xSymmetry )
  {
    //180 - angle -> real angle with out unside-down
    //and combine with origine and sign
    angle = originAngle + sign*(180 - angle);
  }
  //if calculated angle is 0~90
  else
  {
    //combine with origine and sign
    angle = originAngle + sign*(angle);
  }

  //return angle as float
  return float(angle);

}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    from angle set direction of vector

  \parma angle
    angle of direction

  \return
    Vector2& - return *this
*/
/******************************************************************************/
Vector2& Vector2::SetAngle(float angle)
{
  x = Cos(angle);
  y = Sin(angle);
  return *this;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    float(*UnitVector(1,1)) + Vector
  \param lhs
  \param rhs
    
  \return
    const Vector2 - result vector
*/
/******************************************************************************/
const Vector2 operator+ (float lhs,const Vector2& rhs)
{
    return rhs + lhs;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    float(*UnitVector(1,1)) - Vector
  \param lhs
  \param rhs
    
  \return
    const Vector2 - result vector
*/
/******************************************************************************/
const Vector2 operator- (float lhs,const Vector2& rhs)
{
    return Vector2(lhs,lhs) - rhs;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    float * Vector
  \param lhs
  \param rhs
    
  \return
    const Vector2 - result vector
*/
/******************************************************************************/
const Vector2 operator* (float lhs,const Vector2& rhs)
{
    return rhs * lhs;
}

/******************************************************************************/
/*!
  \author
    KiKyeong Lim

  \brief
    float / Vector
  \param lhs
  \param rhs
    
  \return
    const Vector2 - result vector
*/
/******************************************************************************/
const Vector2 operator/ (float lhs,const Vector2& rhs)
{
    return rhs / lhs;
}

#pragma once
#include "Vector2"
#include "Vector4"


// YOUR INCLUDES HERE
//#include "Vector2.h" etc
//#include "Matrix4.h" etc

// TYPEDEFS IF NEEDED
// typedef glm::vec2 Vector2; etc
// typedef glm::mat4 Matrix4; etc

// IF YOU GAVE YOUR CLASSES STREAM OPERATORS YOU CAN UNCOMMENT THIS
//#define NO_DEFAULT_STREAM_OPERATOR

// tests the following:

// Vector2: dot(V2), V2 + V2, V2 - V2, V2 x float, float x V2, magnitude(), normalise(), [], (float*)
// Vector3: dot(V3), cross(V3), V3 + V3, V3 - V3, V3 x float, float x V3, magnitude(), normalise(), [], (float*)
// Vector4: dot(V4), cross(V4), V4 + V4, V4 - V4, V4 x float, float x V4, magnitude(), normalise(), [], (float*)
// Matrix2: setRotate(float), M2 x V2, [], (float*)
// Matrix3: setRotateX(float), setRotateY(float), setRotateZ(float), M3 x V3, [], (float*)
// Matrix4: setRotateX(float), setRotateY(float), setRotateZ(float), M4 x V4, [], (float*)

// returns true if all tests successful
bool runUnitTests();

Vector4::Vector4()
{
	Xpos, Ypos, Zpos, Wpos = 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	Xpos = x;
	Ypos = y;
	Zpos = z;
	Wpos = w;
}

float Vector4::getX()
{
	return Xpos;
}

float Vector4::getY()
{
	return Ypos;
}

float Vector4::getZ()
{
	return Zpos;
}

float Vector4::getW()
{
	return Wpos;
}

Vector4 Vector4::operator+(Vector4 & rhs)
{
	return Vector4(Xpos + rhs.Xpos,
		Ypos + rhs.Ypos,
		Zpos + rhs.Zpos,
		Wpos + rhs.Wpos);
}

Vector4 Vector4::operator-(Vector4 & rhs)
{
	return Vector4(Xpos - rhs.Xpos,
		Ypos - rhs.Ypos,
		Zpos - rhs.Zpos,
		Wpos - rhs.Wpos);
}

Vector4 Vector4::operator*(float & rhs)
{
	Xpos *= rhs;
	Ypos *= rhs;
	Zpos *= rhs;
	Wpos *= rhs;

	return *this;
}

bool Vector4::operator==(Vector4 & rhs)
{
	return (Xpos == rhs.Xpos && Ypos == rhs.Ypos &&
		Zpos == rhs.Zpos &&
		Wpos == rhs.Wpos);
}

bool Vector4::operator!=(Vector4 & rhs)
{
	return (Xpos != rhs.Xpos ||
		Ypos != rhs.Ypos ||
		Zpos != rhs.Zpos ||
		Wpos != rhs.Wpos);
}

float Vector4::Magnitude()
{
	return sqrt((Xpos * Xpos) +
		(Ypos * Ypos) +
		(Zpos * Zpos) +
		(Wpos * Wpos));

}

Vector4 Vector4::Normalise()
{
	float mag = Magnitude();
	Xpos /= mag;
	Ypos /= mag;

	return *this;
}

Vector4 Vector4::Cross(Vector4 position)
{
	return Vector4(Ypos * position.Zpos - Zpos * position.Ypos,
		Zpos * position.Xpos - Xpos * position.Zpos,
		Xpos * position.Ypos - Ypos * position.Xpos,
		0.0);
}

float Vector4::Distance(Vector4 position)
{
	return (*this - position).Magnitude();
}

float Vector4::Dot(Vector4 position)
{
	return (Xpos * position.Xpos +
		Ypos * position.Ypos +
		Zpos * position.Zpos +
		Wpos * position.Wpos);

}

float & Vector4::operator[](int arr)
{
	// TODO: insert return statement here
	float zero = 0.0;

	switch (arr)
	{
	case 0:
		return Xpos;
	case 1:
		return Ypos;
	case 2:
		return Zpos;
	case 3:
		return Wpos;
	default:
		return zero;
	}
}

Vector4::operator float*()
{
	float temp[4] = { Xpos, Ypos, Zpos, Wpos };

	return &temp[0];
}
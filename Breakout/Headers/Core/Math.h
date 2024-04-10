#pragma once

namespace Breakout 
{
	//Adapted from https://jacco.ompf2.com/2021/08/27/3d-game-programming-in-c-part-2-the-template/
	class vec2
	{
	public:
		struct { float x, y; };
		vec2() {}
		vec2(float value) : x(value), y(value) {}
		vec2(float valueX, float valueY) : x(valueX), y(valueY) {}

		vec2 operator - () const { return vec2(-x, -y); }
		vec2 operator + (const vec2& addOperand) const { return vec2(x + addOperand.x, y + addOperand.y); }
		vec2 operator - (const vec2& operand) const { return vec2(x - operand.x, y - operand.y); }
		vec2 operator * (const vec2& operand) const { return vec2(x * operand.x, y * operand.y); }
		vec2 operator * (float operand) const { return vec2(x * operand, y * operand); }
		void operator -= (const vec2& a) { x -= a.x; y -= a.y; }
		void operator += (const vec2& a) { x += a.x; y += a.y; }
		void operator *= (const vec2& a) { x *= a.x; y *= a.y; }
		void operator *= (float a) { x *= a; y *= a; }

		float length() { return sqrtf(x * x + y * y); }
		vec2 normalized() { float r = 1.0f / length(); return vec2(x * r, y * r); }
		void normalize() { float r = 1.0f / length(); x *= r; y *= r; }
		float dot(const vec2& operand) const { return x * operand.x + y * operand.y; }
	};

}
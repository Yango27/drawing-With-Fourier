#pragma once
#include <GLFW/glfw3.h>
#include <cmath>

class Arrow
{
public:
	Arrow(float cx, float cy, float radius, float headSize) : m_cx(cx), m_cy(cy), m_radius(radius), m_headSize(headSize) {}
	void drawArrow();
	void drawCircle();
private:
	float m_cx;
	float m_cy;
	float m_radius;
	float m_headSize;
	float m_velocity;
	float m_phase;
};
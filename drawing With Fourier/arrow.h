#pragma once
#include <GLFW/glfw3.h>
#include <cmath>
#include <vector>

const double M_PI = 3.14159265358979323846;
class Arrow
{
public:
	Arrow(double cx, double cy, double radius, double angularV, double phase) : m_cx(cx), m_cy(cy), m_radius(radius), m_angularV(angularV), m_phase(phase) {
		 m_x = m_cx + m_radius * cos(m_phase);
		m_y = m_cy + m_radius * sin(m_phase);
	}
	void drawArrow();
	void drawCircle();
	void drawPath();
	void phasorSpinning(double t);
	void setCx(double cx) { m_cx = cx; }
	void setCy(double cy) { m_cy = cy; }
	double getX() { return m_x; }
	double getY() { return m_y; }
	double getRadius() { return m_radius; }
	void setRadius(double radius) { m_radius = radius; }
private:
	double m_cx;
	double m_cy;
	double m_x;
	double m_y;
	double m_radius;
	double m_angularV;
	double m_phase;
	std::vector<double> m_pathX;
	std::vector<double> m_pathY;
};
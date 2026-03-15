#include "arrow.h"

void Arrow::drawArrow()
{
    double x = m_cx + m_radius * cos(m_phase);
    double y = m_cy + m_radius * sin(m_phase);
    double dx = cos(m_phase);
    double dy = sin(m_phase);
    double px = -dy;
    double py = dx;

    m_x = x;
    m_y = y;

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(m_cx, m_cy);
    glVertex2f(x, y);
    glEnd();
}

void Arrow::drawCircle()
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 50; i++) {
        float theta = 2.0f * M_PI * float(i) / float(50);
        float x = m_radius * cosf(theta);
        float y = m_radius * sinf(theta);
        glVertex2f(x + m_cx, y + m_cy);
    }
    glEnd();
}

void Arrow::drawPath()
{
    double x = m_cx + m_radius * cos(m_phase);
    double y = m_cy + m_radius * sin(m_phase);
    if (m_pathX.size() >= 500)
    {
        m_pathX.erase(m_pathX.begin());
        m_pathY.erase(m_pathY.begin());
    }
    m_pathX.push_back(x);
    m_pathY.push_back(y);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < m_pathX.size(); i++)
    {
        glColor4f(1.0f, 1.0f, 1.0f, i / float(m_pathX.size()));
        glVertex2f(m_pathX[i], m_pathY[i]);
    }
    glEnd();
}

void Arrow::phasorSpinning(double t)
{
    m_phase += m_angularV * t;
}


#include "arrow.h"

void Arrow::drawArrow()
{
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(m_cx, m_cy);
    glVertex2f(m_cx + m_radius, m_cy);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(m_cx + m_radius, m_cy);
    glVertex2f(m_cx + m_radius - m_headSize, m_cy + m_headSize);
    glVertex2f(m_cx + m_radius - m_headSize, m_cy - m_headSize);
    glEnd();
}

void Arrow::drawCircle()
{
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 50; i++) {
        float angle = 2.0f * 3.1415926f * i / 50;
        float x = m_cx + m_radius * cos(angle);
        float y = m_cy + m_radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}


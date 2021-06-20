#include "GL/glew.h"
#include "Elems/Line_DDA.h"

void Line_DDA::draw() {
    float m = (float)(p2.y - p1.y) / (p2.x - p1.x);
    glColor3f(LINE_DDA_COLOR);
    glBegin(GL_POINTS);
    if (m <= 1 && m >= -1) {
        float y = (float)p1.y;
        int step = p1.x > p2.x ? -1 : 1;
        if (step == -1) m = -m;
        for (int x = p1.x; x != p2.x; x += step) {
            glVertex2i(x, (int)(y + 0.5));
            y += m;
        }
    }
    else {
        m = 1 / m;
        float x = (float)p1.x;
        int step = p1.y > p2.y ? -1 : 1;
        if (step == -1) m = -m;
        for (int y = p1.y; y != p2.y; y += step) {
            glVertex2i((int)(x + 0.5), y);
            x += m;
        }
    }
    glEnd();
}
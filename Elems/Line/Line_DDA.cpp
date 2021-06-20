#include "GL/glew.h"
#include "Line_DDA.h"

void Line_DDA::draw() {
    // 测试样例
    glBegin(GL_LINES);
    glColor3f(LINE_DDA_COLOR);
    glVertex2d(p1.x, p1.y);
    glVertex2d(p2.x, p2.y);
    glEnd();
}
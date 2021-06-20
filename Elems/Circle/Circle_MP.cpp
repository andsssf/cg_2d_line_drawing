#include "Elems/Circle_MP.h"
#include <GL/glew.h>

// 八对称性画出八个点
inline void Circle_MP::drawOtherPoints(Point p) {
	glVertex2d(p.x + center.x, p.y + center.y);
	glVertex2d(p.y + center.x, p.x + center.y);
	glVertex2d(-p.y + center.x, p.x + center.y);
	glVertex2d(-p.x + center.x, p.y + center.y);
	glVertex2d(p.y + center.x, -p.x + center.y);
	glVertex2d(p.x + center.x, -p.y + center.y);
	glVertex2d(-p.x + center.x, -p.y + center.y);
	glVertex2d(-p.y + center.x, -p.x + center.y);
}

void Circle_MP::draw() {
	glColor3f(CIRCLE_MP_COLOR);
	glBegin(GL_POINTS);
	int x = 0, y = radius, d = 5 - 4 * radius;
	drawOtherPoints(Point(x, y));
	while (y > x) {
		if (d <= 0) {
			d += 8 * x + 12;
		}
		else {
			d += 8 * (x - y) + 20;
			y--;
		}
		x++;
		drawOtherPoints(Point(x, y));
	}
	glEnd();
}

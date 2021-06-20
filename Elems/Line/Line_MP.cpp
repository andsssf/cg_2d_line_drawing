#include "GL/glew.h"
#include "Elems/Line_MP.h"
#include "Math.h"

void Line_MP::draw() {
    float m = (float)(p2.y - p1.y) / (p2.x - p1.x);
	glColor3f(LINE_MP_COLOR);
	glBegin(GL_POINTS);
	if (fabs(m) <= 1.0) {
		int x = p1.x < p2.x ? p1.x : p2.x;
		int y = x == p1.x ? p1.y : p2.y;
		if (m >= 0) {
			int d = abs(p2.x - p1.x) - 2 * abs(p2.y - p1.y);
			int incrE = -2 * abs(p2.y - p1.y);
			int incrNE = 2 * (abs(p2.x - p1.x) - abs(p2.y - p1.y));
			glVertex2i(x, y);
			int maxX = p1.x > p2.x ? p1.x : p2.x;
			while (x < maxX) {
				if (d > 0) {
					d += incrE;
				}
				else {
					d += incrNE;
					y++;
				}
				x++;
				glVertex2i(x, y);
			}
		}
		else {
			int d = -abs(p2.x - p1.x) + 2 * abs(p2.y - p1.y);
			int incrE = 2 * abs(p2.y - p1.y);
			int incrNE = -2 * (abs(p2.x - p1.x) - abs(p2.y - p1.y));
			glVertex2i(x, y);
			int maxX = p1.x > p2.x ? p1.x : p2.x;
			while (x < maxX) {
				if (d > 0) {
					d += incrNE;
					y--;
				}
				else {
					d += incrE;
				}
				x++;
				glVertex2i(x, y);
			}
		}
	}
	else {
		m = 1 / m;
		int y = p1.y < p2.y ? p1.y : p2.y;
		int x = y == p1.y ? p1.x : p2.x;
		if (m >= 0) {
			int d = abs(p2.y - p1.y) - 2 * abs(p2.x - p1.x);
			int incrE = -2 * abs(p2.x - p1.x);
			int incrNE = 2 * (abs(p2.y - p1.y) - abs(p2.x - p1.x));
			glVertex2i(x, y);
			int maxY = p1.y > p2.y ? p1.y : p2.y;
			while (y < maxY) {
				if (d > 0) {
					d += incrE;
				}
				else {
					d += incrNE;
					x++;
				}
				y++;
				glVertex2i(x, y);
			}
		}
		else {
			int d = -abs(p2.y - p1.y) + 2 * abs(p2.x - p1.x);
			int incrE = 2 * abs(p2.x - p1.x);
			int incrNE = -2 * (abs(p2.y - p1.y) - abs(p2.x - p1.x));
			glVertex2i(x, y);
			int maxY = p1.y > p2.y ? p1.y : p2.y;
			while (y < maxY) {
				if (d > 0) {
					d += incrNE;
					x--;
				}
				else {
					d += incrE;
				}
				y++;
				glVertex2i(x, y);
			}
		}
	}
	glEnd();
}
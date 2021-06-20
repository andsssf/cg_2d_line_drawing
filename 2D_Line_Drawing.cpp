#include "GL/glew.h"
#include "GL/freeglut.h"
#include "WM/WindowManager.h"
#include "Elems/Line_DDA.h"
#include "Elems/Line_MP.h"
#include "Elems/Circle_MP.h"
#include<iostream>

#define DDA_LINE_MOD 0x101
#define MP_LINE_MOD 0x102
#define MP_CIRCLE_MOD 0x201
#define REDO_COMMAND 0x001
#define CLEAR_COMMAND 0x002
 
using namespace std;
 
void render();
void framebufferSizeCallback(int width, int height);
void cursePoscallback(int x, int y);
void mouseButtonCallback(int button, int state, int x, int y);
void menuCallback(int menuItemNum);

WindowManager wm;
int WIDTH = 800, HEIGHT = 600;
bool clickStatus = false;
int firstClickPosX, firstClickPosY;
int DRAW_MOD = DDA_LINE_MOD;	//默认DDA算法画直线

int main(int argc,char** argv)
{
	//初始化
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("CG 2D Line Drawing");
	
	gluOrtho2D(0, WIDTH, 0, HEIGHT);
    
	wm.init();
	
	glutDisplayFunc(render);

	glutReshapeFunc(framebufferSizeCallback);
    glutMouseFunc(mouseButtonCallback);
    glutCreateMenu(menuCallback);
    
    //添加菜单
    glutAddMenuEntry("draw line (DDA)", DDA_LINE_MOD);
    glutAddMenuEntry("draw line (Mid Point)", MP_LINE_MOD);
    glutAddMenuEntry("draw circle (Mid Point)", MP_CIRCLE_MOD);
    glutAddMenuEntry("redo", REDO_COMMAND);
    glutAddMenuEntry("clear all", CLEAR_COMMAND);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
    return 0;
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	wm.drawAll();
	glFlush();
}

void framebufferSizeCallback(int width, int height) {
    WIDTH = width;
	HEIGHT = height;
	
	glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)width, 0.0, (GLdouble)height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouseButtonCallback(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
        switch (button) {
        case GLUT_LEFT_BUTTON:
            if (!clickStatus) { 
                firstClickPosX = x;
                firstClickPosY = HEIGHT - y;
                clickStatus = true;
            }
            else {
                switch (DRAW_MOD) {
					case DDA_LINE_MOD:
						wm.pushElem(new Line_DDA(Point(firstClickPosX, firstClickPosY), Point(x, HEIGHT - y)));
						break;
					case MP_LINE_MOD:
						wm.pushElem(new Line_MP(Point(firstClickPosX, firstClickPosY), Point(x, HEIGHT - y)));
						break;
					case MP_CIRCLE_MOD:
						Point center(firstClickPosX, firstClickPosY);
						Point secend(x, HEIGHT - y);
						double radius = sqrt(pow(center.x - secend.x, 2) + pow(center.y - secend.y, 2));
						wm.pushElem(new Circle_MP(center, radius));
						break;
				}
                clickStatus = false;
                glutPostRedisplay();
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            wm.popElem();
			glutPostRedisplay();
            break;
        }
    }
}

void menuCallback(int menuItemNum) {
	switch (menuItemNum) {
		case DDA_LINE_MOD:
			DRAW_MOD = DDA_LINE_MOD;
			break;
		case MP_LINE_MOD:
			DRAW_MOD = MP_LINE_MOD;
			break;
		case MP_CIRCLE_MOD:
			DRAW_MOD = MP_CIRCLE_MOD;
			break;
		case REDO_COMMAND:
			wm.popElem();
			glutPostRedisplay();
			break;
		case CLEAR_COMMAND:
			wm.clearAll();
			glutPostRedisplay();
			break;
    }
}
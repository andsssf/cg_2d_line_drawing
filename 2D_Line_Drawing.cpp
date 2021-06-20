#include "GL/glew.h"
#include "GL/freeglut.h"
#include "WM/WindowManager.h"
#include<iostream>
 
using namespace std;

WindowManager wm;
 
void render()
{
	glClearColor(0, 1, 0, 0);
	wm.drawAll();
	glFlush();
	cout << "render" << endl;
}

int main(int argc,char** argv)
{
	//初始化
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(800, 600);
	glutCreateWindow("CG 2D Line Drawing");
	
	gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(render);
    
	wm.init();

	glutMainLoop();
    return 0;
}
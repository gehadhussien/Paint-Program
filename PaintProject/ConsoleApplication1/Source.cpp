using namespace std;
#include<iostream>
#include <windows.h>
#include <gl/gl.h>
#include <GL/glut.h>  
//#include <gl/glut.h>
#include "gl/glut.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")


int ww = 600, wh = 400;
int first = 0;
int xi, yi, xf, yf;
//Function to draw line
void drawLine(int x1, int y1, int x2, int y2)
{
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	glFlush();
}

//to display background color and line color
void display()
{

	glColor3f(0.0f, 0.0f, 0.0f);
	glColor3f(0.7, 0.4, 0.0);
	glFlush();
}
//work on mouse click
void mouse(int btn, int state, int x, int y)
{
	//first = 1;
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		switch (first)
		{
		case 0:
			xi = x;
			yi = wh - y;
			first = 1;
			break;
		case 1:
			xf = x;
			yf = wh - y;
			drawLine(xi, yi, xf, yf);
			first = 0;
			break;
		}
	}
}


void myinit()
{
	//window coordinates width and hieght
	glViewport(0, 0, ww, wh);
	//projection defines object coordinates
	//modelview defines how object transformed like rotation
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	//load the matrix
	glLoadIdentity();
	//sets 2D view
	gluOrtho2D(0.0, ww, 0.0, wh);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutCreateWindow("Drawing Lines");
	glutDisplayFunc(display);
	myinit();
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

int wh = 500, ww = 500;
float size = 3;

void myInit()
{
	gluOrtho2D(0, wh, 0, ww);
}

void drawsq(int x, int y)
{
	y = wh - y;
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(x + size, y + size);
	glVertex2f(x - size, y + size);
	glVertex2f(x - size, y - size);
	glVertex2f(x + size, y - size);
	glEnd();
	glFlush();
}

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		drawsq(x, y);
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		exit(0);
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(wh, ww);
	glutCreateWindow("Square");
	glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	myInit();
	glutMainLoop();
}
#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

inline int Round(float a) { return (int)a + 0.5; }

void setpixel(int x, int y)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}

void lineDDA()
{
	int x0 = 5, y0 = 5, xend = 10, yend = 12, dx, dy, steps, k;
	dx = xend - x0;
	dy = yend - y0;
	float xincr, yincr, x = x0, y = y0;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xincr = dx / steps;
	yincr = dy / steps;
	setpixel(Round(x), Round(y));
	for (k = 0; k < steps; k++)
	{
		x += xincr;
		y += yincr;
	}
}



void myinit()
{
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DDA Line");
	myinit();
	glutDisplayFunc(lineDDA);
	glutMainLoop();
}

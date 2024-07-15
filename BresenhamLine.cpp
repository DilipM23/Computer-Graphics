#include<cmath>
#include<GL/glut.h>

void setPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void lineBresenham(int x0, int y0, int xend, int yend)
{
	int dx = fabs(xend - x0), dy = fabs(yend - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
	int x, y;
	if (x0 > xend)
	{
		x = xend;
		y = yend;
		xend = x0;
	}
	else
	{
		x = x0;
		y = y0;
	}
	setPixel(x, y);
	while (x < xend)
	{
		x++;
		if (p < 0)
			p += twoDy;
		else
		{
			y++;
			p += twoDyMinusDx;
		}
		setPixel(x, y);
	}
}

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	int x0 = 50, y0 = 100, xend = 200, yend = 100;
	lineBresenham(x0, y0, xend, yend);
	glFlush();
}

void init()
{
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Bresenham Line Drawing");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}

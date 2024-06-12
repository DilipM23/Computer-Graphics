#include<GL/glut.h>

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
	glPointSize(5);
	glBegin(GL_POINTS);
		glVertex2i(50,50);
		glColor3f(1, 0, 0);
		glVertex2i(20, 40);
	glEnd();
	glFlush();
}

void myinit()
{
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Points");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
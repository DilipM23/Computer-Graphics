#include<GL/glut.h>

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2i(20, 100);
	glVertex2i(50, 50);
	glColor3f(0, 1, 0);
	glVertex2i(100, 50);
	glVertex2i(150, 150);
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
	glutCreateWindow("Lines");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
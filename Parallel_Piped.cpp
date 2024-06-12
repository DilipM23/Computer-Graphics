#include<GL/glut.h>
#include<math.h>
void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	double angle;
	int i, j;
	for (i = 0; i <= 200; i+=5)
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(50 + i, 50 + i);
		glVertex2i(150 + i, 50 + i);
		glVertex2i(150 + i, 150 + i);
		glVertex2i(50 + i, 150 + i);
		glEnd();
	}
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
	glutCreateWindow("Parallel Piped");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
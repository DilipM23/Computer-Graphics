#include<stdlib.h>
#include<GL/glut.h>

float red = 1.0, green = 1.0, blue = 1.0, sizef = 0;

void init()
{
	gluOrtho2D(0, 500, 0, 500);
}

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red, green, blue);
	glBegin(GL_QUADS);
		glVertex2f(250 - sizef, 250 - sizef);
		glVertex2f(350 + sizef, 250 - sizef);
		glVertex2f(350 + sizef, 350 + sizef);
		glVertex2f(250 - sizef, 350 + sizef);
	glEnd();
	glFlush();
}

void d_menu(int op)
{
	if (op == 1)
		sizef += 5;
	else if (op == 2)
		sizef -= 5;
	else if (op == 3)
		sizef = 0;
	else if (op == 4)
		exit(0);
	glutPostRedisplay();
}
void keyboard(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 'i':
		sizef += 5;
		break;
	case 'd':
		sizef -= 5;
		break;
	case 'r':
		sizef = 0;
		break;
	case 'q':
		exit(0);
	}
	glutPostRedisplay();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Menu");
	glutDisplayFunc(display);
	init();
	glutDisplayFunc(display);
	glutCreateMenu(d_menu);
	glutAddMenuEntry("Increase", 1);
	glutAddMenuEntry("Decrease", 2);
	glutAddMenuEntry("Refresh", 3);
	glutAddMenuEntry("Quit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
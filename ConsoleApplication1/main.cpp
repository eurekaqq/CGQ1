#include <glut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3d(0, 0, 0);
	glRotatef(2, 0.5, 0, 0.5);
	glBegin(GL_TRIANGLES);
	glVertex2d(0.2, 0.15);
	glVertex2d(-0.2, 0.15);
	glVertex2d(0, -0.3);
	//glColor3d(1, 1, 1);
	glVertex2d(0, 0.3);
	glVertex2d(0.2, -0.15);
	glVertex2d(-0.2, -0.15);
	glEnd();
	glutSwapBuffers();
	//glFlush();
}

void init(void)
{
	glClearColor(0.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("test");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}
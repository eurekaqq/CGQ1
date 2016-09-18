#include <glut.h>
#include <iostream>

using namespace std;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3d(0, 0, 0);
	glRotatef(2, 0.5, 0, 0.5);
	glBegin(GL_TRIANGLES);
	glVertex2d(0.2, 0.15);
	glVertex2d(-0.2, 0.15);
	glVertex2d(0, -0.3);
	glVertex2d(0, 0.3);
	glVertex2d(0.2, -0.15);
	glVertex2d(-0.2, -0.15);
	glEnd();
	glutSwapBuffers();
}

void init(void)
{
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
}

void mouse(int button,int state,int x,int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN&&x<100&&y<100)
			cout << "left test" << endl;
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			cout << "right test" << endl;
		break;
	}
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		glTranslatef(0, 0.05, 0);
		break;
	case'a':
		glTranslatef(-0.05, 0, 0);
		break;
	case's':
		glTranslatef(0, -0.05, 0);
		break;
	case'd':
		glTranslatef(0.05, 0, 0);
		break;
	}
}

//void menu(void) {
//	int menu_main;
//
//	menu_main = glutCreateMenu(menu_main_func);
//}
//
//void menu_main_func(int value) {
//	switch (value) {
//	case 1:
//		cout << "main menu1"<<endl;
//		break;
//	case 2:
//		cout << "main menu 2" << endl;
//		break;
//	}
//}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow(argv[0]);
	init();
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}
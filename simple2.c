#include <GL/glut.h>
void display()
{
int x = -1.0;
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(2.0);
glBegin(GL_POINTS);
glColor3f(1.0, 1.0, 1.0);
glVertex2f(-0.5, -0.5);
glColor3f(1.0, 0.0, 0.0);
glVertex2f(-0.5, 0.5);
glColor3f(0.0, 0.0, 1.0);
glVertex2f(0.5, 0.5);
glColor3f(0.0, 1.0, 0.0);
glVertex2f(0.5, -0.5);
glEnd();
glFlush();
}
int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutCreateWindow("simple");
glutDisplayFunc(display);
glutMainLoop();
}

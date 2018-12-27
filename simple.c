#include <GL/glut.h>
void display()
{
int x = -1.0;
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
glVertex2f(x, -0.5);
glVertex2f(-0.5, 0.5);
glVertex2f(0.5, 0.5);
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

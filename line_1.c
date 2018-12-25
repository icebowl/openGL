// line_0.c   cwc
// 181225
//
// g++ line_0.c -lglut -lGL -o line0
#include "GL/freeglut.h"
#include "GL/gl.h"

void plot2Dpoint(int x,int y, float red, float green, float blue){

  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(200, 200);
  glEnd();

}

void drawPoints()
{
    int h,k,done;
    float red,green,blue;
    red = 0.5, blue = 0.25; green = 0.0;
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    for (h = 0; h < 401;h++){
      for (k = 0; k < 401; k++){
      plot2Dpoint(h,k,red,green, );
      glFlush();

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Draw Points");
    glutDisplayFunc(drawPoints);
    glutMainLoop();
    return 0;
}

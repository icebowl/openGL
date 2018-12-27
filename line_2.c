// line_0.c   cwc
// 181225
// g++ line_0.c -lglut -lGL -o line0
#include <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"

void plot2Dpoint(float x,float y, float red, float green, float blue){
  //void plot2Dpoint(float red, float green, float blue){

  glColor3f(1.0, 1.0, 0.0);
  glColor3f(red, green, blue);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glBegin(GL_TRIANGLES);
          glVertex3f(x, 0.7, 0);
          glVertex3f(0.7, 0.7, 0);
          glVertex3f(0, -1, 0);
  glEnd();
  glColor3f(0, 0, 1);

      glBegin(GL_LINES);
       glVertex2f(xf, yf);
       glVertex2f(xf+1, yf);
     glEnd();


  //printf("%d %d \n",x,y);
  //glFlush();
}

void drawPoints()
{
    int h,k,done;


    float red = 1.0,green = 0 ,blue = 0.0;
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    h = -1;
    k = 20;
       plot2Dpoint(h,k,red,green,blue);

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

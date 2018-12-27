// line_0.c   cwc
// 181225
// g++ line_0.c -lglut -lGL -o line0
#include <stdio.h>
#include "GL/freeglut.h"
#include "GL/gl.h"

void plot2Dpoint(float x,float y, float red, float green, float blue){
  glColor3f(red, green, blue);
	glBegin(GL_LINES);
	 glVertex2f(x,y);
	 glVertex2f(x+1,y);
	glEnd();

  //printf("%d %d \n",x,y);
  //glFlush();
}

void drawPoints()
{
    int h,k,done;
    float x,y,red,green,blue;
    red = 1.0, blue = 0.25; green = 0.0;
    glClearColor(1, 1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    x = -1; y = -1;
    for (h = 0; h < 500;h++){
  		for (k = 0; k < 500; k++){
        x = (float)h/250;
        y = (float)y/250;
  			plot2Dpoint(x,y,red,green,blue);
        x = x + (1.0/500.0);
       y = y + (1.0/500.0);
  		}
  		red = red + (1.0/500.0);
  		green =red  + (1.0/500.0);
  		blue = blue + (1.0/500.0);
  		//cout << green << endl;
  		if (red > 1)red = 0;
  		if (green > 1)green = 0;
  		if (blue > 1)blue = 0;
  	}
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

// line_0.c   cwc
// 181225
// g++ chaos_0.c -lglut -lGL -o c.o
#include <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"
// random
#include <time.h>
#include <stdlib.h>


void plot2Dpoint(float x,float y, float red, float green, float blue){
	glColor3f(red, green, blue);
    glVertex2f(x, y);
}

void drawPoints()
{
	//random
	srand(time(NULL));
    int lowerLimit = 1, upperLimit = 4;
    int count = 0, rInt = 0;
	//end random
	
    int i,j;
    float h,k;
    float red = 1.0,green = 0 ,blue = 0.0;
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    h = -1.0; k = -1.0;
    glPointSize(1.0);

    for (i = -100; i < 100; i++){
      h = (float)i/800;
      for( j = -100; j < 100; j++){
        k = (float)j/800;
        glBegin(GL_POINTS);// points
			//printf("drawpoints  %f %f \n",h,k);
			rInt =  lowerLimit + rand() % (upperLimit - lowerLimit);
			printf("%d %f %f ", rInt,h,k);
			plot2Dpoint(h,k,red,green,blue);
        glEnd();//end points
        //glFlush();
      }//end i
      green = green + (1.0/160.0);
      if (green > 1)green = 0;
    }//end j
  
	//glEnd();//end points
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL -800x800");
    glutDisplayFunc(drawPoints);
    glutMainLoop();
    return 0;
}

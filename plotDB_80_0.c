// line_0.c   cwc
// 181225
// g++ line_0.c -lglut -lGL -o line0
#include <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"
//random
#include <stdlib.h>
#include <time.h>

int getRandom(int lower, int upper){
        int rInt = (rand() %  (upper - lower + 1)) + lower;
        return rInt;
	}
  
void plot2Dpoint(float x,float y, float red, float green, float blue){
	glColor3f(red, green, blue);
    glVertex2f(x, y);
}

void drawPoints()
{
	//random
	 int lower = 1, upper = 800, count = 1;
    // Use current time as seed for random generator
    srand(time(0));
    int rInt = getRandom(lower,upper); 
	
    int i,j;
    float h,k;
    float red = 1.0,green = 0 ,blue = 0.0;
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    h = -1.0; k = -1.0;
    glPointSize(1.0);
	
	while( count < 1000){
		i = getRandom(lower,upper); 
		j = getRandom(lower,upper); 
		h = (float)i/800;
        k = (float)j/800;
        glBegin(GL_POINTS);// points
			printf("drawpoints  %f %f \n",h,k);
			plot2Dpoint(h,k,red,green,blue);
        glEnd();//end points
        //glFlush();
        green = green + (1.0/160.0);
      }//end while count
      
 
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

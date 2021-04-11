// line_0.c   cwc
// 181225
// g++ line_0.c -lglut -lGL -o line0
#include <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"
//random
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // sleep

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
	 int lower = -20, upper = 20, count = 1;
    // Use current time as seed for random generator
    srand(time(0));
    int rInt = getRandom(lower,upper); 
	
    int i,j,getPoint;
    float h,k,h1,h2,k1,k2,ph1,pk1,ph2,pk2,ph3,pk3,sh,sk;
    float red = 0.0,green = 0.0 ,blue = 0.0;
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    h1 = -1.0; k1 = -1.0;
    glPointSize(1.0);
	ph1 = 0.0; pk1 = 0.95; ph2 = -0.95; pk2 = -0.695; ph3 = 0.95; pk3 = -0.695;
	i = getRandom(lower,upper); 
	j = getRandom(lower,upper); 
	sh = (float)i/800;
	sh = 0;
	sk = (float)j/800;
	sk = 0;
	h1 = (ph1 - sh)/2; k1 = (pk1 - sk)/2;
	while( count < 1000000){
		getPoint = getRandom(1,3);
		h2 = h1; k2 = k1;
		//printf("getPoint %d ",getPoint); 
        if(getPoint == 1){
			h1 = (ph1 + h2)/ 2; k1 = ( pk1 + k2)/2;
		}//point 1
		 if(getPoint == 2){
			h1 = (ph2+ h2)/ 2; k1 = (pk2 + k2)/2;
		}//point 2
		 if(getPoint == 3){
			h1 = (ph3 + h2)/ 2; k1 = (pk3 + k2)/2;
		}//point 2
        glBegin(GL_POINTS);// points
			//printf("drawpoints  %f %f %f %f \n",h1,k1,h2,k2);
			plot2Dpoint(h1,k1,0.0,0.0,0.0);
        glEnd();//end points
        //glFlush();
        count++;
      }//end while count
      
 
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_DOUBLE);
      glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL -800x800");
    glutDisplayFunc(drawPoints);
    glutMainLoop();
    return 0;
}

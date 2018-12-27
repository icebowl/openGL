// line_0.c   cwc
// 181225
// g++ line_0.c -lglut -lGL -o line0
#include <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"

void plot2D(float x,float y, float red, float green, float blue){
    glColor3f(red, green, blue);
    glVertex2f(x, y);
}

void drawPoints(){
    int scale = 400;
    int colors = 64;
    int iterations = 1000;
    int limit = 100;
    float h,k;
    int count;
    float z,x,y,x1,y1,x2,y2,jd,id;

    float c1 = -1.0;
    float c2 = 0.0;
    float red = 1.0,green = 0 ,blue = 0.0;
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glPointSize(1.0);// set pixel size
    glBegin(GL_POINTS);// points
    // ************************************************************
    for (k = -1.0 ; k <= 1.0 ; k = k + (1.0/800.0)) {
			y1 = k / 0.5;
				for (h = -1.0 ; h <= 1.0; h = h + (1.0/800.0)){
					x1 =  h / 0.5;
					x = x1;
					y = y1;
					z = 0.0;
					count = 0;
					do {
						x2 = (x * x) - (y * y) + c1;
						y = (2 * x * y) + c2;
						x = x2;
						z = (x * x) + (y * y);
						count++;
					}while ((count <= iterations) & (z < 4.0));
						if (count >= limit) {
      				red = count%colors;
      				green= count%colors;
      				blue = count%colors;
      				plot2D(h,k,red,green,blue);
              printf("drawpoints  %f %f \n",h,k);
					}
	    	}//end for i
        }//end for j
      // only change code above this line
    // ************************************************************
    glEnd();//end points
    glutSwapBuffers();// this draws the points
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

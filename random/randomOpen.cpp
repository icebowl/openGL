// line_0.c   cwc
// 181225
// g++ line_0.c -lglut -lGL -o line0
#include <iostream>
#include <random>

//nclude <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"

using namespace std;

void plot2Dpoint(float x,float y, float red, float green, float blue){
  glColor3f(red, green, blue);
    glVertex2f(x, y);
}

void drawPoints()
{
	
	default_random_engine PRNG(random_device {}());
   uniform_real_distribution<double> dist(0.0, 1.0);

   const int nSimulations { 1000 };
// * * * * * * * *
	
    int i,j;
    float h,k;
    float red = 0.0,green = 1.0 ,blue = 0.0;
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    h = -1.0; k = -1.0;
    glPointSize(1.0);
    glBegin(GL_POINTS);// points
    for (i = 0; i < 1000; i++){
    
      h = dist(PRNG);
      k = dist(PRNG) ;
     cout<<h<<" "<<k<<endl;
        plot2Dpoint(h,k,red,green,blue);
        //glFlush();
      }//end i

    
    glEnd();//end points

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


// line_0.c   cwc
// 181225
// g++ line_0.c -lglut -lGL -o line0
#include <iostream>
#include <random>

//nclude <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"
// text


using namespace std;

void plot2Dpoint(float x,float y, float red, float green, float blue){
  glColor3f(red, green, blue);
    glVertex2f(x, y);
}

void drawPoints()
{
	
	default_random_engine PRNG(random_device {}());
   uniform_real_distribution<double> dist(-1.0, 1.0);

   const int nSimulations { 1000 };
	// * * * * * * * *
	double circle = 0 , square = 0;
	// * * * * * * * *
    long i,j;
    float h,k;
	double pi = 0.0;
    float red = 0.0,green = 1.0 ,blue = 0.0;
    //glClearColor(0.4, 0.4, 0.4, 0.4);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    h = -1.0; k = -1.0;
    long iterations = 1000000; // 1, 000, 000 , 000 ,000
    cout<<"\n\n";
    glPointSize(1.0);
    glBegin(GL_POINTS);// points
    for (i = 0; i < iterations; i++){
		square = (double)i;
      h = dist(PRNG);
      k = dist(PRNG) ;
		if(h*h + k*k <= 1.0) circle = circle + 1;
		pi = (double) (4 * (circle / square));
      if ((h*h + k*k)< 1.0) {
			red =155.0/255.0; green = 104.0/255.0; blue = 74.0/255.0;
		}else{
			red = 1.0;green = 1.0 ;blue = 0.0;
		}
		
		if (h < 0.01  && h > -0.01){red = 0.0;green = 0.0 ;blue = 0.0;}
		if (k < 0.01  && k > -0.01){red = 0.0;green = 0.0 ;blue = 0.0;}
		plot2Dpoint(h,k,red,green,blue);
	if ((i % (iterations / 100) == 0) || (i == 1000) || (i == 2000))
		cout<<pi<<" ";
        
        //glFlush();
      }//end i
		 cout<<"PI estimated = "<<pi<<endl;
    
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


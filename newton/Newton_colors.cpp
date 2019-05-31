// Julia_128_custom.cpp   cwc
// 181225
// g++ Julia_128_custom.cpp -lglut -lGL -o Julia128_custom.o
// ./Julia128_custom.o 0.345 0.565 128  4 1
//
#include <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"
#include <iostream>
#include <array>
using namespace std; // c++ namespace
//globals for command line input
int colors_arg;
int limit_arg;
float scale_arg;
float c1_arg,c2_arg;

float round3(float var)
{
    float value = (int)(var * 1000 + 0,5);
    return (float)value / 1000;
}

void plot2D(float x,float y, float red, float green, float blue){
    glColor3f(red, green, blue);
    glVertex2f(x, y);
}

array<array<float,3>,128> buildColors(  array<array<float,3>,2> colors, int numberOfColors){
  array<array<float,3>,128>Colors128;
    int n;
    int m=0; // m is the counter
    float sr,sg,sb,er,eg,eb,ir,ig,ib;
    for (n =0;n < 2 ; n++){
      cout<<"colors n="<<n<<" " << colors[n][0]<<" "<<colors[n][1]<<" "<<colors[n][2]<<endl;
    }
    sr = colors[m][0];sg = colors[m][1];sb = colors[m][2];
    er = colors[m+1][0];eg = colors[m+1][1];eb = colors[m+1][2];
    ir = (er-sr)/numberOfColors;ig = (eg-sg)/numberOfColors; ib =(eb-sb)/numberOfColors;
  //  if(ir < 0.0)ir = ir*-1.0; if(ig < 0.0)ig = ig * -1.0; if(ib < 0.0)ib = ib * -1.0;

    //ir = 0.001; ig = 0.001; ib = 0.001;
    cout<<"increments " << ir <<" "<<ig<<" "<<ib<<endl;
    Colors128[m][0] = colors[m][0] ;
    Colors128[m][1] = colors[m][1];
    Colors128[m][2] = colors[m][2];
  m = 1;
    while(m < 128){
            Colors128[m][0] = Colors128[m-1][0] + ir;
              if(Colors128[m][0] < 0.0)Colors128[m][0] = 0.0;
              if(Colors128[m][0] > 1.0)Colors128[m][0] = 1.0;
            Colors128[m][1] = Colors128[m-1][1] + ig;
              if(Colors128[m][1] < 0.0)Colors128[m][1] = 0.0;
              if(Colors128[m][1] > 1.0)Colors128[m][1] = 1.0;
            Colors128[m][2] = Colors128[m-1][2] + ib;
              if(Colors128[m][2] < 0.0)Colors128[m][2] = 0.0;
              if(Colors128[m][2] > 1.0)Colors128[m][2] = 1.0;

              m = m + 1;
          //  cout<<" m = "<<m<<endl;
          //   cout<< Colors128[n+m][0]<<" "<<Colors128[n+m][1]<<" "<<Colors128[n+m][2]<<endl;
    }
for (n =0;n < 129 ; n++){
    //cout<<"n="<<n<<" " << Colors128[n][0]<<" "<<Colors128[n][1]<<" "<<Colors128[n][2]<<endl;
    }

    return Colors128;
}

void drawPoints(){
  // these are the starting colors
  array<array<float,3>,2> colors = {{
      {   1.0, 0.3 , 0.0},
      {   0.125 , 0.215 , 0.192}
      //20 37 31
    }};
    int total_colors = colors_arg;
    int setcolor = 0;
    int iterations = 1000;
    int limit = limit_arg;
    float h,k;
    int count,maxcount;
    float x,y,x1,y1,x2,y2,jd,id;
      array<array<float,3>,128>colors128 = buildColors(colors,total_colors);
    // .34567 .5

    float red = 1.0,green = 0 ,blue = 0.0;
    glClearColor(1.0,1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glOrtho(-400.0, 400.0, -400.0, 400.0, -400.0, 400.0);
    glPointSize(1.0);// set pixel size
    glBegin(GL_POINTS);// points
    // ************************************************************
    maxcount = 0;
    float scale = scale_arg/2.0;
    count = 0;
    for (k = -400.0 ; k <= 400.0 ; k = k + 1 ){
			y1 = k / scale;
				for (h = -400.0 ; h <= 400.0; h = h + 1){
					x1 =  h / scale;
					x = x1;
					y = y1;

              setcolor = count % total_colors;
      				red = colors128[setcolor][0];
              green= colors128[setcolor][1];
      				blue = colors128[setcolor][2];
      				plot2D(h,k,red,green,blue);
	    	}
        count++;
      }
      //  printf("max count %d \n",maxcount);

      // only change code above this line
    // ************************************************************
    glEnd();//end points
    glutSwapBuffers();// this draws the points
}

int main(int argc, char **argv)
{

    cout<< argv[1]<<endl;
    cout<< argv[2]<<endl;
    colors_arg = stoi(argv[1]);
    scale_arg = stof(argv[2]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Newton Method OpenGL");
    glutDisplayFunc(drawPoints);
    glutMainLoop();
    return 0;
}

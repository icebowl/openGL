// line_0.c   cwc
// 181225
// g++ line_0.c -lglut -lGL -o line0
#include <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"
//float color256[256][3] = {};
float color[16][3]= {
    {  0.0 , 0.1686 , 0.2117 },
    {   0.0274 , 0.2117 , 0.2588},
    {   0.3450 , 0.4313 , 0.4588},
    {   0.3960 , 0.4823, 0.5137},
    {   0.5137 , 0.5803 , 0.5882},
    {   0.5764 , 0.6313 , 0.6313},
    {   0.9333 , 0.9098, 0.8352},
    {   0.9921 , 0.9647 , 0.8901},
    {   0.7098 , 0.5372 , 0.0},
    {   0.7960 , 0.2941 , 0.0862},
    {   0.8627 , 0.1961 , 0.1843},
    {   0.8274, 0.2117 , 0.5098 },
    {   0.4235, 0.4431 , 0.7686},
    {   0.1491 , 0.5450 , 0.8235},
    {   0.1647 , 0.6313 , 0.5961},
    {   0.2549 , 0.5215 , 0.6}

};

floar
void plot2D(float x,float y, float red, float green, float blue){
    glColor3f(red, green, blue);
    glVertex2f(x, y);
}

void drawPoints(){
    int scale = 400;
    int colors = 16;
    int setcolor = 0;
    int iterations = 10000;
    int limit = 0;
    float h,k;
    int count,maxcount;
    float z,x,y,x1,y1,x2,y2,jd,id;
// .34567 .5
    float c1 = 0.345;
    float c2 = 0.575;
    float red = 1.0,green = 0 ,blue = 0.0;
    glClearColor(1.0,1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glPointSize(1.0);// set pixel size
    glBegin(GL_POINTS);// points
    // ************************************************************
    maxcount = 0;
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
            if(count > maxcount)maxcount = count;
						if (count >= limit) {
              setcolor = (float)(count % colors);
      				red = color[setcolor][0];
              green= color[setcolor][1];
      				blue = color[setcolor][2];
      				plot2D(h,k,red,green,blue);

				}
	    	}//end for i
        }//end for j
        printf("max count %d \n",maxcount);

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
/*
base03     0.0 , 0.16862745098039217 , 0.21176470588235294
base02     0.027450980392156862 , 0.21176470588235294 , 0.25882352941176473
base01     0.34509803921568627 , 0.43137254901960786 , 0.4588235294117647
base00     0.396078431372549 , 0.4823529411764706 , 0.5137254901960784
base0     0.5137254901960784 , 0.5803921568627451 , 0.5882352941176471
base1     0.5764705882352941 , 0.6313725490196078 , 0.6313725490196078
base2     0.9333333333333333 , 0.9098039215686274 , 0.8352941176470589
base3     0.9921568627450981 , 0.9647058823529412 , 0.8901960784313725
yellow     0.7098039215686275 , 0.5372549019607843 , 0.0
orange     0.796078431372549 , 0.29411764705882354 , 0.08627450980392157
red     0.8627450980392157 , 0.19607843137254902 , 0.1843137254901961
magenta     0.8274509803921568 , 0.21176470588235294 , 0.5098039215686274
violet     0.4235294117647059 , 0.44313725490196076 , 0.7686274509803922
blue     0.14901960784313725 , 0.5450980392156862 , 0.8235294117647058
cyan     0.16470588235294117 , 0.6313725490196078 , 0.596078431372549
green     0.2549019607843137 , 0.5215686274509804 , 0.6

0.0 , 0.16862745098039217 , 0.21176470588235294
0.027450980392156862 , 0.21176470588235294 , 0.25882352941176473
0.34509803921568627 , 0.43137254901960786 , 0.4588235294117647
0.396078431372549 , 0.4823529411764706 , 0.5137254901960784
0.5137254901960784 , 0.5803921568627451 , 0.5882352941176471
0.5764705882352941 , 0.6313725490196078 , 0.6313725490196078
0.9333333333333333 , 0.9098039215686274 , 0.8352941176470589
0.9921568627450981 , 0.9647058823529412 , 0.8901960784313725
0.7098039215686275 , 0.5372549019607843 , 0.0
0.796078431372549 , 0.29411764705882354 , 0.08627450980392157
0.8627450980392157 , 0.19607843137254902 , 0.1843137254901961
0.8274509803921568 , 0.21176470588235294 , 0.5098039215686274
0.4235294117647059 , 0.44313725490196076 , 0.7686274509803922
0.14901960784313725 , 0.5450980392156862 , 0.8235294117647058
0.16470588235294117 , 0.6313725490196078 , 0.596078431372549
0.2549019607843137 , 0.5215686274509804 , 0.6
*/

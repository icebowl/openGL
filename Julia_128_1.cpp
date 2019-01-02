// line_0.c   cwc
// 181225
// g++ line_0.c -lglut -lGL -o line0
#include <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"
#include <iostream> // c++
#include <array>
using namespace std; // c++ namespace

float round3(float var)
{
    float value = (int)(var * 1000 + .5);
    return (float)value / 1000;
}

void plot2D(float x,float y, float red, float green, float blue){
    glColor3f(red, green, blue);
    glVertex2f(x, y);
}

array<array<float,3>,128> buildColors(  array<array<float,3>,16> colors){
  array<array<float,3>,128>Colors128;
    int n; // n is the index between each gradiant end and start
    int m=0; // m is the multiple
    float sr,sg,sb,er,eg,eb,ir,ig,ib;
    for (n =0;n < 16 ; n++){
      cout<<"colors n="<<n<<" " << colors[n][0]<<" "<<colors[n][1]<<" "<<colors[n][2]<<endl;
    }
    while(m < 128){
          sr = colors[m][0];sg = colors[m][1];sb = colors[m][2];
          er = colors[m+1][0];eg = colors[m+1][1];eb = colors[m+1][2];
          ir = round3((er-sr)/8);ig = round3((eg-sg)/8); ib =round3((eb-sb)/8);
          if(ir < 0.0)ir = ir*-1.0; if(ig < 0.0)ig = ig * -1.0; if(ib < 0.0)ib = ib * -1.0;

          //ir = 0.001; ig = 0.001; ib = 0.001;
          cout<<"increments " << ir <<" "<<ig<<" "<<ib<<endl;
          Colors128[m][0] = colors[m][0] ;
          Colors128[m][1] = colors[m][1];
          Colors128[m][2] = colors[m][2];
          for (n = 1; n < 8; n++){
            Colors128[n+m][0] = Colors128[n+m-1][0] + ir;
                  if(Colors128[n+m][0] < 0.0)Colors128[n+m][0] = 0.0;
                if(Colors128[n+m][0] > 1.0)Colors128[n+m][0] = 1.0;
            Colors128[n+m][1] = Colors128[n+m-1][1] + ig;
                  if(Colors128[n+m][1] < 0.0)Colors128[n+m][1] = 0.0;
                    if(Colors128[n+m][1] > 1.0)Colors128[n+m][1] = 1.0;
            Colors128[n+m][2] = Colors128[n+m-1][2] + ib;
                  if(Colors128[n+m][2] < 0.0)Colors128[n+m][2] = 0.0;
                    if(Colors128[n+m][2] > 1.0)Colors128[n+m][2] = 1.0;
            }
              m = m + 8;
          //  cout<<" m = "<<m<<endl;
          //   cout<< Colors128[n+m][0]<<" "<<Colors128[n+m][1]<<" "<<Colors128[n+m][2]<<endl;
    }
for (n =0;n < 129 ; n++){
         if (n%8 == 0 && n != 0)cout<<" * * end for * *"<<endl;
      cout<<"n="<<n<<" " << Colors128[n][0]<<" "<<Colors128[n][1]<<" "<<Colors128[n][2]<<endl;
    }

    return Colors128;
}

void drawPoints(){
  //float color256[256][3] = {};
  array<array<float,3>,16> colors = {{
    {  0.0 , 0.169 , 0.212 },
    {   0.027 , 0.212 , 0.259},
    {   0.345 , 0.431 , 0.459},
    {   0.396 , 0.482, 0.514},
    {   0.514 , 0.580 , 0.588},
      {   0.576 , 0.631 , 0.631},
      {   0.933 , 0.909, 0.835},
      {   0.992 , 0.965 , 0.890},
      {   0.709 , 0.537 , 0.0},
      {   0.796 , 0.294 , 0.086},
      {   0.862 , 0.196 , 0.184},
      {   0.827, 0.212 , 0.510 },
      {   0.424, 0.443 , 0.769},
      {   0.149 , 0.545 , 0.824},
      {   0.165 , 0.631 , 0.596},
      {   0.255 , 0.522 , 0.6}
    }};
    array<array<float,3>,128>colors128 = buildColors(colors);
    int scale = 400;
    int total_colors = 16;
    int setcolor = 0;
    int iterations = 1000;
    int limit = 0;
    float h,k;
    int count,maxcount;
    float z,x,y,x1,y1,x2,y2,jd,id;
    // .34567 .5
    float c1 = 0.3456;
    float c2 = 0.5321;
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
              setcolor = (count % total_colors);
      				red = colors128[setcolor][0];
              green= colors128[setcolor][1];
      				blue = colors128[setcolor][2];
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
    int r,c;
    float scale;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Julia Set OpenGL");
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

//  g++ Newton_abi.cpp -lglut -lGL -o nm.o
// cw coleman 190608
// ./nm.o 31 400 13
// colors scale limit
#include <stdio.h>
#include "GL/glut.h"
#include "GL/gl.h"
#include <iostream>
#include <array>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std; // c++ namespace
struct ABi {
   double a;
   double bi;
};

//globals for command line input
int colors_arg;
int limit_arg;
float scale_arg;

// a+bi
/* print_a: print a struct passed by value (copied) */
void printABi(ABi abi) {
  double x = abi.a;
  double yi = abi.bi;
   //cout <<"* * * print a+bi -> "<< x<<" + "<<yi<<" i "<<endl;
}

ABi abiPower (ABi abi,double coef, double term, int root){
  ABi abiReturn;
  double a = abi.a;
  double bi = abi.bi;
  double x,yi,xt, yti;
  int n;
  // a+bi and x+yi loop for products
  x=a; yi = bi;
  for (n = 1; n < root; n++){
    xt = (x*a)-(yi*bi);
    yti = (a*yi)+(x*bi);
    x = xt; yi = yti;
  }
  x = coef*x + term;
  yi = coef*yi;
//   cout<<" abiPower "<<endl;
//  cout << " x " << x << " yi "<< yi <<endl;
  abiReturn.a = x;
  abiReturn.bi = yi;
//  printABi(abiReturn);
  return abiReturn;
}

ABi abiDivide (ABi n, ABi d){
  ABi quo;
  double a = n.a;
  double bi = n.bi;
  double x = d.a;
  double yi = d.bi;
  double hn,kni ,kd,q,qi;
  // numberator
//  cout<<" @ @ @ "<<endl;
 // printABi(n);
//  printABi(d);
  hn = (a*x + bi * yi);
  kni = (-1*a*yi + x * bi) ;
  //denominator
  kd = (x*x)+(yi*yi);
  //divide
  q = hn / kd;  qi = kni / kd;
  quo.a = q; quo.bi = qi;
//  cout<<" ~ ~ ~ "<<endl;
  //printABi(quo);
  return quo;
}

ABi abiAdd (ABi xn1, ABi xn){
  ABi sum;
  double a = xn.a;
  double bi = xn.bi;
  double x = xn1.a;
  double yi = xn1.bi;
  //subtract
  sum.a = x - a;
  sum.bi = yi - bi;

  return sum;
}

bool abiCompare (ABi xn1, ABi xn){
  ABi sum;
  double a = xn.a;
  double bi = xn.bi;
  double x = xn1.a;
  double yi = xn1.bi;
  int aI,biI,xI,yiI;
  bool compare =  false;
  //cout<<"compare "<<endl;
//  printABi(xn1);
//  printABi(xn);
  int limit = int (limit_arg);
  aI = int(a * limit);
  xI = int(x * limit);
  biI = int(bi * limit);
  yiI = int(yi * limit);

  //cout <<aL<<" "<<xL<<" "<<biL<<" "<<yiL<<endl;
    if ((aI == xI)&&(biI == yiI)){
      compare = true;
  //  cout<<"compare function "<<compare<<endl;
  }
  return compare;
}

///////////////////////

void plot2D(float x,float y, float red, float green, float blue){glColor3f(red, green, blue);glVertex2f(x, y);
}

// build colors * * * * * * *
array<array<float,3>,128> buildColors(  array<array<float,3>,2> colors, int numberOfColors){
  array<array<float,3>,128>Colors128;
    int n;
    int m=0; // m is the counter
     srand(static_cast<unsigned int>(clock()));
     float r,g,b,ra,ga,ba;
    r = 0; b = 0; g = 0;
           r = (rand() / (float)RAND_MAX );
        g = (rand() / (float)RAND_MAX );
      b = (rand() / (float)RAND_MAX );
      ra = (rand() / (float)RAND_MAX )/ 100;
	ga = (rand() / (float)RAND_MAX )/100;
	ba = (rand() / (float)RAND_MAX )/100;
       
    while(m < 128){
      Colors128[m][0] = r;
      Colors128[m][1] = g;
      Colors128[m][2] = b;
      r = r + ra;
      g = g + ga;
      b = b + ba;
      if (r > 1) ra  = ra * -1;
      if (g > 1) ga = ga * -1;
      if (b > 1) ba = ba * -1;
      
              m = m + 1;
          //  cout<<" m = "<<m<<endl;
          //   cout<< Colors128[n+m][0]<<" "<<Colors128[n+m][1]<<" "<<Colors128[n+m][2]<<endl;
    }
for (n =0;n < 128 ; n++){
    cout<<"n="<<n<<" " << Colors128[n][0]<<" "<<Colors128[n][1]<<" "<<Colors128[n][2]<<endl;
    }

    return Colors128;
}

void drawPoints(){
  // these are the starting colors
        //113,176,159
  array<array<float,3>,2> colors = {{
      {   0.443,0.7 , .624},
      {   1.0,1.0,1.0}
    }};
    int total_colors = colors_arg;
    int setcolor = 0;
    int iterations = 1000;
    int limit = limit_arg;
    float h,k;
    int count,maxcount;
    float x,y,x1,y1,x2,y2,jd,id;
      array<array<float,3>,128>colors128 = buildColors(colors,total_colors);
      
    float red = 1.0,green = 0 ,blue = 0.0;
    glClearColor(1.0,1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glOrtho(-400.0, 400.0, -400.0, 400.0, -400.0, 400.0);
    glPointSize(1.0);// set pixel size
    glBegin(GL_POINTS);// points
    // ************************************************************
     ABi xyin, xyin1, quo, num, den;
    // * * * *
    bool done = false;
    maxcount = 0;
    float scale = scale_arg/2.0;

    for (k = -400.0 ; k <= 400.0 ; k = k + 1 ){
			y1 = k / scale;
				for (h = -400.0 ; h <= 400.0; h = h + 1){
					x1 =  h / scale;
					//x = x1;
					//y = y1;
          xyin.a = x1;
          xyin.bi = y1;
          //printABi(xyin);
          /////////////////////
          done = false;
            count = 0;
            while(!done){
              num = abiPower(xyin,1.0,-1.0,4);
              den = abiPower(xyin,4.0,0.0,3);
               quo = abiDivide(num,den);
               xyin1 = abiAdd(xyin,quo);
               done = abiCompare(xyin1,xyin);
               xyin = xyin1;
               count++;
             }
            // cout<<" count "<<count<<endl;
            ////////////////
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
    cout<< argv[3]<<endl;
    colors_arg = stoi(argv[1]);
    scale_arg = stof(argv[2]);
    limit_arg = stof(argv[3]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Newton Method OpenGL");
    glutDisplayFunc(drawPoints);
    glutMainLoop();
    return 0;
}

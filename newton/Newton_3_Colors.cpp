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
array<array<float,3>,128> buildColors(  array<array<float,3>,3> colors, int numberOfColors){
  array<array<float,3>,128>Colors128;
    int n;
    int m=0; // m is the counter
    int i1, i2, i3 ;//intervals
    float d1,d2,d3 ;// divisor
    
    float r0,r1,r2,g0,g1,g2,b0,b1,b2;
    float ra0, ra1, ra2, ga0, ga1, ga2, ba0, ba1, ba2;
    r0 = colors[0][0];
    g0 =  colors[0][1];
    b0 =  colors[0][2];

    r1 = colors[1][0];
    g1 =  colors[1][1];
    b1 =  colors[1][2];

    r2 = colors[2][0];
    g2 =  colors[2][1];
    b2 =  colors[2][2];
    i1 = 43; i2 = 87; i3 = 128;
    cout<<r0<<" "<<g0<<" "<<b0<<" start colors "<<endl;
    // * * * * 
    d1 = (float) i1; d2 = (float)i2; d3 = (float)i3;
    ra0 = (r1 - r0)/ d1;  ga0 = (g1 - g0)/ d2; ba0 = (b1 - b0)/ d3;
    ra1 = (r2 - r1)/ d2;  ga1 = (g2 - g1)/ d2; ba1 = (b2 - b1)/ d2;
    ra2 = (r2 - 1.0)/ d3; ga2 = (ga2 - 1.0)/ d3; ba2 = (b2 - 1.0)/ d3;
    cout<<ra0<<ga0<<ba0<<" adjust \n\n";
    int interval = 128 / 3;
    while(m < 128){
      if ( m < i1){
	Colors128[m][0] = r0 ;
	Colors128[m][1] = g0 ;
	Colors128[m][2] = b0 ;
	r0 = r0 + ra0;
	g0 = g0 + ga0;
	b0 = b0 + ba0;
	if (r0 > 1.0) ra0 = ra0 * -1;
	if (g0 > 1.0) ga0 = ga0 * -1;
	if (b0 > 1.0) ba0 = ba0 * -1;
	if (r0 < 0.0) ra0 = ra0 * -1;
	if (g0 < 0.0)  ga0 = ga0 * -1;
	if (b0 < 0.0)  ba0 = ba0 * -1;
	
      }
      if (( m > i1 - 1) && ( m <  i2 )){
	Colors128[m][0] = r1 ;
	Colors128[m][1] = g1 ;
	Colors128[m][2] = b1 ;
	r1 = r1 + ra1;
	g1 = g1 + ga1;
	b1 = b1 + ba1;
	if (r1 > 1.0) ra1 = ra1 * -1;
	if (g1 > 1.0) ga1 = ga1 * -1;
	if (b1 > 1.0) ba1 = ba1 * -1;
	if (r1 < 0.0) ra1 = ra1 * -1;
	if (g1 < 0.0)  ga1 = ga1 * -1;
	if (b1 < 0.0)  ba1 = ba1 * -1;
      }
      if ((m > i2-1) && ( m <  i3)){
	Colors128[m][0] = r2 ;
	Colors128[m][1] = g2 ;
	Colors128[m][2] = b2 ;
	r2 = r2 + ra2;
	g2 = g2 + ga2;
	b2 = b2 + ba2;
	if (r2 > 1.0) ra2 = ra2 * -1;
	if (g2 > 1.0) ga2 = ga2 * -1;
	if (b2 > 1.0) ba2 = ba2 * -1;
	if (r2 < 0.0) ra2 = ra2 * -1;
	if (g2 < 0.0) ga2 = ga2 * -1;
	if (b2 < 0.0) ba2 = ba2 * -1;
      }
      
       m = m + 1;
            
    }
for (n =0;n < 128 ; n++){
    cout<<"n="<<n<<" " << Colors128[n][0]<<" "<<Colors128[n][1]<<" "<<Colors128[n][2]<<endl;
    }

    return Colors128;
}

// drawPoints
void drawPoints(){
  // these are the starting colors
        //113,176,159
  // 2d array
  float cr2, cg2, cb2, cr3,cg3, cb3;
  cr2 = (float)17/255; cg2 = (float)57/255; cb2 = (float)17/255;
  cr3 = (float)91/255; cg3 = (float)91/255; cb3 = (float)11/255;
  array<array<float,3>,3> colors = {{
      { 0.443, 0.7 , .62},
      {1.0, 0.5   , 0.0},
      { 0.2, 0.7, 0.0}
      }};
  // celeste  0.443, 0.7 , .624
  /*
  srand(static_cast<unsigned int>(clock()));
     float r,g,b,ra,ga,ba;
    r = 0; b = 0; g = 0;
           r = (rand() / (float)RAND_MAX );
        g = (rand() / (float)RAND_MAX );
      b = (rand() / (float)RAND_MAX );
      ra = (rand() / (float)RAND_MAX )/ 100;
	ga = (rand() / (float)RAND_MAX )/100;
	ba = (rand() / (float)RAND_MAX )/100;
  */

//end starting colors
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

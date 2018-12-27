// cwc  GLFW plot study
//g++ lines_2D_1.cpp -lglfw -lGLU -lGL -o line2d1.o
// glOrtho 	see https://www.opengl.org/sdk/docs/man2/xhtml/glOrtho.xml

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#include <GLFW/glfw3.h>
#include <GL/gl.h>

void plot2Dpoint(int x,int y, float red, float green, float blue){
	glColor3f(red, green, blue);
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();

}

void render_loop()
{
	int h,k,done;
	float red,green,blue;
	green = 0.0;
	glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(1);
	glLineWidth(1);
	for (h = 0; h < 801;h++){
		for (k = 0; k < 801; k++){
			plot2Dpoint(h,k,red,green,blue);
		}
		red = red + (1.0/800.0);
		green =red  + (1.0/400.0);
		blue = blue + (1.0/200.0);
		//cout << green << endl;
		if (red > 1)red = 0;
		if (green > 1)green = 0;
		if (blue > 1)blue = 0;
	}


}

// main function
int main(int argc, char *argv[])
{
	GLFWwindow* window;
	if( !glfwInit() )
	{	fprintf( stderr, "Failed to initialize GLFW\n" );	exit( EXIT_FAILURE );}

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow( 800, 800, "OpenGL", NULL, NULL );
	if (!window)
	{	fprintf( stderr, "Failed to open GLFW window\n" );	glfwTerminate();	exit( EXIT_FAILURE );}
	glfwMakeContextCurrent(window);
	glfwSwapInterval( 1 );
	glViewport( 0, 0, 800, 800 ); 	// set up view
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(0.0,800.0,0.0,800.0,0.0,1.0); // this creates a canvas you can do 2D drawing on
	// main loop
	while( !glfwWindowShouldClose(window) )
	{		render_loop(); 	// Draw gears
		glfwSwapBuffers(window); // Swap buffers
		glfwPollEvents();
	}
	glfwTerminate(); 	// Terminate GLFW
	exit( EXIT_SUCCESS ); 	// Exit program
}//end main function

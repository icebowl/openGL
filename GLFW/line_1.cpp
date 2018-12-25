#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <GLFW/glfw3.h>
#include <GL/gl.h>


void render_loop()
{
	glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(10);
	glLineWidth(2.5);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(210.0,0.0,0.0);
		glVertex3f(0.0,0.0,0.0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(400,400,0);
	glEnd();

}

// main
int main(int argc, char *argv[])
{
	GLFWwindow* window;
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		exit( EXIT_FAILURE );
	}

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow( 400, 400, "LearnOpenGL", NULL, NULL );
	if (!window)
	{
		fprintf( stderr, "Failed to open GLFW window\n" );
		glfwTerminate();
		exit( EXIT_FAILURE );
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval( 1 );

	// set up view
	glViewport( 0, 0, 400, 400 );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// see https://www.opengl.org/sdk/docs/man2/xhtml/glOrtho.xml
	glOrtho(0.0,400.0,0.0,400.0,0.0,1.0); // this creates a canvas you can do 2D drawing on

	// Main loop
	while( !glfwWindowShouldClose(window) )
	{
		render_loop(); 	// Draw gears
		glfwSwapBuffers(window); // Swap buffers
		glfwPollEvents();
	}
	glfwTerminate(); 	// Terminate GLFW
	exit( EXIT_SUCCESS ); 	// Exit program
}

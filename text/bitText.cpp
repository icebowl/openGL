#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstdio>

float xrot = 0.00, yrot = 0.00, zoom = -30;

void text()
{
    char text[32];
    sprintf(text, "X:%.0f Y:%.0f", xrot, yrot);
    glColor3f(0, 0, 0);
    glRasterPos3f( -25 , 20 , zoom);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void render(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0, zoom);

    // Write the text before any transformation or rotation
    // Or the text will change its position with the models
    text();

    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    // Blue Cube
    glColor3f(0.0, 0.5, 0.9);
    glutSolidCube(10);

    glFlush();
    glutSwapBuffers();
}

void init(void)
{
    glClearColor( 1, 1, 1, 1);
    glClearDepth( 1.0 );
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_LIGHT0);
}

void reshape(int w, int h)
{
    float aspectRatio = (float)w/(float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 's':
        xrot -= 1.0;
        break;
    case 'a':
        yrot -= 1.0;
        break;
    case 'w':
        xrot += 1.0;
        break;
    case 'd':
        yrot += 1.0;
        break;
    case 27:
        exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(400, 300);
    glutCreateWindow("Bitmap Text Example");
    init();
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}

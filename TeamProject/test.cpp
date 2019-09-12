#include<GL/glut.h>
#include<GL/GL.h>
#include<GL/GLU.h>

GLfloat vertices[][] = {
	{0, 0, 0},
{0,0,1},
{0,1,0},
{0,1,1},
{1,0,0},
{1,0,1},
{1,1,1}
};

void cube() {

}

/*
a----d
|    |
|    |
b----c
*/

void polygon(int a, int b, int c, int d) {
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(0, a, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(c, y, 0);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glVertex3fv();
		glVertex3fv();
		glVertex3fv();
	}
	glEnd();
}
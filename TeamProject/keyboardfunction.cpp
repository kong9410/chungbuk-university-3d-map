/*********************************************************************************************************************

* �ۼ��� : ����ö, ����ȣ

* ���ϸ� : keyboardfunction.cpp

* ���� : Ű���� ���� �Լ��� ���Ե� �ڵ�.

**********************************************************************************************************************/
#include"keyboardfunction.h"
float a1 = 0, a2 = 0, a3 = 0;
//Ű ������ ��
void pressKey(unsigned char key, int x, int y)
{
	unsigned char c = (unsigned char)key;
	switch (c)
	{
	case 'a':
		deltaAngle = -0.03f;
		break;
	case 'd':
		deltaAngle = 0.03f;
		break;
	case 'w':
		deltaMove = 2;
		break;
	case 's':
		deltaMove = -2;
		break;
	}
}

//Ű ���� ��
void releaseKey(unsigned char key, int x, int y)
{
	unsigned char c = (unsigned char)key;
	switch (c)
	{
	case 'a':
	case 'd':
		deltaAngle = 0.0f;
		break;
	case 'w':
	case 's':
		deltaMove = 0;
		break;
	}
}



void move_view(GLdouble movex, GLdouble movey, GLdouble movez) {
	glTranslatef(movex, -movey, movez);
	glRotatef(a2, 1, 0, 0);
}






void orientMe(float ang)
{
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i)
{
	x = x + i * (lx)*0.1;
	z = z + i * (lz)*0.1;
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}


void renderScene(void)
{
	moveMeFlat(deltaMove);
	angle += deltaAngle;
	orientMe(angle);
}

/*********************************************************************************************************************

* �ۼ��� : ����ö, ����ȣ

* ���ϸ� : Model.cpp

* ���� : ����, ����, ���ε� �� �𵨵��� �𵨸��ϰ� ��ġ�� �Լ��� ���Ե� �ڵ�.

**********************************************************************************************************************/

#include "Model.h"

//---------------------------------------   Render_Wheel   -----------------------------------------

void Render_Wheel(int xt, int yt, int zt)  //������ ���� �𵨸�
{
	glPushMatrix();
	glTranslatef(xt, yt, zt);
	glutSolidTorus(2, 5, 12, 36);
	glPopMatrix();
}

//-----------------------------------------   Draw_Car   -------------------------------------------

void Draw_Car1(void)  //1. �Ķ���
{
	glPushMatrix();

	glDisable(GL_CULL_FACE);  //�ܸ� ������ �ÿ� ������ �̻��ϰ� ������ ����
	glTranslatef(C1x, 1, C1z);
	glRotatef(-90, 0, 1, 0);
	if (C1z == 101.5) {
		glRotatef(90, 0, 1, 0);
	}

	glScalef(0.05, 0.05, 0.05);
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.6, 0.6);
	Vrt(-40, 0, 15); Vrt(40, 0, 15); Vrt(40, -15, 15); Vrt(-40, -15, 15);  // left
	Vrt(-40, 0, -15); Vrt(40, 0, -15); Vrt(40, -15, -15); Vrt(-40, -15, -15);  // right
	glColor3f(0.4, 0.6, 0.6);
	Vrt(40, 0, -15); Vrt(40, 0, 15); Vrt(40, -15, 15); Vrt(40, -15, -15);  // back
	Vrt(-40, 0, -15); Vrt(-40, 0, 15); Vrt(-40, -15, 15); Vrt(-40, -15, -15);  // front
	glColor3f(1.0, 1.0, 1.0);  //������Ʈ
	Vrt(-41, -5, 15); Vrt(-41, -10, 15); Vrt(-41, -10, 10); Vrt(-41, -5, 10);  // left
	Vrt(-41, -5, -15); Vrt(-41, -5, -10); Vrt(-41, -10, -10); Vrt(-41, -10, -15); // right
	glColor3f(1.0, 0.1, 0.1);  //���϶���Ʈ
	Vrt(41, -5, 15); Vrt(41, -10, 15); Vrt(41, -10, 10); Vrt(41, -5, 10);  // left
	Vrt(41, -5, -15); Vrt(41, -5, -10); Vrt(41, -10, -10); Vrt(41, -10, -15); // right
	glColor3f(0.4, 0.6, 0.8);
	Vrt(-40, 0, 15); Vrt(-40, 0, -15); Vrt(40, 0, -15); Vrt(40, 0, 15);  // trunks
	Vrt(-10, 10, 15); Vrt(-10, 10, -15); Vrt(20, 10, -15); Vrt(20, 10, 15);  // roof
	glColor3f(0.8, 1, 1);
	Vrt(-20, 0, 15); Vrt(-10, 10, 15); Vrt(20, 10, 15); Vrt(25, 0, 15);  // window l
	Vrt(-20, 0, -15); Vrt(-10, 10, -15); Vrt(20, 10, -15); Vrt(25, 0, -15);  // window r
	glColor3f(0.8, 0.9, 0.9);
	Vrt(-10, 10, 15); Vrt(-20, 0, 15); Vrt(-20, 0, -15); Vrt(-10, 10, -15);  // windshield
	Vrt(20, 10, 15); Vrt(20, 10, -15); Vrt(25, 0, -15); Vrt(25, 0, 15);  // rear window
	glColor3f(0.4, 0.5, 0.5);
	Vrt(-40, -15, 15); Vrt(-40, -15, -15); Vrt(40, -15, -15); Vrt(40, -15, 15);  // bottom
	glEnd();

	// Render wheels using torus's with lighting on.
	glColor3f(0.3, 0.3, 0.3);
	Render_Wheel(-20, -15, 15);  //���� ���� 4��
	Render_Wheel(20, -15, 15);
	Render_Wheel(-20, -15, -15);
	Render_Wheel(20, -15, -15);

	glEnable(GL_CULL_FACE);
	glPopMatrix();
}

void Draw_Car2(void)  //2. ������
{
	glPushMatrix();
	glDisable(GL_CULL_FACE);
	glTranslatef(C2x, 1, C2z);
	glRotatef(90, 0, 1, 0);
	if (C2z == 250.5) {
		glRotatef(-90, 0, 1, 0);
	}
	glScalef(0.05, 0.05, 0.05);
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.3, 0.3);
	Vrt(-40, 0, 15); Vrt(40, 0, 15); Vrt(40, -15, 15); Vrt(-40, -15, 15);  // left
	Vrt(-40, 0, -15); Vrt(40, 0, -15); Vrt(40, -15, -15); Vrt(-40, -15, -15);  // right
	glColor3f(0.8, 0.4, 0.4);
	Vrt(40, 0, -15); Vrt(40, 0, 15); Vrt(40, -15, 15); Vrt(40, -15, -15);  // back
	Vrt(-40, 0, -15); Vrt(-40, 0, 15); Vrt(-40, -15, 15); Vrt(-40, -15, -15);  // front
	glColor3f(1.0, 1.0, 1.0);  //������Ʈ
	Vrt(-41, -5, 15); Vrt(-41, -10, 15); Vrt(-41, -10, 10); Vrt(-41, -5, 10);  // left
	Vrt(-41, -5, -15); Vrt(-41, -5, -10); Vrt(-41, -10, -10); Vrt(-41, -10, -15); // right
	glColor3f(1.0, 0.1, 0.1);  //���϶���Ʈ
	Vrt(41, -5, 15); Vrt(41, -10, 15); Vrt(41, -10, 10); Vrt(41, -5, 10);  // left
	Vrt(41, -5, -15); Vrt(41, -5, -10); Vrt(41, -10, -10); Vrt(41, -10, -15); // right
	glColor3f(0.9, 0.4, 0.4);
	Vrt(-40, 0, 15); Vrt(-40, 0, -15); Vrt(40, 0, -15); Vrt(40, 0, 15);  // trunks
	Vrt(-10, 10, 15); Vrt(-10, 10, -15); Vrt(20, 10, -15); Vrt(20, 10, 15);  // roof
	glColor3f(0.8, 1, 1);
	Vrt(-20, 0, 15); Vrt(-10, 10, 15); Vrt(20, 10, 15); Vrt(25, 0, 15);  // window l
	Vrt(-20, 0, -15); Vrt(-10, 10, -15); Vrt(20, 10, -15); Vrt(25, 0, -15);  // window r
	glColor3f(0.8, 0.9, 0.9);
	Vrt(-10, 10, 15); Vrt(-20, 0, 15); Vrt(-20, 0, -15); Vrt(-10, 10, -15);  // windshield
	Vrt(20, 10, 15); Vrt(20, 10, -15); Vrt(25, 0, -15); Vrt(25, 0, 15);  // rear window
	glColor3f(0.9, 0.4, 0.4);
	Vrt(-40, -15, 15); Vrt(-40, -15, -15); Vrt(40, -15, -15); Vrt(40, -15, 15);  // bottom
	glEnd();

	// Render wheels using torus's with lighting on.

	glColor3f(0.3, 0.3, 0.3);
	Render_Wheel(-20, -15, 15);
	Render_Wheel(20, -15, 15);
	Render_Wheel(-20, -15, -15);
	Render_Wheel(20, -15, -15);
	glEnable(GL_CULL_FACE);
	glPopMatrix();
}

void Draw_Car3(void)  //3. �����
{
	glPushMatrix();
	glDisable(GL_CULL_FACE);
	glTranslatef(C3x, 1, C3z);
	glRotatef(180, 0, 1, 0);
	if (C3x == 57.5) {
		glRotatef(-90, 0, 1, 0);
	}
	if (C3x == 96.5) {
		glRotatef(90, 0, 1, 0);
	}
	glScalef(0.05, 0.05, 0.05);
	glBegin(GL_QUADS);
	glColor3f(1, 0.9, 0.1);
	Vrt(-40, 0, 15); Vrt(40, 0, 15); Vrt(40, -15, 15); Vrt(-40, -15, 15);  // left
	Vrt(-40, 0, -15); Vrt(40, 0, -15); Vrt(40, -15, -15); Vrt(-40, -15, -15);  // right
	glColor3f(1, 0.9, 0.8);
	Vrt(40, 0, -15); Vrt(40, 0, 15); Vrt(40, -15, 15); Vrt(40, -15, -15);  // back
	Vrt(-40, 0, -15); Vrt(-40, 0, 15); Vrt(-40, -15, 15); Vrt(-40, -15, -15);  // front
	glColor3f(1.0, 1.0, 1.0);  //������Ʈ
	Vrt(-41, -5, 15); Vrt(-41, -10, 15); Vrt(-41, -10, 10); Vrt(-41, -5, 10);  // left
	Vrt(-41, -5, -15); Vrt(-41, -5, -10); Vrt(-41, -10, -10); Vrt(-41, -10, -15); // right
	glColor3f(1.0, 0.1, 0.1);  //���϶���Ʈ
	Vrt(41, -5, 15); Vrt(41, -10, 15); Vrt(41, -10, 10); Vrt(41, -5, 10);  // left
	Vrt(41, -5, -15); Vrt(41, -5, -10); Vrt(41, -10, -10); Vrt(41, -10, -15); // right
	glColor3f(1, 1, 0);
	Vrt(-40, 0, 15); Vrt(-40, 0, -15); Vrt(40, 0, -15); Vrt(40, 0, 15);  // trunks
	Vrt(-10, 10, 15); Vrt(-10, 10, -15); Vrt(20, 10, -15); Vrt(20, 10, 15);  // roof
	glColor3f(0.8, 1, 1);
	Vrt(-20, 0, 15); Vrt(-10, 10, 15); Vrt(20, 10, 15); Vrt(25, 0, 15);  // window l
	Vrt(-20, 0, -15); Vrt(-10, 10, -15); Vrt(20, 10, -15); Vrt(25, 0, -15);  // window r
	glColor3f(0.8, 0.9, 0.9);
	Vrt(-10, 10, 15); Vrt(-20, 0, 15); Vrt(-20, 0, -15); Vrt(-10, 10, -15);  // windshield
	Vrt(20, 10, 15); Vrt(20, 10, -15); Vrt(25, 0, -15); Vrt(25, 0, 15);  // rear window
	glColor3f(1, 1, 0);
	Vrt(-40, -15, 15); Vrt(-40, -15, -15); Vrt(40, -15, -15); Vrt(40, -15, 15);  // bottom
	glEnd();

	// Render wheels using torus's with lighting on.
	glColor3f(0.3, 0.3, 0.3);
	Render_Wheel(-20, -15, 15);
	Render_Wheel(20, -15, 15);
	Render_Wheel(-20, -15, -15);
	Render_Wheel(20, -15, -15);
	glEnable(GL_CULL_FACE);
	glPopMatrix();
}

void Draw_Car4(void)  //4. �ʷ���
{
	glPushMatrix();
	glDisable(GL_CULL_FACE);
	glTranslatef(C4x, 1, C4z);
	if (C4x == 93.5) {
		glRotatef(90, 0, 1, 0);
	}
	if (C4x == 57.5) {
		glRotatef(90, 0, 1, 0);
	}
	glScalef(0.05, 0.05, 0.05);
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0.49);
	Vrt(-40, 0, 15); Vrt(40, 0, 15); Vrt(40, -15, 15); Vrt(-40, -15, 15);  // left
	Vrt(-40, 0, -15); Vrt(40, 0, -15); Vrt(40, -15, -15); Vrt(-40, -15, -15);  // right
	glColor3f(0.48, 0.98, 0);
	Vrt(40, 0, -15); Vrt(40, 0, 15); Vrt(40, -15, 15); Vrt(40, -15, -15);  // back
	Vrt(-40, 0, -15); Vrt(-40, 0, 15); Vrt(-40, -15, 15); Vrt(-40, -15, -15);  // front
	glColor3f(1.0, 1.0, 1.0);  //������Ʈ
	Vrt(-41, -5, 15); Vrt(-41, -10, 15); Vrt(-41, -10, 10); Vrt(-41, -5, 10);  // left
	Vrt(-41, -5, -15); Vrt(-41, -5, -10); Vrt(-41, -10, -10); Vrt(-41, -10, -15); // right
	glColor3f(1.0, 0.1, 0.1);  //���϶���Ʈ
	Vrt(41, -5, 15); Vrt(41, -10, 15); Vrt(41, -10, 10); Vrt(41, -5, 10);  // left
	Vrt(41, -5, -15); Vrt(41, -5, -10); Vrt(41, -10, -10); Vrt(41, -10, -15); // right
	glColor3f(0.59, 0.98, 0.59);
	Vrt(-40, 0, 15); Vrt(-40, 0, -15); Vrt(40, 0, -15); Vrt(40, 0, 15);  // trunks
	Vrt(-10, 10, 15); Vrt(-10, 10, -15); Vrt(20, 10, -15); Vrt(20, 10, 15);  // roof
	glColor3f(0.8, 1, 1);
	Vrt(-20, 0, 15); Vrt(-10, 10, 15); Vrt(20, 10, 15); Vrt(25, 0, 15);  // window l
	Vrt(-20, 0, -15); Vrt(-10, 10, -15); Vrt(20, 10, -15); Vrt(25, 0, -15);  // window r
	glColor3f(0.8, 0.9, 0.9);
	Vrt(-10, 10, 15); Vrt(-20, 0, 15); Vrt(-20, 0, -15); Vrt(-10, 10, -15);  // windshield
	Vrt(20, 10, 15); Vrt(20, 10, -15); Vrt(25, 0, -15); Vrt(25, 0, 15);  // rear window
	glColor3f(0.59, 0.98, 0.59);
	Vrt(-40, -15, 15); Vrt(-40, -15, -15); Vrt(40, -15, -15); Vrt(40, -15, 15);  // bottom
	glEnd();


	// Render wheels using torus's with lighting on.
	glColor3f(0.3, 0.3, 0.3);
	Render_Wheel(-20, -15, 15);
	Render_Wheel(20, -15, 15);
	Render_Wheel(-20, -15, -15);
	Render_Wheel(20, -15, -15);
	glEnable(GL_CULL_FACE);
	glPopMatrix();
}

void Draw_Car5(void)  //5. ������
{
	glPushMatrix();
	glDisable(GL_CULL_FACE);
	glTranslatef(C5x, 1, C5z);
	glRotatef(180, 0, 1, 0);
	if (C5x == 96.5) {
		glRotatef(90, 0, 1, 0);
	}
	glScalef(0.05, 0.05, 0.05);
	glBegin(GL_QUADS);
	glColor3f(0.933333, 0.509804, 0.933333);
	Vrt(-40, 0, 15); Vrt(40, 0, 15); Vrt(40, -15, 15); Vrt(-40, -15, 15);  // left
	Vrt(-40, 0, -15); Vrt(40, 0, -15); Vrt(40, -15, -15); Vrt(-40, -15, -15);  // right
	glColor3f(0.866667, 0.627451, 0.866667);
	Vrt(40, 0, -15); Vrt(40, 0, 15); Vrt(40, -15, 15); Vrt(40, -15, -15);  // back
	Vrt(-40, 0, -15); Vrt(-40, 0, 15); Vrt(-40, -15, 15); Vrt(-40, -15, -15);  // front
	glColor3f(1.0, 1.0, 1.0);  //������Ʈ
	Vrt(-41, -5, 15); Vrt(-41, -10, 15); Vrt(-41, -10, 10); Vrt(-41, -5, 10);  // left
	Vrt(-41, -5, -15); Vrt(-41, -5, -10); Vrt(-41, -10, -10); Vrt(-41, -10, -15); // right
	glColor3f(1.0, 0.1, 0.1);  //���϶���Ʈ
	Vrt(41, -5, 15); Vrt(41, -10, 15); Vrt(41, -10, 10); Vrt(41, -5, 10);  // left
	Vrt(41, -5, -15); Vrt(41, -5, -10); Vrt(41, -10, -10); Vrt(41, -10, -15); // right
	glColor3f(0.627451, 0.12549, 0.941176);
	Vrt(-40, 0, 15); Vrt(-40, 0, -15); Vrt(40, 0, -15); Vrt(40, 0, 15);  // trunks
	Vrt(-10, 10, 15); Vrt(-10, 10, -15); Vrt(20, 10, -15); Vrt(20, 10, 15);  // roof
	glColor3f(0.8, 1, 1);
	Vrt(-20, 0, 15); Vrt(-10, 10, 15); Vrt(20, 10, 15); Vrt(25, 0, 15);  // window l
	Vrt(-20, 0, -15); Vrt(-10, 10, -15); Vrt(20, 10, -15); Vrt(25, 0, -15);  // window r
	glColor3f(0.8, 0.9, 0.9);
	Vrt(-10, 10, 15); Vrt(-20, 0, 15); Vrt(-20, 0, -15); Vrt(-10, 10, -15);  // windshield
	Vrt(20, 10, 15); Vrt(20, 10, -15); Vrt(25, 0, -15); Vrt(25, 0, 15);  // rear window
	glColor3f(0.627451, 0.12549, 0.941176);
	Vrt(-40, -15, 15); Vrt(-40, -15, -15); Vrt(40, -15, -15); Vrt(40, -15, 15);  // bottom
	glEnd();

	// Render wheels using torus's with lighting on.
	glColor3f(0.3, 0.3, 0.3);
	Render_Wheel(-20, -15, 15);
	Render_Wheel(20, -15, 15);
	Render_Wheel(-20, -15, -15);
	Render_Wheel(20, -15, -15);
	glEnable(GL_CULL_FACE);
	glPopMatrix();
}

///////////////���� ������///////////////////
void Moving_Car() {
	//1. �Ķ���
	if (C1z > 101.5) {
		C1z -= 0.1;
	}
	if (C1z <= 101.5) {
		C1z = 101.5;
		C1x -= 0.1;
	}
	if (C1x <= 1) {
		C1x = 60.5;
		C1z = 270;
	}
	//2. ������
	if (C2z < 250) {
		C2z += 0.1;
	}
	if (250 <= C2z && C2x > 57.5) {
		C2z = 250.5;
		C2x -= 0.1;
	}
	if (C2x <= 57.5) {
		C2x = 57.5;
		C2z += 0.1;
	}
	if (C2z >= 270) {
		C2x = 93.5;
		C2z = 0;
	}
	//3. ����� 
	if (C3x < 57.5) {
		C3x += 0.1;
	}
	if (57.5 <= C3x && C3z < 202.5 && C3x < 96.5) {
		C3x = 57.5;
		C3z += 0.1;
	}
	if (C3z >= 202.5 && C3x < 96.5) {
		C3z = 202.5;
		C3x += 0.1;
	}
	if (96.5 <= C3x && C3z <= 202.5 && C3z > 78.5) {
		C3x = 96.5;
		C3z -= 0.1;
	}
	if (C3z <= 78.5 && C3x >= 96.5 && C3x < 180) {
		C3z = 78.5;
		C3x += 0.1;
	}
	if (C3x >= 180) {
		C3z = 187.5;
		C3x = 0;
	}
	//4. �ʷ���
	if (C4x > 93.5) {
		C4x -= 0.1;
	}
	if (C4x <= 93.5 && C4z < 199.5) {
		C4x = 93.5;
		C4z += 0.1;
	}
	if (C4z >= 199.5&&C4x <= 93.5 && C4x > 57.5) {
		C4z = 199.5;
		C4x -= 0.1;
	}
	if (C4x <= 57.5 && C4z >= 199.5 && C4z < 270) {
		C4x = 57.5;
		C4z += 0.1;
	}
	if (C4z >= 270 && C4x <= 57.5) {
		C4z = 110.5;
		C4x = 180;
	}
	//5. ������
	if (C5x < 96.5) {
		C5x += 0.1;
	}
	if (C5x >= 96.5 && C5z <= 78.5 && C5z > 0) {
		C5x = 96.5;
		C5z -= 0.1;
	}
	if (C5z <= 0 && C5x <= 96.5) {
		C5z = 78.5;
		C5x = 0;
	}
}

void timer(int value) {
	glutPostRedisplay();      //�����츦 �ٽ� �׸����� ��û
	glutTimerFunc(10, timer, 0); //���� Ÿ�̸� �̺�Ʈ�� 10�и�����Ʈ ��  ȣ���.
}

////////////////////////////////////////����� ����� �Լ�///////////////////////////////////////////
void createCylinder(GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat radius, GLfloat h)
{
	/* function createCyliner()
	������� �߽� x,y,z��ǥ, ������, ���̸� �޾� ������� �����ϴ� �Լ�(+z�������� ������ �þ)
	centerx : ����� ���� �߽� x��ǥ
	centery : ����� ���� �߽� y��ǥ
	centerz : ����� ���� �߽� z��ǥ
	radius : ������� ������
	h : ������� ����
	*/
	GLfloat x, y, angle;

	glBegin(GL_TRIANGLE_FAN);           //������� ����
	glNormal3f(0.0f, 0.0f, -1.0f);
	glColor3f(0.466667, 0.533333, 0.6);
	Vrt(centerx, centery, centerz); //<p></p>

	for (angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI / 8.0f))
	{
		x = centerx + radius * sin(angle);
		y = centery + radius * cos(angle);
		glNormal3f(0.0f, 0.0f, -1.0f);
		Vrt(x, y, centerz);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);            //������� ����

	for (angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI / 8.0f))
	{
		x = centerx + radius * sin(angle);
		y = centery + radius * cos(angle);
		glNormal3f(sin(angle), cos(angle), 0.0f);
		Vrt(x, y, centerz);
		Vrt(x, y, centerz + h);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);           //������� �ظ�

	glNormal3f(0.0f, 0.0f, 1.0f);
	Vrt(centerx, centery, centerz + h);

	for (angle = (2.0f*GL_PI); angle > 0.0f; angle -= (GL_PI / 8.0f))
	{
		x = centerx + radius * sin(angle);
		y = centery + radius * cos(angle);
		glNormal3f(0.0f, 0.0f, 1.0f);
		Vrt(x, y, centerz + h);
	}
	glEnd();
}

/////////////////////////////////////////���ε�//////////////////////////////////////
void street_lights(float Streetr, float Streetx, float Streetz) {
	glPushMatrix();
	glDisable(GL_CULL_FACE);
	glTranslatef(Streetx, 3.8, Streetz);  //���ε��� ��ġ ��ǥ
	glRotatef(90, 1, 0, 0);
	glRotatef(Streetr, 0, 0, 1);
	glScalef(0.05, 0.05, 0.05);
	createCylinder(-30, -30, -30, 2, 80);   //����� �κ�
	createCylinder(-30, -30, -35.1, 3, 10);
	createCylinder(-30, -30, 50, 5, 20);
	glBegin(GL_QUADS);   //����� ����� �κ��� �����ϴ� ���簢�� �����
	glColor3f(0.827451, 0.827451, 0.827451);
	Vrt(-33, -70, -35); Vrt(-33, -27, -35); Vrt(-27, -27, -35); Vrt(-27, -70, -35);
	Vrt(-33, -70, -37); Vrt(-33, -27, -37); Vrt(-27, -27, -37); Vrt(-27, -70, -37);
	Vrt(-33, -27, -35); Vrt(-27, -27, -35); Vrt(-27, -27, -37); Vrt(-33, -27, -37);
	Vrt(-27, -27, -37); Vrt(-27, -27, -35); Vrt(-27, -70, -35); Vrt(-27, -70, -37);
	Vrt(-33, -27, -37); Vrt(-33, -27, -35); Vrt(-33, -70, -35); Vrt(-33, -70, -37);
	glEnd();
	createCylinder(-30, -71, -37.1, 5, 3);  //����κ�
	glEnable(GL_CULL_FACE);
	glPopMatrix();
}

///////////////////////////////���ε� ��ġ/////////////////////////////
void SL_location() {
	glPushMatrix();
	////// �Ĺ����� ��
	for (Streetz = 2; Streetz <= 195; Streetz += 15) {
		if (Streetz == 77) {
			Streetz = 92;
		}
		street_lights(90, 90, Streetz);
	}
	for (Streetz = 215; Streetz <= 250; Streetz += 15) {
		street_lights(90, 90, Streetz);
	}
	for (Streetz = 7; Streetz <= 240; Streetz += 15) {
		if (Streetz == 74.5) {
			Streetz = 84.5;
		}
		if (Streetz == 112) {
			Streetz = 127;
		}
		street_lights(-90, 100, Streetz);
	}
	///// ���� ������ ��
	for (Streetx = 102; Streetx <= 180; Streetx += 15) {
		street_lights(180, Streetx, 72);
	}
	for (Streetx = 112.5; Streetx <= 180; Streetx += 15) {
		street_lights(0, Streetx, 82);
	}
	///// �п���� ��
	for (Streetx = 102; Streetx <= 180; Streetx += 15) {
		street_lights(180, Streetx, 107);
	}
	for (Streetx = 112.5; Streetx <= 180; Streetx += 15) {
		if (Streetx == 142.5) {
			Streetx = 157.5;
		}
		street_lights(0, Streetx, 117);
	}
	///// ������ ������ ��
	for (Streetx = 64; Streetx <= 130; Streetx += 15) {
		if (Streetx == 94) {
			Streetx = 109;
		}
		street_lights(180, Streetx, 247);
	}
	for (Streetx = 74.5; Streetx <= 140; Streetx += 15) {
		street_lights(0, Streetx, 257);
	}
	///// �ָ� ����
	for (Streetx = 64; Streetx <= 90; Streetx += 15) {
		street_lights(180, Streetx, 196);
	}
	for (Streetx = 74.5; Streetx <= 90; Streetx += 15) {
		street_lights(0, Streetx, 206);
	}
	///// �״Ͻ��� ����  
	for (Streetx = 10; Streetx <= 50; Streetx += 15) {
		street_lights(180, Streetx, 181);
	}
	for (Streetx = 5.5; Streetx <= 60; Streetx += 15) {
		street_lights(0, Streetx, 191);
	}
	///// �������� ��
	for (Streetz = 112; Streetz <= 270; Streetz += 15) {
		if (Streetz == 187) {
			Streetz = 202;
		}
		street_lights(90, 54, Streetz);
	}
	for (Streetz = 102; Streetz <= 240; Streetz += 15) {
		street_lights(-90, 64, Streetz);
	}
	///// �缺�� ����� 
	for (Streetz = 213; Streetz <= 250; Streetz += 15) {
		street_lights(-90, 138, Streetz);
	}
	///// ���� �ǹ� ���� ª�� ��
	for (Streetx = 131; Streetx <= 150; Streetx += 15) {
		street_lights(180, Streetx, 200);
	}
	///// ���� �� �밢�� ��
	Streetx = 139.5;
	for (Streetz = 121; Streetz <= 210; Streetz += 15) {
		street_lights(81, Streetx, Streetz);
		Streetx += 1.56;
	}
	Streetx = 150.5;
	for (Streetz = 125.5; Streetz <= 180; Streetz += 15) {
		street_lights(-99, Streetx, Streetz);
		Streetx += 1.56;
	}
	glPopMatrix();
}


//////////////////////////////Tree///////////////////////////////////

//�� ������ ����� ����� �Լ�
void TcreateCylinder(GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat radius, GLfloat h, GLfloat TR, GLfloat TG, GLfloat TB)
{
	/* function TcreateCyliner()
	������� �߽� x,y,z��ǥ, ������, ���̸� �޾� ������� �����ϴ� �Լ�(+z�������� ������ �þ)
	centerx : ����� ���� �߽� x��ǥ
	centery : ����� ���� �߽� y��ǥ
	centerz : ����� ���� �߽� z��ǥ
	radius : ������� ������
	h : ������� ����
	TR ; RED
	TG : GREEN
	TB : BLUE
	*/
	GLfloat x, y, angle;

	glBegin(GL_TRIANGLE_FAN);           //������� ����
	glNormal3f(0.0f, 0.0f, -1.0f);
	glColor3f(TR, TG, TB);
	Vrt(centerx, centery, centerz); //<p></p>

	for (angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI / 8.0f))
	{
		x = centerx + radius * sin(angle);
		y = centery + radius * cos(angle);
		glNormal3f(0.0f, 0.0f, -1.0f);
		Vrt(x, y, centerz);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);            //������� ����

	for (angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI / 8.0f))
	{
		x = centerx + radius * sin(angle);
		y = centery + radius * cos(angle);
		glNormal3f(sin(angle), cos(angle), 0.0f);
		Vrt(x, y, centerz);
		Vrt(x, y, centerz + h);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);           //������� �ظ�

	glNormal3f(0.0f, 0.0f, 1.0f);
	Vrt(centerx, centery, centerz + h);

	for (angle = (2.0f*GL_PI); angle > 0.0f; angle -= (GL_PI / 8.0f))
	{
		x = centerx + radius * sin(angle);
		y = centery + radius * cos(angle);
		glNormal3f(0.0f, 0.0f, 1.0f);
		Vrt(x, y, centerz + h);
	}
	glEnd();
}

void drawTree(GLfloat TX, GLfloat TY, GLfloat TZ) {  //���� �׸��� �Լ�
	glPushMatrix();

	glTranslatef(TX, TY, TZ);
	glScalef(0.6, 0.6, 0.6);

	glPushMatrix();  //���� ���
	glRotatef(-90, 1, 0, 0);
	TcreateCylinder(0, 0, 0, 0.2, 2.1, 0.956863, 0.643137, 0.376471);
	glPopMatrix();

	glPushMatrix();  //��հ� ���� ���� �����
	glRotatef(-90, 1, 0, 0);
	TcreateCylinder(0, 0, 2, 1, 0.0001, 0, 1, 0.498039);
	glPopMatrix();

	glPushMatrix();   //�ϴ� ��
	glTranslatef(0, 2, 0);
	glRotatef(-90, 1, 0, 0);
	glColor3f(0, 1, 0.498039);
	glutSolidCone(1, 2, 100, 1);
	glPopMatrix();

	glPushMatrix();  //�ߴ� ��
	glTranslatef(0, 3, 0);
	glRotatef(-90, 1, 0, 0);
	glScalef(0.9, 0.9, 0.9);
	glColor3f(0, 1, 0.55);
	glutSolidCone(1, 2, 100, 1);
	glPopMatrix();

	glPushMatrix();  //��� ��
	glTranslatef(0, 4, 0);
	glRotatef(-90, 1, 0, 0);
	glScalef(0.8, 0.8, 0.8);
	glColor3f(0, 1, 0.6);
	glutSolidCone(1, 2, 100, 1);
	glPopMatrix();

	glPopMatrix();
}

void Tree_location() {    //�������� ��ġ ���� �Լ�
	glPushMatrix();

	drawTree(30, 0, 3);
	drawTree(18, 0, 7);
	drawTree(46, 0, 22);
	drawTree(33, 0, 46);
	drawTree(5, 0, 61);
	drawTree(27, 0, 31);
	drawTree(39, 0, 50);
	drawTree(42, 0, 19);
	drawTree(15, 0, 28);
	drawTree(23, 0, 42);
	drawTree(2, 0, 10);
	drawTree(25, 0, 59);
	drawTree(35, 0, 67);

	drawTree(125, 0, 40);
	drawTree(160, 0, 30);
	drawTree(170, 0, 11);
	drawTree(131, 0, 3);
	drawTree(156, 0, 21);
	drawTree(179, 0, 43);
	drawTree(144, 0, 29);
	drawTree(153, 0, 38);
	drawTree(167, 0, 42);
	drawTree(135, 0, 8);
	drawTree(129, 0, 15);
	drawTree(148, 0, 13);
	drawTree(162, 0, 6);

	drawTree(101, 0, 71);
	drawTree(103, 0, 71);
	drawTree(105, 0, 71);
	drawTree(107, 0, 71);
	drawTree(109, 0, 71);
	drawTree(111, 0, 71);
	drawTree(113, 0, 71);
	drawTree(115, 0, 71);
	drawTree(117, 0, 71);
	drawTree(119, 0, 71);
	drawTree(109, 0, 61);
	drawTree(111, 0, 61);
	drawTree(113, 0, 61);
	drawTree(115, 0, 61);
	drawTree(117, 0, 61);
	drawTree(119, 0, 61);

	for (int i = 49; i > 0; i -= 2) {
		drawTree(i, 0, 73);
	}

	for (int i = 19; i > 0; i -= 2) {
		drawTree(i, 0, 81);
	}

	for (int i = 34; i > 0; i -= 2) {
		drawTree(i, 0, 99);
	}

	drawTree(3, 0, 97);
	drawTree(7, 0, 86);
	drawTree(5, 0, 83);
	drawTree(13, 0, 87);
	drawTree(18, 0, 92);
	drawTree(9, 0, 91);

	for (int i = 50; i > 8; i -= 2) {
		if (i == 32)
			i = 23;
		drawTree(i, 0, 107);
	}

	for (int i = 123; i > 107; i -= 2) {
		drawTree(50, 0, i);
	}

	for (int i = 31; i > 0; i -= 2) {
		drawTree(i, 0, 193);
	}

	drawTree(30, 0, 203);
	drawTree(18, 0, 207);
	drawTree(5, 0, 261);
	drawTree(27, 0, 231);
	drawTree(15, 0, 228);
	drawTree(23, 0, 242);
	drawTree(2, 0, 210);
	drawTree(25, 0, 259);

	for (int i = 246; i > 148; i -= 2) {
		if (i == 172)
			i = 162;
		drawTree(101, 0, i);
	}

	for (int i = 109; i > 101; i -= 2) {
		drawTree(i, 0, 246);
	}

	for (int i = 246; i > 184; i -= 2) {
		drawTree(109, 0, i);
	}

	for (int i = 129; i > 107; i -= 2) {
		drawTree(i, 0, 184);
	}

	drawTree(125, 0, 172);
	drawTree(105, 0, 183);
	drawTree(111, 0, 175);
	drawTree(105, 0, 150);
	drawTree(108, 0, 153);
	drawTree(121, 0, 169);
	drawTree(126, 0, 181);

	for (int i = 183; i > 138; i -= 2) {
		if (i == 157)
			i = 149;
		drawTree(i, 0, 228);
	}

	for (int i = 228; i > 200; i -= 2) {
		drawTree(157, 0, i);
	}

	for (int i = 228; i > 208; i -= 2) {
		drawTree(149, 0, i);
	}

	for (int i = 148; i > 138; i -= 2) {
		drawTree(i, 0, 209);
	}

	for (int i = 147; i > 130; i -= 2) {
		drawTree(i, 0, 199);
	}

	//�ָ� �ֺ�

	drawTree(86, 0, 170);
	drawTree(87, 0, 184);
	drawTree(86, 0, 162);
	drawTree(80, 0, 168);
	drawTree(74, 0, 161);
	drawTree(67, 0, 164);
	drawTree(72, 0, 172);
	drawTree(74, 0, 174);
	drawTree(66, 0, 178);
	drawTree(73, 0, 188);
	drawTree(74, 0, 183);
	drawTree(67, 0, 184);
	drawTree(81, 0, 189);
	drawTree(69, 0, 192);
	drawTree(84, 0, 195);

	glPopMatrix();
}

void Goal1() {  //��� �׸��� �Լ�
	glPushMatrix();
	glTranslatef(73.5, -2, 65);
	glScalef(0.3, 0.3, 0.3);

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	TcreateCylinder(-19.5, 0, 0, 0.5, 13, 0.9, 0.9, 0.9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 13, 0);
	glRotatef(-90, 0, 1, 0);
	TcreateCylinder(0, 0, 0, 0.5, 20, 0.9, 0.9, 0.9);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	TcreateCylinder(-0.5, 0, 0, 0.5, 13, 0.9, 0.9, 0.9);
	glPopMatrix();

	glPopMatrix();
}

void Goal2() {
	glPushMatrix();
	glTranslatef(73.5, -2, 20);
	glScalef(0.3, 0.3, 0.3);

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	TcreateCylinder(-19.5, 0, 0, 0.5, 13, 0.9, 0.9, 0.9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 13, 0);
	glRotatef(-90, 0, 1, 0);
	TcreateCylinder(0, 0, 0, 0.5, 20, 0.9, 0.9, 0.9);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	TcreateCylinder(-0.5, 0, 0, 0.5, 13, 0.9, 0.9, 0.9);
	glPopMatrix();

	glPopMatrix();
}
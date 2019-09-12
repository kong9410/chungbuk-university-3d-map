/*********************************************************************************************************************

* �ۼ��� : ����ö, ����ȣ

* ���ϸ� : source.cpp

* ���� : ���콺 ����, ���÷���, ����, �����Լ� ���� ����� �ڵ�.

**********************************************************************************************************************/

#include<stdio.h>
#include<gl/glut.h>
#include<windows.h>
#include"Texture.h"
#include"model.h"
#include"campus.h"
#include "Sun.h"
#include"keyboardfunction.h"
//#include"controls.cpp"

void Display();  //�Լ� ����

//Camera camera;
float cx = 92, cy = 20, cz = 100;
float rx = 0.0, ry = 0.0, rz = 0.1;
float cameraX = -90, cameraY = -5, cameraZ = -50;
unsigned int ID;
bool night = false;

GLdouble eyeX = 0, eyeY = 1.0, eyeZ = 0;
GLdouble centerX = 0.0, centerY = -1.0, centerZ = 0.0;
GLdouble upX = 0, upY = 0.0, upZ = 0;

//GLfloat sky_color[] = { 0.1, 0.4, 0.5, 0.5 };  //�� �ϴ� ��
//GLfloat dark_color[] = { 0.0, 0.0, 0.1, 1.0 };  //�� �ϴ� ��

void Sound() {    //���� �Լ�
	sndPlaySound("street.wav", SND_ASYNC | SND_LOOP);

}

//�ʱ�ȭ
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glColorMaterial(GL_AMBIENT_AND_DIFFUSE, GL_FRONT);
	glColorMaterial(GL_SPECULAR, GL_FRONT);
	glShadeModel(GL_SMOOTH);   //�ε巴��
	glEnable(GL_COLOR_MATERIAL);   //���� ������ 
	glEnable(GL_LIGHTING);    //����Ʈ ON
	glEnable(GL_CULL_FACE);    //�ܸ� ������ ON

	//�ٸ����
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	printf("Initialize Complete\n");
}

/*
// ���÷��� �籸�� �̺�Ʈ
void reshape(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);                           // ������� ����
   glLoadIdentity();                                    // �׵���ķ� �ʱ�ȭ
   if (h == 0)
	  h = 1;
   gluPerspective(45.0f, (float)w / (float)h, 0.1, 100.0);         // ���� ����
   glMatrixMode(GL_MODELVIEW);                              // �𵨺���� ����
   glLoadIdentity();                                    // �׵���ķ� �ʱ�ȭ
}
*/

//���콺 Ŭ��
void Mouse(int button, int state, int x, int y)
{
	x_click = x;
	y_click = y;

	new_mouse = 1;
}

//���콺 ���� �̵�
void Motion(int x, int y)
{
	float turn_del, tipp_del, x_del, y_del;

	static int c = 0, x_sav, y_sav;
	static float turn_save = 0.0, tipp_save = 0.0;

	// printf ("   Motion:  %5d ->   x = %5d, y = %5d.\n", ++c, x, y);

	if (new_mouse) {
		new_mouse = 0;
		x_sav = x_click;
		y_sav = y_click;
	}

	if (mouse_rot) {

		turn_del = x - x_sav;
		turn += turn_del;

		tipp_del = y - y_sav;
		tipp += tipp_del;

	}
	else if (mouse_trn) {

		x_del = float(x - x_sav) * 0.01;
		xtm += x_del;

		y_del = float(y - y_sav) * 0.01;
		ytm -= y_del;

	}

	x_sav = x;
	y_sav = y;

	glutPostRedisplay();
}


void Init_Lights(void)  //����Ʈ ���� �Լ�
{
	GLfloat light_ambient[] = { AX, AY, AZ, 1.0 };    //���� ���� �� ��� ����. LIGHT 2
	GLfloat light_diffuse[] = { 0.3, 0.3, 0.3, 1.0f };
	GLfloat light_specular[] = { 1, 1, 1, 1.0 };
	GLfloat light_position[] = { 2.0, 3.0, 2.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);
	glEnable(GL_LIGHT2);

	GLfloat light2_position[] = { 80, 1.0, 80.0, 1.0 };   //�⺻������ ������� �����ִ� ����. LIGHT 3
	GLfloat light2_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	glLightfv(GL_LIGHT3, GL_AMBIENT, light2_ambient);
	glLightfv(GL_LIGHT3, GL_POSITION, light2_position);
	glEnable(GL_LIGHT3);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
}


void Display() {   //ȭ��. ���÷��� �Լ�
	static float x = 2.0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(bgColR, bgColG, bgColB, 0.0);  //����� ���� ���� �㿡 ���� ��ȭ�Ѵ�
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0f, 1.0f, 2000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	moveMeFlat(deltaMove);
	angle += deltaAngle;
	orientMe(angle);

	glRotatef(tipp, 1, 0, 0);       // Rotate around world    vertical axis.

	drawCampus();         //ķ�۽��׸���

	glPushMatrix();  //���� 1~5 �׸���
	Draw_Car1();
	Draw_Car2();
	Draw_Car3();
	Draw_Car4();
	Draw_Car5();
	glPopMatrix();

	Goal1();
	Goal2();

	Tree_location();  //��ġ�� ������ �׸���

	Moving_Car();         //�ڵ��� �̵� ���

	SL_location();         //��ġ�� ���ε� �׸���

	Init_Lights();         //������ ����

	glutSwapBuffers();
}


int main(int argc, char **argv) {  //�����Լ�
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("OPENGL PROJECT");
	initTexture();                  //�ؽ��� �ҷ�����
	initRendering();                //������

	glutReshapeFunc(handleResize);      //�����̵�
	glutKeyboardFunc(pressKey);         //Ű����
	glutKeyboardUpFunc(releaseKey);      //Ű�ø�
	glutIdleFunc(renderScene);         //Ű�������� �ٲ� ��ǥ ��ȯ
	glutDisplayFunc(Display);         //���÷���
	glutMouseFunc(Mouse);            //���콺 Ŭ��
	glutMotionFunc(Motion);            //���콺 ���� �̵�
	glutTimerFunc(0, timer, 0);          //������ ������ �ð� ����
	glutTimerFunc(10, update, 0);       //���� �� �ð� ����
	Sound();                                   //���� ON
	glutMainLoop();
	return 0;
}
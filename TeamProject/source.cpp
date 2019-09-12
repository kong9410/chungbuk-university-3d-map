/*********************************************************************************************************************

* 작성자 : 공민철, 최진호

* 파일명 : source.cpp

* 설명 : 마우스 조작, 디스플레이, 조명, 메인함수 등이 저장된 코드.

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

void Display();  //함수 정의

//Camera camera;
float cx = 92, cy = 20, cz = 100;
float rx = 0.0, ry = 0.0, rz = 0.1;
float cameraX = -90, cameraY = -5, cameraZ = -50;
unsigned int ID;
bool night = false;

GLdouble eyeX = 0, eyeY = 1.0, eyeZ = 0;
GLdouble centerX = 0.0, centerY = -1.0, centerZ = 0.0;
GLdouble upX = 0, upY = 0.0, upZ = 0;

//GLfloat sky_color[] = { 0.1, 0.4, 0.5, 0.5 };  //낮 하늘 색
//GLfloat dark_color[] = { 0.0, 0.0, 0.1, 1.0 };  //밤 하늘 색

void Sound() {    //사운드 함수
	sndPlaySound("street.wav", SND_ASYNC | SND_LOOP);

}

//초기화
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glColorMaterial(GL_AMBIENT_AND_DIFFUSE, GL_FRONT);
	glColorMaterial(GL_SPECULAR, GL_FRONT);
	glShadeModel(GL_SMOOTH);   //부드럽게
	glEnable(GL_COLOR_MATERIAL);   //색깔 나오게 
	glEnable(GL_LIGHTING);    //라이트 ON
	glEnable(GL_CULL_FACE);    //단면 렌더링 ON

	//앨리어싱
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	printf("Initialize Complete\n");
}

/*
// 디스플레이 재구성 이벤트
void reshape(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);                           // 투영행렬 선택
   glLoadIdentity();                                    // 항등행렬로 초기화
   if (h == 0)
	  h = 1;
   gluPerspective(45.0f, (float)w / (float)h, 0.1, 100.0);         // 원근 투영
   glMatrixMode(GL_MODELVIEW);                              // 모델뷰행렬 선택
   glLoadIdentity();                                    // 항등행렬로 초기화
}
*/

//마우스 클릭
void Mouse(int button, int state, int x, int y)
{
	x_click = x;
	y_click = y;

	new_mouse = 1;
}

//마우스 상하 이동
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


void Init_Lights(void)  //라이트 관련 함수
{
	GLfloat light_ambient[] = { AX, AY, AZ, 1.0 };    //낮과 밤의 맵 밝기 조절. LIGHT 2
	GLfloat light_diffuse[] = { 0.3, 0.3, 0.3, 1.0f };
	GLfloat light_specular[] = { 1, 1, 1, 1.0 };
	GLfloat light_position[] = { 2.0, 3.0, 2.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);
	glEnable(GL_LIGHT2);

	GLfloat light2_position[] = { 80, 1.0, 80.0, 1.0 };   //기본적으로 어느정도 밝혀주는 조명. LIGHT 3
	GLfloat light2_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	glLightfv(GL_LIGHT3, GL_AMBIENT, light2_ambient);
	glLightfv(GL_LIGHT3, GL_POSITION, light2_position);
	glEnable(GL_LIGHT3);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
}


void Display() {   //화면. 디스플레이 함수
	static float x = 2.0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(bgColR, bgColG, bgColB, 0.0);  //배경의 색이 낮과 밤에 따라 변화한다
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0f, 1.0f, 2000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	moveMeFlat(deltaMove);
	angle += deltaAngle;
	orientMe(angle);

	glRotatef(tipp, 1, 0, 0);       // Rotate around world    vertical axis.

	drawCampus();         //캠퍼스그리기

	glPushMatrix();  //차량 1~5 그리기
	Draw_Car1();
	Draw_Car2();
	Draw_Car3();
	Draw_Car4();
	Draw_Car5();
	glPopMatrix();

	Goal1();
	Goal2();

	Tree_location();  //배치한 나무들 그리기

	Moving_Car();         //자동차 이동 명령

	SL_location();         //배치한 가로등 그리기

	Init_Lights();         //라이팅 실행

	glutSwapBuffers();
}


int main(int argc, char **argv) {  //메인함수
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("OPENGL PROJECT");
	initTexture();                  //텍스쳐 불러오기
	initRendering();                //렌더링

	glutReshapeFunc(handleResize);      //리쉐이딩
	glutKeyboardFunc(pressKey);         //키누름
	glutKeyboardUpFunc(releaseKey);      //키올림
	glutIdleFunc(renderScene);         //키눌렀을때 바뀐 좌표 전환
	glutDisplayFunc(Display);         //디스플레이
	glutMouseFunc(Mouse);            //마우스 클릭
	glutMotionFunc(Motion);            //마우스 상하 이동
	glutTimerFunc(0, timer, 0);          //차량의 움직임 시간 관장
	glutTimerFunc(10, update, 0);       //낮과 밤 시간 관장
	Sound();                                   //사운드 ON
	glutMainLoop();
	return 0;
}
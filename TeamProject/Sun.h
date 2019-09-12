/*********************************************************************************************************************

* �ۼ��� : ����ö, ����ȣ

* ���ϸ� : Sun.h

* ���� : ��ü ���� ���� ���� �����ϴ� �ڵ�

**********************************************************************************************************************/

#pragma once
#include<iostream>
#include<stdlib.h>

#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else 
#include<GL/glut.h>
#endif

using namespace std;

float ballX = -0.8f;  //�¾��� ��ǥ x,y,z
float ballY = -0.3f;
float ballZ = -1.2f;
float colR = 3.0;   //�¾��� ���� R,G,B
float colG = 1.5;
float colB = 1.0;
float bgColR = 0.0;  //����� ���� R,G,B
float bgColG = 0.0;
float bgColB = 0.0;

float AX = 0.0;   //���� ������ ���� ��ǥ x,y,z
float AY = 0.0;
float AZ = 0.0;

static int flag = 1;  //flag�� ���� ���� �� ����

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT5); //Enable light #5
	glEnable(GL_LIGHT6); //Enable light #6
	glEnable(GL_NORMALIZE); //Automatically normalize normals
}

//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}

//float _angle = 30.0f;
void update(int value) {

	if (ballX > 0.9f)  //��->��ħ
	{
		ballX = -0.8f;
		ballY = -0.3f;
		flag = 1;
		colR = 2.0;
		colG = 1.50;
		colB = 1.0;

		bgColB = 0.0;
		AX = 0;
		AY = 0;
		AZ = 0;
	}

	if (flag)       //��ħ->����
	{
		ballX += 0.001f;
		ballY += 0.0007f;
		colR -= 0.001;
		colB += 0.005;

		bgColB += 0.001;
		AX += 0.001;
		AY += 0.001;
		AZ += 0.001;
		if (ballX > 0.01)
		{
			flag = 0;

		}
	}
	if (!flag)    //����->��
	{
		ballX += 0.001f;
		ballY -= 0.0007f;
		colR += 0.001;
		colB -= 0.01;

		bgColB -= 0.001;
		AX -= 0.001;
		AY -= 0.001;
		AZ -= 0.001;
		if (ballX < -0.3)
		{
			flag = 1;

		}
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(10, update, 0);
}
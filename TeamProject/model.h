/*********************************************************************************************************************

* �ۼ��� : ����ö, ����ȣ

* ���ϸ� : Model.h

* ���� : ����, ���ε�, ���� ���� �𵨸��ϰ� ��ġ�ϴ� ���� ���Ǵ� ������ �Լ����� ����

**********************************************************************************************************************/

#pragma once
#ifndef MODEL_H
#define MODEL_H


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <GL/glut.h>

#define Vrt glVertex3f
#define GL_PI 3.1415f

float C1z = 270;    //���� 1~5 ������ x,y ��ǥ
float C1x = 60.5;
float C2z = 0;
float C2x = 93.5;
float C3z = 187.5;
float C3x = 0;
float C4z = 110.5;
float C4x = 180;
float C5z = 78.5;
float C5x = 0;

float Streetr;  //���ε��� ȸ���� z,x ��ǥ
float Streetz;
float Streetx;

int proj = 1, new_mouse = 0, mouse_rot = 1, mouse_trn = 0;  //���콺�� ȭ�� ȸ���� �� ���Ǵ� ����

float turn = 50.0, tipp = 30.0, twst = 0.0, x_click = 0, y_click = 0, xtm = 0.0, ytm = 0.0,
scl = 1.0, xcr = 0.0;

void Draw_Car1(void);  //���� 1~5
void Draw_Car2(void);
void Draw_Car3(void);
void Draw_Car4(void);
void Draw_Car5(void);
void Moving_Car();  //���� 1~5���� ������

void timer(int value);  //�ð��� ���� ȭ�� ����� �Լ�

void createCylinder(GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat radius, GLfloat h);  //����� ����� �Լ�
void TcreateCylinder(GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat radius, GLfloat h, GLfloat TR, GLfloat TG, GLfloat TB);  //����տ� ������ ����� �Լ�
void street_lights(float Streetr, float Streetx, float Streetz); //���ε� �𵨸� �Լ�
void SL_location();  //���ε� ��ġ �Լ�

void drawTree(GLfloat TX, GLfloat TY, GLfloat TZ);  //���� �𵨸� �Լ�
void Tree_location();  //���� ��ġ �Լ�

void Goal1();  //���� ���
void Goal2();

#endif // !MODEL_H
/*********************************************************************************************************************

* 작성자 : 공민철, 최진호

* 파일명 : Model.h

* 설명 : 나무, 가로등, 차량 등을 모델링하고 배치하는 데에 사용되는 변수와 함수들을 정의

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

float C1z = 270;    //차량 1~5 까지의 x,y 좌표
float C1x = 60.5;
float C2z = 0;
float C2x = 93.5;
float C3z = 187.5;
float C3x = 0;
float C4z = 110.5;
float C4x = 180;
float C5z = 78.5;
float C5x = 0;

float Streetr;  //가로등의 회전과 z,x 좌표
float Streetz;
float Streetx;

int proj = 1, new_mouse = 0, mouse_rot = 1, mouse_trn = 0;  //마우스로 화면 회전할 때 사용되는 변수

float turn = 50.0, tipp = 30.0, twst = 0.0, x_click = 0, y_click = 0, xtm = 0.0, ytm = 0.0,
scl = 1.0, xcr = 0.0;

void Draw_Car1(void);  //차량 1~5
void Draw_Car2(void);
void Draw_Car3(void);
void Draw_Car4(void);
void Draw_Car5(void);
void Moving_Car();  //차량 1~5들의 움직임

void timer(int value);  //시간에 따른 화면 재실행 함수

void createCylinder(GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat radius, GLfloat h);  //원기둥 만들기 함수
void TcreateCylinder(GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat radius, GLfloat h, GLfloat TR, GLfloat TG, GLfloat TB);  //원기둥에 색입혀 만드는 함수
void street_lights(float Streetr, float Streetx, float Streetz); //가로등 모델링 함수
void SL_location();  //가로등 배치 함수

void drawTree(GLfloat TX, GLfloat TY, GLfloat TZ);  //나무 모델링 함수
void Tree_location();  //나무 배치 함수

void Goal1();  //대운동장 골대
void Goal2();

#endif // !MODEL_H
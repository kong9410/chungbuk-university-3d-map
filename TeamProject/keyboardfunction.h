/*********************************************************************************************************************

* �ۼ��� : ����ö, ����ȣ

* ���ϸ� : keyboardfunction.h

* ���� : Ű���� ������ ����ϴ� �Լ��� �������� ����

**********************************************************************************************************************/

#pragma once
// ��� ����
#include <stdio.h>          // Standard C/C++ Input-Output
#include <math.h>           // Math Functions
#include <windows.h>        // Standard Header For MSWindows Applications
#include <gl\glut.h>         // The GL Utility Toolkit (GLUT) Header

// The Following Directive Fixes The Problem With Extra Console Window
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#define PI_OVER_180  0.0174532925f   //This is to convert radians to degrees
float angle = 0.0, deltaAngle = 0.0;
float ratio;
float x = 85.0f, y = 3.75f, z = 85.0f;               // �ʱⰪ
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
GLint snowman_display_list;
int deltaMove = 0;

void moveMeFlat(int i);
void orientMe(float ang);
void releaseKey(unsigned char key, int x, int y);
void pressKey(unsigned char key, int x, int y);
void renderScene(void);
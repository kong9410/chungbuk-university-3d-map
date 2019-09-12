/*********************************************************************************************************************

* �ۼ��� : ����ö, ����ȣ

* ���ϸ� : Texture.h

* ���� : ķ�۽� �ǹ�, ����, ��Ǯ, �ָ� ���� �ؽ��ĸ� ������ ������ �Լ����� ����

**********************************************************************************************************************/

#pragma once
#include<GL/glut.h>
#include<windows.h>

//�ؽ��� ���� ����
static GLuint road_text[3];      //����
static GLuint grass_text[2];      //��Ǯ
static GLuint walkroad_text[3];   //�ε�
static GLuint build_text[4];   //�ǹ�
static GLuint whitebuild;      //�Ͼ�ǹ�
static GLuint soil_text;		//�״Ͻ�
static GLuint fence_text;		//�潺
static GLuint sky_text[6];         //�ϴ� ���
static GLuint water_text;		//�ָ�
//��Ʈ�� �ҷ����� �Լ�(���¼ҽ�)
void initTexture();
GLubyte *LoadBmp(const char *Path, int *Width, int *Height);
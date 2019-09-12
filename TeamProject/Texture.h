/*********************************************************************************************************************

* 작성자 : 공민철, 최진호

* 파일명 : Texture.h

* 설명 : 캠퍼스 건물, 도로, 수풀, 솔못 등의 텍스쳐를 입히는 변수와 함수들을 정의

**********************************************************************************************************************/

#pragma once
#include<GL/glut.h>
#include<windows.h>

//텍스쳐 저장 변수
static GLuint road_text[3];      //도로
static GLuint grass_text[2];      //수풀
static GLuint walkroad_text[3];   //인도
static GLuint build_text[4];   //건물
static GLuint whitebuild;      //하얀건물
static GLuint soil_text;		//테니스
static GLuint fence_text;		//펜스
static GLuint sky_text[6];         //하늘 배경
static GLuint water_text;		//솔못
//비트맵 불러오는 함수(오픈소스)
void initTexture();
GLubyte *LoadBmp(const char *Path, int *Width, int *Height);
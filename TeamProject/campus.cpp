/*********************************************************************************************************************

* 작성자 : 공민철, 최진호

* 파일명 : campus.cpp

* 설명 : 캠퍼스 건물, 도로, 수풀, 솔못 등의 좌표를 설정하고 텍스쳐를 입혀 배치하는 코드.

**********************************************************************************************************************/

#include<gl/glut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include"campus.h"
#include"Texture.h"

GLint EnvMode = GL_REPLACE;
GLint TexFilter = GL_LINEAR;

//육면체 건물(가로, 세로, 높이)
void drawCube(float width, float height, float depth) {
	glPushMatrix();
	//윗면
	float t_width = width / 3;
	float t_height = height / 8;
	float t_depth = depth / 8;

	//뒷면
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, depth, 0);
	glTexCoord2f(t_width, 0.0);
	glVertex3f(width, depth, 0);
	glTexCoord2f(t_width, t_depth);
	glVertex3f(width, 0, 0);
	glTexCoord2f(0.0, t_depth);
	glVertex3f(0, 0, 0);
	glEnd();

	//왼쪽
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(t_height, 0.0);
	glVertex3f(0, 0, height);
	glTexCoord2f(t_height, t_depth);
	glVertex3f(0, depth, height);
	glTexCoord2f(0.0, t_depth);
	glVertex3f(0, depth, 0);
	glEnd();

	//오른쪽
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(width, depth, 0);
	glTexCoord2f(t_height, 0.0);
	glVertex3f(width, depth, height);
	glTexCoord2f(t_height, t_depth);
	glVertex3f(width, 0, height);
	glTexCoord2f(0.0, t_depth);
	glVertex3f(width, 0, 0);
	glEnd();

	//앞면
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, height);
	glTexCoord2f(t_width, 0.0);
	glVertex3f(width, 0, height);
	glTexCoord2f(t_width, t_depth);
	glVertex3f(width, depth, height);
	glTexCoord2f(0.0, t_depth);
	glVertex3f(0, depth, height);
	glEnd();

	//윗면
	glBindTexture(GL_TEXTURE_2D, build_text[1]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, depth, height);
	glTexCoord2f(width, 0.0);
	glVertex3f(width, depth, height);
	glTexCoord2f(width, height);
	glVertex3f(width, depth, 0);
	glTexCoord2f(0.0, height);
	glVertex3f(0, depth, 0);
	glEnd();
	glFlush();
	glPopMatrix();
}

//인도(가로, 세로, 높이)
void drawGrayCube(float width, float height, float depth) {
	glPushMatrix();
	//윗면
	float t_width = width / width;
	float t_height = height / height;

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, depth, 0);
	glTexCoord2f(width, 0.0);
	glVertex3f(width, depth, 0);
	glTexCoord2f(width, height);
	glVertex3f(width, 0, 0);
	glTexCoord2f(0.0, height);
	glVertex3f(0, 0, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 0, height);
	glTexCoord2f(1, 1);
	glVertex3f(0, depth, height);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, depth, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(width, depth, 0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(width, depth, height);
	glTexCoord2f(1, 1);
	glVertex3f(width, 0, height);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(width, 0, 0);
	glEnd();

	//앞면
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, height);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(width, 0, height);
	glTexCoord2f(1, 1);
	glVertex3f(width, depth, height);
	glTexCoord2f(0.0, 1);
	glVertex3f(0, depth, height);
	glEnd();

	//윗면
	glBindTexture(GL_TEXTURE_2D, walkroad_text[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, depth, height);
	glTexCoord2f(width, 0.0);
	glVertex3f(width, depth, height);
	glTexCoord2f(width, height);
	glVertex3f(width, depth, 0);
	glTexCoord2f(0.0, height);
	glVertex3f(0, depth, 0);
	glEnd();
	glFlush();
	glPopMatrix();
}

//테니스장 펜스
void drawFence(float width, float height, float depth) {
	glPushMatrix();
	//윗면
	float t_width = width / width;
	float t_height = height / height;

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, depth, 0);
	glTexCoord2f(width, 0.0);
	glVertex3f(width, depth, 0);
	glTexCoord2f(width, height);
	glVertex3f(width, 0, 0);
	glTexCoord2f(0.0, height);
	glVertex3f(0, 0, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 0, height);
	glTexCoord2f(1, 1);
	glVertex3f(0, depth, height);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, depth, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(width, depth, 0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(width, depth, height);
	glTexCoord2f(1, 1);
	glVertex3f(width, 0, height);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(width, 0, 0);
	glEnd();

	//앞면
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, height);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(width, 0, height);
	glTexCoord2f(1, 1);
	glVertex3f(width, depth, height);
	glTexCoord2f(0.0, 1);
	glVertex3f(0, depth, height);
	glEnd();

	//윗면
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, depth, height);
	glTexCoord2f(width, 0.0);
	glVertex3f(width, depth, height);
	glTexCoord2f(width, height);
	glVertex3f(width, depth, 0);
	glTexCoord2f(0.0, height);
	glVertex3f(0, depth, 0);
	glEnd();
	glFlush();
	glPopMatrix();
}
void drawFenceVertex(float x, float y, float z, float width, float height, float depth, float Yangle) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(Yangle, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, fence_text);
	drawCube(width, height, depth);
	glPopMatrix();
}

//인도 큐브(가로, 세로, 높이)
void drawRoadCube(float width, float height, float depth) {
	glPushMatrix();
	//윗면
	float t_width = width / width;
	float t_height = height / height;

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, depth, 0);
	glTexCoord2f(width, 0.0);
	glVertex3f(width, depth, 0);
	glTexCoord2f(width, height);
	glVertex3f(width, 0, 0);
	glTexCoord2f(0.0, height);
	glVertex3f(0, 0, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 0, height);
	glTexCoord2f(1, 1);
	glVertex3f(0, depth, height);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, depth, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(width, depth, 0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(width, depth, height);
	glTexCoord2f(1, 1);
	glVertex3f(width, 0, height);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(width, 0, 0);
	glEnd();

	//앞면
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, height);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(width, 0, height);
	glTexCoord2f(1, 1);
	glVertex3f(width, depth, height);
	glTexCoord2f(0.0, 1);
	glVertex3f(0, depth, height);
	glEnd();

	//윗면
	glBindTexture(GL_TEXTURE_2D, walkroad_text[0]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, depth, height);
	glTexCoord2f(width, 0.0);
	glVertex3f(width, depth, height);
	glTexCoord2f(width, height);
	glVertex3f(width, depth, 0);
	glTexCoord2f(0.0, height);
	glVertex3f(0, depth, 0);
	glEnd();
	glFlush();
	glPopMatrix();
}

//일반 건물(좌표, 가로, 세로, 높이)
void drawBuilding(float x, float y, float z, float width, float height, float depth, float Yangle) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(Yangle, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, build_text[0]);
	drawCube(width, height, depth);
	glPopMatrix();
}

//하얀 건물(좌표, 가로, 세로, 높이)
void drawWhiteBuilding(float x, float y, float z, float width, float height, float depth, float Yangle) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(Yangle, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, build_text[2]);
	drawCube(width, height, depth);
	glPopMatrix();
}

//파란 건물(좌표, 가로, 세로, 높이)
void drawBlueBuilding(float x, float y, float z, float width, float height, float depth) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, build_text[3]);
	drawCube(width, height, depth);
	glPopMatrix();
}

//사각형(가로, 세로)
void drawSquare(float width, float height) {
	glPushMatrix();
	float t_width = width / 6;
	float t_height = height / 6;

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(0.0, t_height);
	glVertex3f(0, 0, height);
	glTexCoord2f(t_width, t_height);
	glVertex3f(width, 0, height);
	glTexCoord2f(t_width, 0.0);
	glVertex3f(width, 0, 0);
	glEnd();
	glPopMatrix();
	glFlush();
}

//길(시작점, 크기, 끝점)
void drawFreeRoad(float sx, float sy, float sz, float width, float ex, float ey, float ez) {
	float dx = (ex - sx);
	float dy = (ey - sy);
	float dz = (ez - sz);
	float d2v = sqrt(pow(dx, 2) + pow(dz, 2));
	float d3v = sqrt(pow(dz, 2) + pow(d2v, 2));
	double angleXZ = atan2f(dx, dz) * 180 / 3.1415f;
	double angle2Y = atan2f(dy, d2v) * 180 / 3.1415f;
	glBindTexture(GL_TEXTURE_2D, road_text[0]);
	glPushMatrix();
	glTranslatef(sx, sy, sz);
	glRotatef(angleXZ, 0, 1, 0);
	if (dy) {
		glRotatef(-angle2Y, 1, 0, 0);
	}
	if (dx > dz)
		drawSquare(width, dx);
	else if (dz > dx)
		drawSquare(width, dz);

	glPopMatrix();
	glFlush();
}

//주차장(시작점, 폭, 끝점)
void drawParkingRoad(float sx, float sy, float sz, float width, float ex, float ey, float ez) {
	float dx = (ex - sx);
	float dy = (ey - sy);
	float dz = (ez - sz);
	float d2v = sqrt(pow(dx, 2) + pow(dz, 2));
	float d3v = sqrt(pow(dz, 2) + pow(d2v, 2));
	double angleXZ = atan2f(dx, dz) * 180 / 3.1415f;
	double angle2Y = atan2f(dy, d2v) * 180 / 3.1415f;
	glBindTexture(GL_TEXTURE_2D, road_text[1]);
	glPushMatrix();
	glTranslatef(sx, sy, sz);
	glRotatef(angleXZ, 0, 1, 0);
	if (dy) {
		glRotatef(-angle2Y, 1, 0, 0);
	}
	if (dx > dz)
		drawSquare(width, dx);
	else if (dz > dx)
		drawSquare(width, dz);

	glPopMatrix();
	glFlush();
}
// 수풀(좌표, 가로, 세로)
void drawGarden(float sx, float sy, float sz, float width, float height, float YAngle) {
	glBindTexture(GL_TEXTURE_2D, grass_text[1]);
	float dw = 1;
	float dh = 1;
	float size = 6;
	glPushMatrix();
	glTranslatef(sx, sy, sz);
	glRotatef(YAngle, 0, 1, 0);
	drawSquare(width, height);
	glPopMatrix();
}
// 운동장(시작점, 가로, 세로, 각도)
void drawGarden2(float sx, float sy, float sz, float width, float height, float YAngle) {
	glBindTexture(GL_TEXTURE_2D, grass_text[0]);
	float dw = 1;
	float dh = 1;
	float size = 6;
	glPushMatrix();
	glTranslatef(sx, sy, sz);
	glRotatef(YAngle, 0, 1, 0);
	drawSquare(width, height);
	glPopMatrix();
}
//솔못(시작점, 가로, 세로, 각도)
void drawWater(float sx, float sy, float sz, float width, float height, float YAngle) {
	glBindTexture(GL_TEXTURE_2D, water_text);
	float dw = 1;
	float dh = 1;
	float size = 6;
	glPushMatrix();
	glTranslatef(sx, sy, sz);
	glRotatef(YAngle, 0, 1, 0);
	drawSquare(width, height);
	glPopMatrix();
}

//인도(좌표, 가로, 세로)
void drawWalkRoad(float sx, float sy, float sz, float width, float height, float angle) {
	glBindTexture(GL_TEXTURE_2D, walkroad_text[1]);
	glPushMatrix();
	glTranslatef(sx, sy, sz);
	glRotatef(angle, 0, 1, 0);
	float dw = 1.0f;
	for (int i = 0; i < dw; i++) {
		glPushMatrix();
		glTranslatef(i*width, 0, 0);
		drawRoadCube(width, height, 0.3f);
		glPopMatrix();
	}
	glPopMatrix();
}

//대운동장
void drawGrayRoad(float sx, float sy, float sz, float width, float height, float angle) {
	glBindTexture(GL_TEXTURE_2D, walkroad_text[2]);
	glPushMatrix();
	glTranslatef(sx, sy, sz);
	glRotatef(angle, 0, 1, 0);
	float dw = 1.0f;
	for (int i = 0; i < dw; i++) {
		glPushMatrix();
		glTranslatef(i*width, 0, 0);
		drawGrayCube(width, height, 1.0f);
		glPopMatrix();
	}
	glPopMatrix();
}

//모래밭
void drawSoil(float x, float y, float z, float width, float height, float angle) {
	glBindTexture(GL_TEXTURE_2D, soil_text);
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(angle, 0, 1, 0);
	drawSquare(width, height);
	glPopMatrix();
}

//캠퍼스 그리는 함수(건물, 도로 등의 좌표)
void drawCampus() {
	skybox();      //배경(하늘)
	drawGarden(0, 0.001f, 0, 50, 74, 0);      //대운동장 왼쪽 풀밭
	drawParkingRoad(100, 0, 0, 20, 100, 0, 60); //병원쪽 운동장
	drawParkingRoad(50, 0, 7, 7, 90, 0, 7);      //학생주차장
	drawWalkRoad(98, 0, 0, 2, 74, 0);         //후문~올라가는길
	drawWalkRoad(98, 0, 80, 2, 29, 0);         //올라가는길~3거리
	drawWalkRoad(98, 0, 115, 2, 134, 0);      //3거리~S1-21까지
	drawGarden(120, 0, 0, 60, 50, 0);
	drawWhiteBuilding(100, 0, 5, 20, 20, 15, 0);   //충대 병원
	drawWhiteBuilding(100, 0, 25, 15, 10, 11, 0);   //충대 병원 부속건물
	drawBuilding(100, 0, 40, 9, 15, 9, 0);   //E7-1
	drawBuilding(100, 0, 57, 8, 13, 9, 0);   //E7-3
	drawBuilding(120, 0, 60, 5, 12, 5, 0);  //E8-4
	drawBuilding(128, 0, 55, 7, 13, 5, 0);  //E8-5
	drawBuilding(143, 0, 55, 5, 13, 5, 0);  //E8-6
	drawBuilding(148, 0, 55, 10, 4, 5, 0);  //E8-6 ㄱ자
	drawBuilding(170, 0, 55, 7, 13, 10, 0);  //E8-10
	drawWalkRoad(100, 0, 72, 60, 2, 0);     //E8-10으로 이어지는 인도
	drawGarden(100, 0, 60, 20, 12, 0);      //등교길 풀밭
	drawFreeRoad(98, 0, 80, 6, 180, 0, 80);   //E8-3에서 E8-10으로 이어지는 길
	drawFreeRoad(0, 0, 80, 6, 92, 0, 80);   //운동장쪽 도로
	drawGarden2(55, -1.5f, 10, 30, 60, 0);      //대운동장
	/*대운동장 계단*/
	drawGrayRoad(85, -0.5f, 7, 5, 67, 0);
	drawGrayRoad(83, -1.5f, 7, 2, 67, 0);
	drawGrayRoad(50, -0.5f, 7, 5, 67, 0);
	drawGrayRoad(55, -1.5f, 7, 2, 67, 0);
	drawGrayRoad(55, -0.5f, 7, 30, 3, 0);
	drawGrayRoad(55, -1.5f, 10, 30, 2, 0);
	drawGrayRoad(55, -0.5f, 70, 30, 4, 0);
	drawGrayRoad(55, -1.5f, 68, 30, 2, 0);

	drawBuilding(100, 0, 82, 15, 5, 12, 0);   //E8-3 ㄱ자
	drawBuilding(111, 0, 87, 4, 10, 12, 0);   //E8-3 ㄱ자
	drawBuilding(125, 0, 82, 15, 5, 12, 0);//E8-7 ㄱ자
	drawBuilding(135, 0, 82, 5, 10, 12, 0);//E8-7 ㄱ자
	drawBuilding(147, 0, 82, 15, 5, 12, 0);//E-10

	drawBlueBuilding(152, 0, 94, 6, 15, 20);//E9 학연산
	drawParkingRoad(100, 0, 80, 80, 100, 0, 109);//학연산 주차장
	drawParkingRoad(120, 0, 50, 60, 120, 0, 74); //E8-10앞 주차장

	drawBuilding(100, 0, 87, 4, 3, 12, 0);   //E8-3 ㄷ자
	drawBuilding(100, 0, 94, 4, 10, 10, 0);   //E8-1
	drawBuilding(104, 0, 100, 4, 4, 10, 0);   //E8-1 ㄴ자

	drawWalkRoad(100, 0, 80, 64, 2, 0);      //E8-10가는길 인도 오른쪽

	drawFreeRoad(98, 0, 115, 6, 141, 0, 115);//학연산 방향 길
	drawFreeRoad(140.5, 0, 115, 6, 180, 0, 115);//동문 방향 길
	drawFreeRoad(140.5, 0, 115, 6, 150, 0, 200);//우리학과 가는 방향
	drawFreeRoad(150, 0, 198, 6, 150, 0, 208);
	drawParkingRoad(150, 0, 208, 6, 150, 0, 269);
	drawGarden(136, 0, 208, 14, 21, 0);
	drawGarden(150, -0.0012f, 188, 35, 41, 0);
	drawParkingRoad(136, -0.001f, 270, 41, 185, 0, 270);   //기숙사 아스팔트
	drawBlueBuilding(150, 0, 240, 8, 25, 15);//기숙사
	drawFreeRoad(130, 0, 208, 6, 150, 0, 208);
	drawFreeRoad(130, 0, 208, 6, 130, 0, 255);
	drawFreeRoad(98, 0, 255, 6, 130.5, 0, 255);   //기숙사 가는길
	drawWalkRoad(62, 0, 255, 76, 2, 0);         //기숙사 가는 오른쪽 인도
	drawWalkRoad(98, 0, 247, 32, 2, 0);         //기숙사 가는 왼쪽 인도
	drawWalkRoad(136, 0, 208, 2, 47, 0);      //중앙동아리 맞은편 인도


	drawWalkRoad(155, 0, 170, 20, 3, 6);      //학과 옆 풀숲
	drawGarden(156, 0.51f, 171, 18, 1, 6);      //학과 옆 풀숲

	drawWalkRoad(147, 0, 115, 30, 2, 0);   //학연산 맞은편 인도
	drawWalkRoad(147, 0, 115, 2, 60, 6);   //학연산-학과건물 인도
	drawWalkRoad(165, 0, 117, 12, 25, 0);   //S1-5뒤 풀밭
	drawGarden(165, 0.51f, 117, 12, 25, 0);      //S1-5뒤 풀밭
	drawWhiteBuilding(115, 0, 119, 11, 4, 6, 0);
	drawBuilding(100, 0, 119, 10, 25, 10, 0);   //S1-1
	drawBuilding(133, 0, 119, 5, 20, 8, 10);   //S1-4
	drawBuilding(136, 0, 150, 5, 10, 8, 10);   //S2
	drawBuilding(140, 0, 170, 4, 12, 5, 10);   //S3
	drawBuilding(138, 0, 178.5, 4, 4, 5, 10);   //S3
	drawWhiteBuilding(120, 0, 190, 5, 12, 5, 0);//자연박물관
	drawWhiteBuilding(115, 0, 190, 5, 5, 5, 0); //자연박물관
	drawBuilding(110, 0, 220, 8, 15, 6, 0);      //중앙동아리건물
	drawParkingRoad(110, 0, 185, 20, 110, 0, 249);//박물관주차장
	drawGarden(100, -0.001f, 149, 10, 100, 0);     //서문가는길 풀밭
	drawGarden(110, -0.001f, 149, 20, 40, 0);   //박물관 뒤 풀밭
	drawParkingRoad(120, -0.001f, 120, 20, 130, 0, 190);
	drawGarden(130, -0.001f, 185, 20, 17, 0);   //중문가는길 풀숲
	drawWalkRoad(130, 0, 200, 20, 2, 0);      //박물관 방향 인도

	drawBuilding(160, 0, 130, 7, 20, 6, 0);
	drawWhiteBuilding(165, 0, 182, 5, 13, 12, 10);   //S4-1  우리학과
	drawParkingRoad(145.5, -0.001f, 115, 30, 156, 0, 200);//우리학과 주차장
	drawGarden(154, 0.001f, 184, 8, 13, 10);

	drawBuilding(100, 0, 258, 4, 15, 10, 0);   //S21-5
	drawBuilding(100, 0, 272, 10, 4, 10, 0);   //S21-5
	drawGarden(62, 0, 257, 75, 13, 0);

	drawFreeRoad(92, 0, 0, 6, 92, 0, 255);      //후문부터~S21-5까지 길
	drawWalkRoad(90, 0, 0, 2, 74, 0);         //후문부터 개신가지 인도
	drawWalkRoad(90, 0, 80, 2, 20, 0);
	drawFreeRoad(100, 0, 173, 6, 140, 0, 143);  //농구장 올라가는길
	drawParkingRoad(100, 0, 149, 31, 140, 0, 149); //농구 주차장
	drawWalkRoad(100, 0, 115, 40, 3, 0);      //S1-4올라가는 인도
	drawWalkRoad(100, 0, 107, 40, 2, 0);
	drawWalkRoad(139, 0, 115, 2, 86, 6);      //학과까지 인도
	drawBuilding(80, 0, 80, 10, 5, 13, 0);      //농협
	drawBuilding(80, 0, 90, 10, 10, 12, 0);      //총학생

	drawParkingRoad(70, 0, 80, 20, 70, 0, 100);
	drawWhiteBuilding(50, -5, 80, 20, 10, 20, 0);/*개신문화관*/
	//계단
	drawGrayRoad(50, -0.5f, 99, 20, 1, 0);
	drawGrayRoad(50, -1.5f, 98, 20, 1, 0);
	drawGrayRoad(50, -2.5f, 97, 20, 1, 0);
	drawWalkRoad(50, -2.8f, 90, 20, 10, 0);
	drawGrayRoad(50, -0.5f, 90, 2, 10, 0);
	drawGrayRoad(52, -1.5f, 90, 2, 10, 0);
	drawGrayRoad(54, -2.5f, 90, 1, 10, 0);
	drawGrayRoad(68, -0.5f, 90, 2, 10, 0);
	drawGrayRoad(66, -1.5f, 90, 2, 10, 0);
	drawGrayRoad(65, -2.5f, 90, 1, 10, 0);
	//계단 끝

	drawBuilding(20, 0, 80, 4, 13, 10, 0);//E1-1
	drawBuilding(24, 0, 80, 11, 3, 10, 0);
	drawBuilding(35, 0, 80, 4, 13, 10, 0);//E1-2
	drawBuilding(24, 0, 89, 11, 3, 10, 0);

	drawParkingRoad(35, 0, 80, 15, 35, 0, 100);   //개신 좌측 길
	drawGarden(0, 0, 80, 35, 20, 0);         //개신 좌측 풀숲
	drawFreeRoad(56, 0, 100, 6, 56, 0, 269);   //개신~정문
	drawFreeRoad(0, 0, 106, 6, 56, 0, 106);      //개신 좌회전길
	drawFreeRoad(0, 0, 106, 6, 11, 0, 131);      //개신 좌측끝길 ~ N16-1앞 도로
	drawGarden(0, -0.002f, 106, 70, 17, 0);      //개신 좌측 풀숲
	drawParkingRoad(0, -0.003f, 147, 24, 70, -0.003f, 147);   //N15쪽 주차장
	drawWalkRoad(0, 0, 147, 10, 2, 0);         //화단
	drawGarden(0, 0.301f, 147, 10, 2, 0);
	drawWalkRoad(16, 0, 147, 35, 2, 0);         //화단
	drawGarden(16, 0.301f, 147, 35, 2, 0);
	drawWalkRoad(0, 0, 153, 51, 3, 0);         //화단
	drawGarden(0, 0.301f, 153, 51, 3, 0);
	drawWalkRoad(0, 0, 180, 15, 3, 0);         //미대 앞 인도
	drawWalkRoad(21, 0, 180, 30, 3, 0);         //미대 앞 인도
	drawParkingRoad(0, 0, 183, 27, 51, 0, 183);      //미대 주차장
	drawWhiteBuilding(5, 0, 156, 20, 12, 8, 0);      //미대


	drawFenceVertex(31, 0, 195, 0.2, 30, 1.5f, 0);
	drawFenceVertex(51, 0, 195, 0.2, 30, 1.5f, 0);
	drawFenceVertex(31, 0, 195, 20, 0.2f, 1.5f, 0);
	drawFenceVertex(31, 0, 225, 20, 0.2f, 1.5f, 0);
	drawSoil(31, 0.001f, 195, 20, 30, 0);      //테니스장
	drawFenceVertex(31, 0, 235, 0.2, 30, 1.5f, 0);
	drawFenceVertex(51, 0, 235, 0.2, 30, 1.5f, 0);
	drawFenceVertex(31, 0, 235, 20, 0.2f, 1.5f, 0);
	drawFenceVertex(31, 0, 265, 20, 0.2f, 1.5f, 0);
	drawSoil(31, 0.001f, 235, 20, 30, 0);      //테니스장2

	drawWalkRoad(51, 0, 189, 5, 80, 0);         //테니스장 앞 인도
	drawWalkRoad(0, 0, 189, 51, 3, 0);         //테니스장 뒤 인도
	drawGarden(0, 0, 192, 51, 77, 0);

	drawFreeRoad(30, -0.001f, 100, 6, 5, 0, 130);   //개신 좌회전길 ~ N16-1앞 도로
	drawFreeRoad(10, -0.001f, 123, 6, 10, 0, 149);   //N16-1앞 도로
	drawWalkRoad(62, 0, 100, 30, 98, 0);         //중도 인도
	drawWalkRoad(51, 0, 106, 5, 43, 0);         //개신 왼쪽 인도
	drawWalkRoad(51, 0, 153, 5, 30, 0);         //개신 왼쪽 인도 이어서
	drawGarden2(65, 0.35f, 160, 24, 36, 0);         //솔못쪽 수풀
	drawWater(75, 0.351f, 170, 10, 15, 0);      //솔못

	drawWalkRoad(62, 0, 204, 3, 45, 0);         //본부 왼쪽 인도
	drawWalkRoad(89, 0, 204, 3, 45, 0);         //본부 오른쪽 인도
	drawWalkRoad(65, 0, 204, 24, 2, 0);         //본부 위쪽 인도
	drawParkingRoad(65, 0, 206, 24, 65, 0, 246);//본부 주차장
	drawWalkRoad(65, 0, 246, 24, 3, 0);         //본부 아래 인도

	drawFreeRoad(62, 0, 255, 6, 92, 0, 255);
	drawWhiteBuilding(70, 0, 125, 15, 30, 15, 0);//중도
	drawWhiteBuilding(68, 0, 120, 18, 5, 15, 0); //신축도서관
	drawBuilding(35, 0, 120, 6, 25, 12, 0);       //N15
	drawBuilding(29, 0, 139, 6, 6, 12, 0);      //N15

	drawParkingRoad(0, 0, 153, 4, 56, 0, 153);   //N15지나서 중문 가는길

	drawBuilding(0, 0, 125, 6, 17, 12, 0);      //N16-1
	drawBuilding(6, 0, 125, 4, 6, 12, 0);      //N16-1

	drawFreeRoad(0, 0, 189, 6, 56, 0, 189);      //중문 가는 길

	drawBuilding(35, 0, 156, 6, 20, 10, 0);//N13

	drawFreeRoad(62, 0, 204, 6, 92, 0, 204);

	drawBuilding(86, 0, 206, 4, 17, 10, 0); //N11
	drawWhiteBuilding(68, 0, 226, 5, 15, 10, 0);//N10
	drawWhiteBuilding(73, 0, 236, 7, 5, 20, 0);//N10
}

//텍스쳐 초기화
void initTexture() {
	GLubyte *data;


	//텍스쳐 크기
	int width = 64, height = 64;

	//도로, 인도 텍스쳐
	glGenTextures(2, road_text);
	glBindTexture(GL_TEXTURE_2D, road_text[0]);
	data = LoadBmp("./road1.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, road_text[1]);
	data = LoadBmp("./road.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}

	//건물 텍스쳐
	glGenTextures(4, build_text);
	glBindTexture(GL_TEXTURE_2D, build_text[0]);
	data = LoadBmp("./build.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, build_text[1]);
	data = LoadBmp("./rooftop.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, build_text[2]);
	data = LoadBmp("./whitebuild.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, build_text[3]);
	data = LoadBmp("./hak.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}

	//풀밭 텍스쳐
	glGenTextures(2, grass_text);
	glBindTexture(GL_TEXTURE_2D, grass_text[0]);
	data = LoadBmp("./grass.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	//풀밭2 텍스쳐
	glBindTexture(GL_TEXTURE_2D, grass_text[1]);
	data = LoadBmp("./grass2.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}

	//테니스장 텍스쳐
	glGenTextures(1, &soil_text);
	glBindTexture(GL_TEXTURE_2D, soil_text);
	data = LoadBmp("./soil.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}

	//테니스장 펜스 텍스쳐
	glGenTextures(1, &fence_text);
	glBindTexture(GL_TEXTURE_2D, fence_text);
	data = LoadBmp("./greenFence.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}

	//인도와 대운동장, 개신문화관 계단 텍스쳐
	glGenTextures(3, walkroad_text);
	glBindTexture(GL_TEXTURE_2D, walkroad_text[0]);
	data = LoadBmp("./walkroad.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, walkroad_text[1]);
	data = LoadBmp("./walkroad2.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, walkroad_text[2]);
	data = LoadBmp("./gray.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}

	//배경 텍스쳐
	glGenTextures(6, sky_text);
	glBindTexture(GL_TEXTURE_2D, sky_text[0]);
	data = LoadBmp("./glacier_bk.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, sky_text[1]);
	data = LoadBmp("./glacier_ft.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, sky_text[2]);
	data = LoadBmp("./glacier_lf.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, sky_text[3]);
	data = LoadBmp("./glacier_rt.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, sky_text[4]);
	data = LoadBmp("./glacier_dn.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}
	glBindTexture(GL_TEXTURE_2D, sky_text[5]);
	data = LoadBmp("./glacier_up.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}

	//솔못 텍스쳐
	glGenTextures(1, &water_text);
	glBindTexture(GL_TEXTURE_2D, water_text);
	data = LoadBmp("./water.bmp", &width, &height);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, EnvMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		free(data);
	}

	glEnable(GL_TEXTURE_2D);
}


//배경 그리기 함수
void skybox(void) {
	float x = 0;
	float y = 0;
	float z = 0;
	float width = 1000;
	float height = 1000;
	float length = 1000;
	glBindTexture(GL_TEXTURE_2D, sky_text[0]);
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;
	//뒷면
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	//앞면
	glBindTexture(GL_TEXTURE_2D, sky_text[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	//밑면
	glBindTexture(GL_TEXTURE_2D, sky_text[4]);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
	glEnd();
	//윗면
	glBindTexture(GL_TEXTURE_2D, sky_text[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();
	//왼면
	glBindTexture(GL_TEXTURE_2D, sky_text[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);

	glEnd();
	//오른면
	glBindTexture(GL_TEXTURE_2D, sky_text[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();
}
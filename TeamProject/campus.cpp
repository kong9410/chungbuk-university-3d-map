/*********************************************************************************************************************

* �ۼ��� : ����ö, ����ȣ

* ���ϸ� : campus.cpp

* ���� : ķ�۽� �ǹ�, ����, ��Ǯ, �ָ� ���� ��ǥ�� �����ϰ� �ؽ��ĸ� ���� ��ġ�ϴ� �ڵ�.

**********************************************************************************************************************/

#include<gl/glut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include"campus.h"
#include"Texture.h"

GLint EnvMode = GL_REPLACE;
GLint TexFilter = GL_LINEAR;

//����ü �ǹ�(����, ����, ����)
void drawCube(float width, float height, float depth) {
	glPushMatrix();
	//����
	float t_width = width / 3;
	float t_height = height / 8;
	float t_depth = depth / 8;

	//�޸�
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

	//����
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

	//������
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

	//�ո�
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

	//����
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

//�ε�(����, ����, ����)
void drawGrayCube(float width, float height, float depth) {
	glPushMatrix();
	//����
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

	//�ո�
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

	//����
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

//�״Ͻ��� �潺
void drawFence(float width, float height, float depth) {
	glPushMatrix();
	//����
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

	//�ո�
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

	//����
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

//�ε� ť��(����, ����, ����)
void drawRoadCube(float width, float height, float depth) {
	glPushMatrix();
	//����
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

	//�ո�
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

	//����
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

//�Ϲ� �ǹ�(��ǥ, ����, ����, ����)
void drawBuilding(float x, float y, float z, float width, float height, float depth, float Yangle) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(Yangle, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, build_text[0]);
	drawCube(width, height, depth);
	glPopMatrix();
}

//�Ͼ� �ǹ�(��ǥ, ����, ����, ����)
void drawWhiteBuilding(float x, float y, float z, float width, float height, float depth, float Yangle) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(Yangle, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, build_text[2]);
	drawCube(width, height, depth);
	glPopMatrix();
}

//�Ķ� �ǹ�(��ǥ, ����, ����, ����)
void drawBlueBuilding(float x, float y, float z, float width, float height, float depth) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, build_text[3]);
	drawCube(width, height, depth);
	glPopMatrix();
}

//�簢��(����, ����)
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

//��(������, ũ��, ����)
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

//������(������, ��, ����)
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
// ��Ǯ(��ǥ, ����, ����)
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
// ���(������, ����, ����, ����)
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
//�ָ�(������, ����, ����, ����)
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

//�ε�(��ǥ, ����, ����)
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

//����
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

//�𷡹�
void drawSoil(float x, float y, float z, float width, float height, float angle) {
	glBindTexture(GL_TEXTURE_2D, soil_text);
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(angle, 0, 1, 0);
	drawSquare(width, height);
	glPopMatrix();
}

//ķ�۽� �׸��� �Լ�(�ǹ�, ���� ���� ��ǥ)
void drawCampus() {
	skybox();      //���(�ϴ�)
	drawGarden(0, 0.001f, 0, 50, 74, 0);      //���� ���� Ǯ��
	drawParkingRoad(100, 0, 0, 20, 100, 0, 60); //������ ���
	drawParkingRoad(50, 0, 7, 7, 90, 0, 7);      //�л�������
	drawWalkRoad(98, 0, 0, 2, 74, 0);         //�Ĺ�~�ö󰡴±�
	drawWalkRoad(98, 0, 80, 2, 29, 0);         //�ö󰡴±�~3�Ÿ�
	drawWalkRoad(98, 0, 115, 2, 134, 0);      //3�Ÿ�~S1-21����
	drawGarden(120, 0, 0, 60, 50, 0);
	drawWhiteBuilding(100, 0, 5, 20, 20, 15, 0);   //��� ����
	drawWhiteBuilding(100, 0, 25, 15, 10, 11, 0);   //��� ���� �μӰǹ�
	drawBuilding(100, 0, 40, 9, 15, 9, 0);   //E7-1
	drawBuilding(100, 0, 57, 8, 13, 9, 0);   //E7-3
	drawBuilding(120, 0, 60, 5, 12, 5, 0);  //E8-4
	drawBuilding(128, 0, 55, 7, 13, 5, 0);  //E8-5
	drawBuilding(143, 0, 55, 5, 13, 5, 0);  //E8-6
	drawBuilding(148, 0, 55, 10, 4, 5, 0);  //E8-6 ����
	drawBuilding(170, 0, 55, 7, 13, 10, 0);  //E8-10
	drawWalkRoad(100, 0, 72, 60, 2, 0);     //E8-10���� �̾����� �ε�
	drawGarden(100, 0, 60, 20, 12, 0);      //��� Ǯ��
	drawFreeRoad(98, 0, 80, 6, 180, 0, 80);   //E8-3���� E8-10���� �̾����� ��
	drawFreeRoad(0, 0, 80, 6, 92, 0, 80);   //����� ����
	drawGarden2(55, -1.5f, 10, 30, 60, 0);      //����
	/*���� ���*/
	drawGrayRoad(85, -0.5f, 7, 5, 67, 0);
	drawGrayRoad(83, -1.5f, 7, 2, 67, 0);
	drawGrayRoad(50, -0.5f, 7, 5, 67, 0);
	drawGrayRoad(55, -1.5f, 7, 2, 67, 0);
	drawGrayRoad(55, -0.5f, 7, 30, 3, 0);
	drawGrayRoad(55, -1.5f, 10, 30, 2, 0);
	drawGrayRoad(55, -0.5f, 70, 30, 4, 0);
	drawGrayRoad(55, -1.5f, 68, 30, 2, 0);

	drawBuilding(100, 0, 82, 15, 5, 12, 0);   //E8-3 ����
	drawBuilding(111, 0, 87, 4, 10, 12, 0);   //E8-3 ����
	drawBuilding(125, 0, 82, 15, 5, 12, 0);//E8-7 ����
	drawBuilding(135, 0, 82, 5, 10, 12, 0);//E8-7 ����
	drawBuilding(147, 0, 82, 15, 5, 12, 0);//E-10

	drawBlueBuilding(152, 0, 94, 6, 15, 20);//E9 �п���
	drawParkingRoad(100, 0, 80, 80, 100, 0, 109);//�п��� ������
	drawParkingRoad(120, 0, 50, 60, 120, 0, 74); //E8-10�� ������

	drawBuilding(100, 0, 87, 4, 3, 12, 0);   //E8-3 ����
	drawBuilding(100, 0, 94, 4, 10, 10, 0);   //E8-1
	drawBuilding(104, 0, 100, 4, 4, 10, 0);   //E8-1 ����

	drawWalkRoad(100, 0, 80, 64, 2, 0);      //E8-10���±� �ε� ������

	drawFreeRoad(98, 0, 115, 6, 141, 0, 115);//�п��� ���� ��
	drawFreeRoad(140.5, 0, 115, 6, 180, 0, 115);//���� ���� ��
	drawFreeRoad(140.5, 0, 115, 6, 150, 0, 200);//�츮�а� ���� ����
	drawFreeRoad(150, 0, 198, 6, 150, 0, 208);
	drawParkingRoad(150, 0, 208, 6, 150, 0, 269);
	drawGarden(136, 0, 208, 14, 21, 0);
	drawGarden(150, -0.0012f, 188, 35, 41, 0);
	drawParkingRoad(136, -0.001f, 270, 41, 185, 0, 270);   //����� �ƽ���Ʈ
	drawBlueBuilding(150, 0, 240, 8, 25, 15);//�����
	drawFreeRoad(130, 0, 208, 6, 150, 0, 208);
	drawFreeRoad(130, 0, 208, 6, 130, 0, 255);
	drawFreeRoad(98, 0, 255, 6, 130.5, 0, 255);   //����� ���±�
	drawWalkRoad(62, 0, 255, 76, 2, 0);         //����� ���� ������ �ε�
	drawWalkRoad(98, 0, 247, 32, 2, 0);         //����� ���� ���� �ε�
	drawWalkRoad(136, 0, 208, 2, 47, 0);      //�߾ӵ��Ƹ� ������ �ε�


	drawWalkRoad(155, 0, 170, 20, 3, 6);      //�а� �� Ǯ��
	drawGarden(156, 0.51f, 171, 18, 1, 6);      //�а� �� Ǯ��

	drawWalkRoad(147, 0, 115, 30, 2, 0);   //�п��� ������ �ε�
	drawWalkRoad(147, 0, 115, 2, 60, 6);   //�п���-�а��ǹ� �ε�
	drawWalkRoad(165, 0, 117, 12, 25, 0);   //S1-5�� Ǯ��
	drawGarden(165, 0.51f, 117, 12, 25, 0);      //S1-5�� Ǯ��
	drawWhiteBuilding(115, 0, 119, 11, 4, 6, 0);
	drawBuilding(100, 0, 119, 10, 25, 10, 0);   //S1-1
	drawBuilding(133, 0, 119, 5, 20, 8, 10);   //S1-4
	drawBuilding(136, 0, 150, 5, 10, 8, 10);   //S2
	drawBuilding(140, 0, 170, 4, 12, 5, 10);   //S3
	drawBuilding(138, 0, 178.5, 4, 4, 5, 10);   //S3
	drawWhiteBuilding(120, 0, 190, 5, 12, 5, 0);//�ڿ��ڹ���
	drawWhiteBuilding(115, 0, 190, 5, 5, 5, 0); //�ڿ��ڹ���
	drawBuilding(110, 0, 220, 8, 15, 6, 0);      //�߾ӵ��Ƹ��ǹ�
	drawParkingRoad(110, 0, 185, 20, 110, 0, 249);//�ڹ���������
	drawGarden(100, -0.001f, 149, 10, 100, 0);     //�������±� Ǯ��
	drawGarden(110, -0.001f, 149, 20, 40, 0);   //�ڹ��� �� Ǯ��
	drawParkingRoad(120, -0.001f, 120, 20, 130, 0, 190);
	drawGarden(130, -0.001f, 185, 20, 17, 0);   //�߹����±� Ǯ��
	drawWalkRoad(130, 0, 200, 20, 2, 0);      //�ڹ��� ���� �ε�

	drawBuilding(160, 0, 130, 7, 20, 6, 0);
	drawWhiteBuilding(165, 0, 182, 5, 13, 12, 10);   //S4-1  �츮�а�
	drawParkingRoad(145.5, -0.001f, 115, 30, 156, 0, 200);//�츮�а� ������
	drawGarden(154, 0.001f, 184, 8, 13, 10);

	drawBuilding(100, 0, 258, 4, 15, 10, 0);   //S21-5
	drawBuilding(100, 0, 272, 10, 4, 10, 0);   //S21-5
	drawGarden(62, 0, 257, 75, 13, 0);

	drawFreeRoad(92, 0, 0, 6, 92, 0, 255);      //�Ĺ�����~S21-5���� ��
	drawWalkRoad(90, 0, 0, 2, 74, 0);         //�Ĺ����� ���Ű��� �ε�
	drawWalkRoad(90, 0, 80, 2, 20, 0);
	drawFreeRoad(100, 0, 173, 6, 140, 0, 143);  //���� �ö󰡴±�
	drawParkingRoad(100, 0, 149, 31, 140, 0, 149); //�� ������
	drawWalkRoad(100, 0, 115, 40, 3, 0);      //S1-4�ö󰡴� �ε�
	drawWalkRoad(100, 0, 107, 40, 2, 0);
	drawWalkRoad(139, 0, 115, 2, 86, 6);      //�а����� �ε�
	drawBuilding(80, 0, 80, 10, 5, 13, 0);      //����
	drawBuilding(80, 0, 90, 10, 10, 12, 0);      //���л�

	drawParkingRoad(70, 0, 80, 20, 70, 0, 100);
	drawWhiteBuilding(50, -5, 80, 20, 10, 20, 0);/*���Ź�ȭ��*/
	//���
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
	//��� ��

	drawBuilding(20, 0, 80, 4, 13, 10, 0);//E1-1
	drawBuilding(24, 0, 80, 11, 3, 10, 0);
	drawBuilding(35, 0, 80, 4, 13, 10, 0);//E1-2
	drawBuilding(24, 0, 89, 11, 3, 10, 0);

	drawParkingRoad(35, 0, 80, 15, 35, 0, 100);   //���� ���� ��
	drawGarden(0, 0, 80, 35, 20, 0);         //���� ���� Ǯ��
	drawFreeRoad(56, 0, 100, 6, 56, 0, 269);   //����~����
	drawFreeRoad(0, 0, 106, 6, 56, 0, 106);      //���� ��ȸ����
	drawFreeRoad(0, 0, 106, 6, 11, 0, 131);      //���� �������� ~ N16-1�� ����
	drawGarden(0, -0.002f, 106, 70, 17, 0);      //���� ���� Ǯ��
	drawParkingRoad(0, -0.003f, 147, 24, 70, -0.003f, 147);   //N15�� ������
	drawWalkRoad(0, 0, 147, 10, 2, 0);         //ȭ��
	drawGarden(0, 0.301f, 147, 10, 2, 0);
	drawWalkRoad(16, 0, 147, 35, 2, 0);         //ȭ��
	drawGarden(16, 0.301f, 147, 35, 2, 0);
	drawWalkRoad(0, 0, 153, 51, 3, 0);         //ȭ��
	drawGarden(0, 0.301f, 153, 51, 3, 0);
	drawWalkRoad(0, 0, 180, 15, 3, 0);         //�̴� �� �ε�
	drawWalkRoad(21, 0, 180, 30, 3, 0);         //�̴� �� �ε�
	drawParkingRoad(0, 0, 183, 27, 51, 0, 183);      //�̴� ������
	drawWhiteBuilding(5, 0, 156, 20, 12, 8, 0);      //�̴�


	drawFenceVertex(31, 0, 195, 0.2, 30, 1.5f, 0);
	drawFenceVertex(51, 0, 195, 0.2, 30, 1.5f, 0);
	drawFenceVertex(31, 0, 195, 20, 0.2f, 1.5f, 0);
	drawFenceVertex(31, 0, 225, 20, 0.2f, 1.5f, 0);
	drawSoil(31, 0.001f, 195, 20, 30, 0);      //�״Ͻ���
	drawFenceVertex(31, 0, 235, 0.2, 30, 1.5f, 0);
	drawFenceVertex(51, 0, 235, 0.2, 30, 1.5f, 0);
	drawFenceVertex(31, 0, 235, 20, 0.2f, 1.5f, 0);
	drawFenceVertex(31, 0, 265, 20, 0.2f, 1.5f, 0);
	drawSoil(31, 0.001f, 235, 20, 30, 0);      //�״Ͻ���2

	drawWalkRoad(51, 0, 189, 5, 80, 0);         //�״Ͻ��� �� �ε�
	drawWalkRoad(0, 0, 189, 51, 3, 0);         //�״Ͻ��� �� �ε�
	drawGarden(0, 0, 192, 51, 77, 0);

	drawFreeRoad(30, -0.001f, 100, 6, 5, 0, 130);   //���� ��ȸ���� ~ N16-1�� ����
	drawFreeRoad(10, -0.001f, 123, 6, 10, 0, 149);   //N16-1�� ����
	drawWalkRoad(62, 0, 100, 30, 98, 0);         //�ߵ� �ε�
	drawWalkRoad(51, 0, 106, 5, 43, 0);         //���� ���� �ε�
	drawWalkRoad(51, 0, 153, 5, 30, 0);         //���� ���� �ε� �̾
	drawGarden2(65, 0.35f, 160, 24, 36, 0);         //�ָ��� ��Ǯ
	drawWater(75, 0.351f, 170, 10, 15, 0);      //�ָ�

	drawWalkRoad(62, 0, 204, 3, 45, 0);         //���� ���� �ε�
	drawWalkRoad(89, 0, 204, 3, 45, 0);         //���� ������ �ε�
	drawWalkRoad(65, 0, 204, 24, 2, 0);         //���� ���� �ε�
	drawParkingRoad(65, 0, 206, 24, 65, 0, 246);//���� ������
	drawWalkRoad(65, 0, 246, 24, 3, 0);         //���� �Ʒ� �ε�

	drawFreeRoad(62, 0, 255, 6, 92, 0, 255);
	drawWhiteBuilding(70, 0, 125, 15, 30, 15, 0);//�ߵ�
	drawWhiteBuilding(68, 0, 120, 18, 5, 15, 0); //���൵����
	drawBuilding(35, 0, 120, 6, 25, 12, 0);       //N15
	drawBuilding(29, 0, 139, 6, 6, 12, 0);      //N15

	drawParkingRoad(0, 0, 153, 4, 56, 0, 153);   //N15������ �߹� ���±�

	drawBuilding(0, 0, 125, 6, 17, 12, 0);      //N16-1
	drawBuilding(6, 0, 125, 4, 6, 12, 0);      //N16-1

	drawFreeRoad(0, 0, 189, 6, 56, 0, 189);      //�߹� ���� ��

	drawBuilding(35, 0, 156, 6, 20, 10, 0);//N13

	drawFreeRoad(62, 0, 204, 6, 92, 0, 204);

	drawBuilding(86, 0, 206, 4, 17, 10, 0); //N11
	drawWhiteBuilding(68, 0, 226, 5, 15, 10, 0);//N10
	drawWhiteBuilding(73, 0, 236, 7, 5, 20, 0);//N10
}

//�ؽ��� �ʱ�ȭ
void initTexture() {
	GLubyte *data;


	//�ؽ��� ũ��
	int width = 64, height = 64;

	//����, �ε� �ؽ���
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

	//�ǹ� �ؽ���
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

	//Ǯ�� �ؽ���
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
	//Ǯ��2 �ؽ���
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

	//�״Ͻ��� �ؽ���
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

	//�״Ͻ��� �潺 �ؽ���
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

	//�ε��� ����, ���Ź�ȭ�� ��� �ؽ���
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

	//��� �ؽ���
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

	//�ָ� �ؽ���
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


//��� �׸��� �Լ�
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
	//�޸�
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	//�ո�
	glBindTexture(GL_TEXTURE_2D, sky_text[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	//�ظ�
	glBindTexture(GL_TEXTURE_2D, sky_text[4]);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
	glEnd();
	//����
	glBindTexture(GL_TEXTURE_2D, sky_text[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();
	//�޸�
	glBindTexture(GL_TEXTURE_2D, sky_text[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);

	glEnd();
	//������
	glBindTexture(GL_TEXTURE_2D, sky_text[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();
}
#pragma once
/*********************************************************************************************************************

* �ۼ��� : ����ö, ����ȣ

* ���ϸ� : campus.h

* ���� : ķ�۽� ������ �ʿ��� �Լ����� ����

**********************************************************************************************************************/

void drawCube(float width, float height, float depth); //����ü �׸��� �Լ�(����, ����, ����)
void drawGrayCube(float width, float height, float depth);
void drawFence(float width, float height, float depth);
void drawFenceVertex(float x, float y, float z, float width, float height, float depth, float Yangle);
void drawRoadCube(float width, float height, float depth);
void drawBuilding(float x, float y, float z, float width, float height, float depth, float Yangle);
void drawWhiteBuilding(float x, float y, float z, float width, float height, float depth, float Yangle);
void drawBlueBuilding(float x, float y, float z, float width, float height, float depth);
void drawSquare(float width, float height);
void drawFreeRoad(float sx, float sy, float sz, float width, float ex, float ey, float ez);
void drawParkingRoad(float sx, float sy, float sz, float width, float ex, float ey, float ez);
void drawGarden(float sx, float sy, float sz, float width, float height, float YAngle);
void drawGarden2(float sx, float sy, float sz, float width, float height, float YAngle);
void drawWater(float sx, float sy, float sz, float width, float height, float YAngle);
void drawWalkRoad(float sx, float sy, float sz, float width, float height, float angle);
void drawGrayRoad(float sx, float sy, float sz, float width, float height, float angle);
void drawSoil(float x, float y, float z, float width, float height, float angle);
void drawCampus();
void skybox();
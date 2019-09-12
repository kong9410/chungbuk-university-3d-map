#pragma once
/*********************************************************************************************************************

* 작성자 : 공민철, 최진호

* 파일명 : campus.h

* 설명 : 캠퍼스 구성에 필요한 함수들을 정의

**********************************************************************************************************************/

void drawCube(float width, float height, float depth); //육면체 그리는 함수(가로, 세로, 높이)
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
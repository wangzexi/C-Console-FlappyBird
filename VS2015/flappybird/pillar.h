#pragma once

#define PILLAR_WIDTH 8

#define PILLAR_GAP 10

struct Pillar
{
	float left;
	int gap;		//Öù×ÓÈ±¿Ú¾àÆÁÄ»¶¥±ßµÄ¾àÀë
};


void PillarInit(int index);
char PillarGetCharFromPoint(int index, int x, int y);
int PillarIsCollision(int index, int x, int y);

#include "common.h"

void PillarInit(int index) {
	gPillarPool[index].gap = (rand() % 10 - 5) + HEIGHT / 2;
}

char PillarGetCharFromPoint(int index, int x, int y) {
	if (y < gPillarPool[index].gap - PILLAR_GAP / 2 || y > gPillarPool[index].gap + PILLAR_GAP / 2)
		return ' ';
	return '\0';
}

int PillarIsCollision(int index, int x, int y) {
	if (x < gPillarPool[index].left + PILLAR_WIDTH && x > gPillarPool[index].left)
		if (y < gPillarPool[index].gap - PILLAR_GAP / 2 || y > gPillarPool[index].gap + PILLAR_GAP / 2)
			return 1;
	return 0;
}
#include "common.h"

void PillarPoolInit() {
	int x = PILLAR_START;
	for (int i = 0; i < PILLAR_COUNT; ++i) {
		PillarInit(i);
		gPillarPool[i].left = x;
		x += PILLAR_SPACE;
	}
}

void PillarPoolMove(float x) {
	for (int i = 0; i < PILLAR_COUNT; ++i) {
		if (gPillarPool[i].left + PILLAR_WIDTH < 0) {
			gPillarPool[i].left = WIDTH;
			PillarInit(i);
		}
			
		gPillarPool[i].left += x;
	}
}
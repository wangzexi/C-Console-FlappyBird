#include "common.h"

void Init() {
	time_t t;
	srand((unsigned)time(&t));

	RenderInit();

	Ready();
}

void Ready() {
	gDistance = 0;
	gStatus = READY;

	BirdInit();
	PillarPoolInit();
}

void Process() {
	int key = GetAsyncKeyState(VK_SPACE);
	if (key && 1) {
		switch (gStatus)
		{
		case READY:
			gStatus = PLAYING;
			break;
		case DEAD:
			gStatus = READY;
			Ready();
			break;
		default:
			BirdFly();
		}
	}
}
#include "common.h"

char birdChar[BIRD_HEIGHT][BIRD_WIDTH] = {
	' ', '/', '~', '~', '~', '\0',
	')', ' ', ' ', '@', ' ', '<',
	'\0', '\\', '_', '_', '/', '\0'
};

void BirdInit() {
	gBird.left = BIRD_START;
	gBird.top = 10;

	gBird.v = 0;
}

void BirdFly() {
	gBird.v = FLY_UP_SPEED;
}

char BirdGetCharFromPoint(int x, int y) {
	if (x >= 0 && x < BIRD_WIDTH && y >= 0 && y < BIRD_HEIGHT)
		return birdChar[y][x];
	return ' ';
}
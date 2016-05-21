#include "common.h"

enum Status gStatus;		// ”Œœ∑◊¥Ã¨

float gDistance;			// ∑…––æ‡¿Î

struct Bird gBird;
struct Pillar gPillarPool[PILLAR_COUNT];

int main() {
	
	Init();
	
	while (1) {
		
		Process();
		Update();

		Render();
		
		Sleep(DT * 1000);
	}

	return 0;
}
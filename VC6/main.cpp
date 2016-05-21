#include "common.h"

enum Status gStatus;		// ��Ϸ״̬

float gDistance;			// ���о���

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
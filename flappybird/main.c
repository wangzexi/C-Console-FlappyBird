#include "common.h"


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
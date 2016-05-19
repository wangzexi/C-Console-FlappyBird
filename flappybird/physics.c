#include "common.h"

void Update() {
	if (gStatus == PLAYING) {
		// �����ƶ�
		PillarPoolMove(SPEED);
		gDistance += -SPEED;

		// ������
		gBird.v = gBird.v + DT * gBird.g;
		gBird.top = gBird.top + DT * gBird.v;

		if (gBird.top + BIRD_HEIGHT > HEIGHT) {
			gBird.top = HEIGHT - BIRD_HEIGHT;
			gStatus = DEAD;
		}

		// ��ײ���
		for (int i = 0; i < PILLAR_COUNT; ++i)
			if (PillarIsCollision(i, gBird.left + BIRD_WIDTH / 2, gBird.top + BIRD_HEIGHT / 2))
				gStatus = DEAD;

	}
}
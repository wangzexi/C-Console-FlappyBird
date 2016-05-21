
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#include "controller.h"
#include "render.h"
#include "pillar.h"
#include "pillarPool.h"
#include "brid.h"
#include "physics.h"


#define WIDTH 100			//�������
#define HEIGHT 30			//�����߶�

#define DT 0.05				// ˢ�¼������λ��

#define SPEED -1			// �ƶ��ٶ�
#define GRAVITY 150			// ����
#define FLY_UP_SPEED -45	// �Ϸ��ٶ�

enum Status{
	PLAYING,
	READY,
	DEAD
};


extern enum Status gStatus;		// ��Ϸ״̬

extern float gDistance;			// ���о���

extern struct Bird gBird;
extern struct Pillar gPillarPool[PILLAR_COUNT];
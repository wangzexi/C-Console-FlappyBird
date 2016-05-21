
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


#define WIDTH 100			//画布宽度
#define HEIGHT 30			//画布高度

#define DT 0.05				// 刷新间隔，单位秒

#define SPEED -1			// 移动速度
#define GRAVITY 150			// 重力
#define FLY_UP_SPEED -45	// 上飞速度

enum Status{
	PLAYING,
	READY,
	DEAD
};


extern enum Status gStatus;		// 游戏状态

extern float gDistance;			// 飞行距离

extern struct Bird gBird;
extern struct Pillar gPillarPool[PILLAR_COUNT];
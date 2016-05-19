#include "common.h"


HANDLE wHnd;	// �������̨���

// �ַ���������
CHAR_INFO consoleBuffer[WIDTH * HEIGHT];

COORD characterBufferSize = { WIDTH, HEIGHT };
COORD characterPosition = { 0, 0 };
SMALL_RECT consoleWriteArea = { 0, 0, WIDTH - 1, HEIGHT - 1 };

void RenderInit() {
	// ���ô��ڱ���
	SetConsoleTitle("FlappyBird");

	// ȡ���
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���ô��ڴ�С
	SMALL_RECT windowSize = { 0, 0, WIDTH - 1, HEIGHT - 1 };
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);

	// ���û�������С
	COORD bufferSize = { WIDTH, HEIGHT };
	SetConsoleScreenBufferSize(wHnd, bufferSize);

	// ���������������Ĺ��
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(wHnd, &cursor_info);
}

void Render() {
	// ������
	for (int y = 0; y < HEIGHT; ++y)
		for (int x = 0; x < WIDTH; ++x) {
			consoleBuffer[x + WIDTH * y].Char.AsciiChar = ' ';
			if (y > HEIGHT * 0.8)
				PaintPoint(x, y, ' ', BACKGROUND_GREEN | BACKGROUND_INTENSITY);
			else
				PaintPoint(x, y, ' ', BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
		}

	// ������
	for (int i = 0; i < PILLAR_COUNT; ++i)
		for (int y = 0; y < HEIGHT; ++y)
			for (int x = 0; x < PILLAR_WIDTH; ++x) {
				char c = PillarGetCharFromPoint(i, x, y);
				PaintPoint(
					(int)(gPillarPool[i].left + x),
					y,
					c,
					BACKGROUND_GREEN | BACKGROUND_BLUE
					);
			}

	// ����
	for (int y = 0; y < BIRD_HEIGHT; ++y)
		for (int x = 0; x < BIRD_WIDTH; ++x) {
			PaintPoint(
				(int)(gBird.left + x),
				(int)(gBird.top + y),
				BirdGetCharFromPoint(x, y),
				gStatus != DEAD
					? BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
					: BACKGROUND_RED | BACKGROUND_INTENSITY
				);
		}

	// ������
	int count = 1 + (gDistance - (PILLAR_START - BIRD_START) - BIRD_WIDTH - PILLAR_WIDTH) / PILLAR_SPACE;
	char str[10];
	_itoa(count, str, 10);
	
	int i = 0;
	while (str[i] != '\0') {
		PaintPoint(WIDTH * 0.48 + i, HEIGHT * 0.1, str[i], FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED);
		++i;
	}
	
	// �������
	WriteConsoleOutputA(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);
}



void PaintPoint(int x, int y, char c, WORD attr) {
	//��֤���鰲ȫ
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
		int i = x + WIDTH * y;
		consoleBuffer[i].Char.AsciiChar = c;
		if (c != '\0')
			consoleBuffer[i].Attributes = attr;
	}
}
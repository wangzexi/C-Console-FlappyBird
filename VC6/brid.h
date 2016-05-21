
#define BIRD_WIDTH 6
#define BIRD_HEIGHT 3

#define BIRD_START 20

struct Bird
{
	float left;
	float top;

	float v;
};


void BirdInit();
void BirdFly();
char BirdGetCharFromPoint(int x, int y);

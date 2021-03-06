#include <graphics.h>

void field();
void sun();
void hut();

int main()
{
	int gdriver = DETECT, gmode = VGAMAX;
	initgraph(&gdriver, &gmode, "NONE");
	field();
	sun();
	hut();
	delay(1000);
	return 0;
}

void hut()
{
	int x = getmaxx(), y = getmaxy();
	setcolor(WHITE);
	rectangle(x - 50, y / 2, x - 120, (y / 2) - 80);
	rectangle(x - 70, y /2, x - 100, (y / 2) - 50);
	circle(x - 80, (y / 2) - 25, 5);
	line(x - 120, (y / 2) - 80, x - 85, y / 2 - 120);
	line(x - 85, (y / 2) - 120, x - 50, y / 2 - 80);
	setfillstyle(SOLID_FILL, RED);
	floodfill(x - 60, (y / 2) - 60, WHITE);
	setfillstyle(SOLID_FILL, BROWN);
	floodfill(x - 80, (y / 2) - 40, WHITE);
	setfillstyle(SOLID_FILL, BROWN);
	floodfill(x - 100, (y / 2) - 90, WHITE);
}

void sun()
{
	setcolor(YELLOW);
	arc(100, 60, -60, 60, 30);
	arc(60, 60, -25, 25, 60);
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(122, 60, YELLOW);
}

void field()
{
	int x = getmaxx(), y = getmaxy();
	setcolor(GREEN);
	line(0, y / 2, x, y / 2);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(x, y, GREEN);
}

#include <graphics.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	float x1, x2, y1, y2, dx, dy, l, i;
	cout << "Enter the value of x1, y1, x2 and y2\n";
	cin >> x1 >> y1 >> x2 >> y2;
	dx = x2 - x1;
	dy = y2 - y1;
	if(abs(dx) > abs(dy))
		l = abs(dx);
	else
		l = abs(dy);

	dx = dx / l;
	dy = dy / l;
	x1 += 0.5;
	y2 += 0.5;
	int gdriver = DETECT, gmode = VGAMAX;
	initgraph(&gdriver, &gmode, "NULL");
	
	for(i = 0; i <= len; i++)
	{
		putpixel(x1, y1, WHITE);
		x1 += dx;
		y1 += dy;
	}
	return 0;
}

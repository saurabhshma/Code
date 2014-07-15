#include<iostream>
#include<graphics.h>

int main()
{
int gd,gm=VGAMAX; gd=DETECT;
initgraph(&gd,&gm,NULL);
line(50,50,80,80);
delay(10000);

return 0;
}


#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
void drawLine(int,int,int,int);
void main (){
	int x1,x2,x3,y1,y2,y3;
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C://TURBOC3//BGI");
	printf("Enter the value of x1 :\n");
	scanf("%d",&x1);
	printf("Enter the value of y1 :\n");
	scanf("%d",&y1);
	printf("Enter the value of x2 :\n");
	scanf("%d",&x2);
	printf("Enter the value of y2 :\n");
	scanf("%d",&y2);
	printf("Enter the value of x3 :\n");
	scanf("%d",&x3);
	printf("Enter the value of y3 :\n");
	scanf("%d",&y3);
       clrscr();
	drawLine(x1,y1,x2,y2);
       drawLine(x2,y2,x3,y3);
	drawLine(x3,y3,x1,y1);
	getch();
	//closegraph();


}
void drawLine (int x1, int y1, int x2, int y2) {
	int dx, dy, steps,i;
	float x_inc, y_inc, x, y;
	dx = x2 - x1;
	dy =y2 - y1;
	if (abs(dx) >abs(dy))
	steps =abs(dx);
	else
	steps = abs(dy);
	x_inc = dx/(float) steps;
	y_inc =dy/(float) steps;
	x = x1;
	y = y1;
	for(i = 0; i <= steps ;i++){
    putpixel(x,y,WHITE);
	x = x + x_inc;
	y = y + y_inc;

	}

}

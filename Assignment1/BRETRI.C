#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
void lineB(int xa, int ya, int xb, int yb) {
    int dx = abs(xa - xb), dy = abs (ya - yb);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyDx = 2 *(dy - dx);
    int pr = 2 * dx - dy;
    int twoDyr = 2 * dx, twoDyDxr = 2 *(dx - dy);
    int x, y, xEnd, yEnd;

    if(xa > xb) {
	x = xb;
	y = yb;
	xEnd = xa;
	yEnd = ya;
    }
    else {
	x = xa;
	y = ya;
	xEnd = xb;
    yEnd = yb;
    }
    putpixel (x, y,WHITE);
    if (dx == 0){
	while (y < yEnd){
	    putpixel(x,y,WHITE);
	    y++;
	}
    }
    else if(y<= yEnd){
	    float m = dy /(float) dx;
	    //m>0 <1
	    if(m>=0 && m < 1){
	    while(x < xEnd) {
		x++;
		if(p < 0)
		    p +=twoDy;
		else{
			y++;
			p += twoDyDx;
		    }
		putpixel(x, y,WHITE);
		}
	}

	else{
	    while(y < yEnd) {
		y++;
		if(pr < 0)
		    pr +=twoDyr;
		else{
			x++;
			pr += twoDyDxr;
		    }
		putpixel(x, y,WHITE);
		}
	    }



    }
    else if(y > yEnd){
	float m = dy /(float) dx;
	    if(m>=0 && m < 1){
	    while(x < xEnd) {
		x++;
		if(p < 0)
		    p +=twoDy;
		else{
			y--;
			p += twoDyDx;
		    }
		putpixel(x, y,WHITE);
		}
	}

	else{
	    while(y > yEnd) {
		y--;
		if(pr < 0)
		    pr +=twoDyr;
		else{
			x++;
			pr += twoDyDxr;
		    }
		putpixel(x, y,WHITE);
		}
	    }
    }

}
void main(){
    int x1,x2,x3,y1,y2,y3;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C://TURBOC3//BGI");
    printf("Enter the value of x1:\n");
    scanf("%d",&x1);
    printf("Enter the value of y1:\n");
    scanf("%d",&y1);
    printf("Enter the value of x2:\n");
    scanf("%d",&x2);
    printf("Enter the value of y2:\n");
    scanf("%d",&y2);
    printf("Enter the value of x3:\n");
    scanf("%d",&x3);
    printf("Enter the value of y3:\n");
    scanf("%d",&y3);
    clrscr();
    lineB(x1,y1,x2,y2);
    lineB(x2,y2,x3,y3);
    lineB(x3,y3,x1,y1);
    getch();
}

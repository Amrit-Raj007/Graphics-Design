
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
void drawLine (int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs (y2 - y1);
    float m = dy / (float) dx;
    float mS = (float)(y2 - y1)/ (float) (x2 - x1);
    int twoDy = 2 * dy;
    int twoDyDx = 2 * (dy - dx);
    //twoDyM and twoDyDxM are used when slope is greater than 1
    int twoDyM = 2 * dx;
    int twoDyDxM = 2 * (dx - dy);
    int x, y, xEnd, yEnd;
    int p = 2 * dy - dx;
    int pM = 2 * dx - dy;
    if ((x2 - x1) == 0){
	if (y1 < y2) {
	    y = y1;
	    x = x1;
	    while (y < y2) {
		putpixel(x, y, 255);
		y++;
	    }
	    return;
	}
	else{
	    y = y1;
	    x = x1;
	    while (y > y2) {
		putpixel(x, y, 255);
		y--;
	    }
	    return;
	}
    }
    else if ((y2 - y1) == 0){
	if (x1 < x2) {
	    x = x1;
	    y = y1;
	    while(x < x2) {
		putpixel(x, y, 255);
		x++;
	    }
	    return;
	}
	else{
	    x = x2;
	    y = y1;
	    while(x < x1){
		putpixel(x, y, 255);
		x++;
	    }
	    return;
	}
    }
    else {
    if (x1 > x2) {
	x = x2;
	y = y2;
	xEnd = x1;
	yEnd = y1;
    }
    else {
	x = x1;
	y = y1;
	xEnd = x2;
	yEnd = y2;
    }
    putpixel (x, y, 255);
    if (m > 0 && m < 1) {
	if (mS >= 0) {
	    while(x < xEnd) {
		x++;
		if (p < 0) {
		    p += twoDy;
		}
		else {
		    y++;
		    p += twoDyDx;
		}
		putpixel(x, y, 255);
	    }
	}
	else {
	    while(x < xEnd) {
		x++;
		if (p < 0) {
		    p += twoDy;
		}
		else {
		    y--;
		    p += twoDyDx;
		}
		putpixel(x, y, 255);
	    }
	}
    }
    else {
	if (mS > 0) {
	    while(y < yEnd) {
		y++;
		if (pM < 0) {
		    pM += twoDyM;
		}
		else {
		    x++;
		    pM += twoDyDxM;
                }
                putpixel(x, y, 255);
            }
        }
        else {
            while(y > y1) {
                y--;
                if (pM < 0) {
                    pM += twoDyM;
                }
                else {
                    x++;
                    pM += twoDyDxM;
                }
                putpixel(x, y, 255);
            }
        }
    }
    }
}
void main () {
    int xa, ya, xb, yb,xc,yc,xd,yd;
    int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C://TURBOC3//BGI");
    printf("Enter the value of x1:\n");
    scanf("%d",&xa);
    printf("Enter the value of y1:\n");
    scanf("%d",&ya);
    printf("Enter the value of x2:\n");
    scanf("%d",&xb);
    printf("Enter the value of y2:\n");
    scanf("%d",&yb);
    printf("Enter the value of x3:\n");
    scanf("%d",&xc);
    printf("Enter the value of y3:\n");
    scanf("%d",&yc);
    clrscr();
    drawLine(xa,ya,xb,yb);
    drawLine(xb,yb,xc,yc);
    drawLine(xc,yc,xa,ya);
    getch();
}

#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
#define ROUND(a) ((int)(a + 0.5))
int image[1500][1500];
int yref ;
float th;
void drawLine(int,int,int,int);
void reflection (int *a, int *b) {
    *b = - (*b);
}
void ellipsePlotPoints(int xC, int yC, int x, int y){
    rotation(xC + x, yC + y,0,xC,yC);
    rotation(xC - x, yC + y,0,xC,yC);
    rotation(xC + x, yC - y,0,xC,yC);
    rotation(xC - x, yC - y,0,xC,yC);
}
void rotation(int a, int b, float theta, int xF, int yF) {

    float thetaP = theta * ((3.14)/180);
    float xPrime = xF +((a - xF) * cos(thetaP)) - ((b - yF) * sin(thetaP));
    float yPrime = xF + ((a - xF) * sin(thetaP)) + ((b - yF) * cos(thetaP));
    image[ROUND (xPrime)][ROUND (yPrime)] = 255;
}
void ellipseMidPoint(int xC, int yC, int Rx, int Ry) {
    int Rx2 = Rx * Rx;
    int Ry2 = Ry * Ry;
    int twoRx2 = 2 * Rx2;
    int twoRy2 = 2 * Ry2;
    int p;
    int x = 0;
    int y = Ry;
    int px = 0;
    int py = twoRx2 * y;
    ellipsePlotPoints(xC, yC, x, y);
    p = ROUND(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
    while(px < py) {
        x++;
        px += twoRy2;
        if (p < 0) {
            p += Ry2 + px;
        }
        else{
            y--;
            py -= twoRx2;
            p += Ry2 + px - py;
        }
        ellipsePlotPoints(xC, yC, x, y);
    }
    p =ROUND (Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y-1) * (y-1) - Rx2 * Ry2);
    while(y > 0) {
        y--;
        py -= twoRx2;
        if(p > 0) {
            p += Rx2 - py;
        }
        else {
            x++;
            px += twoRy2;
            p += Rx2 - py + px;
        }
        ellipsePlotPoints(xC, yC, x, y);
    }
}

int main (){
	int xc,a,rx,x1,x2,x3,x4,yc,b,ry,y1,y2,y3,y4,i,j,temp,ahalf,bhalf;
	int height = 1500, width = 1500;
	for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++)
            image[i][j] = 0;
    }
    yref = y1;
	printf("Enter the value of xc :\n");
	scanf("%d",&xc);
	printf("Enter the value of yc :\n");
	scanf("%d",&yc);
	printf("Enter the value of a :\n");
	scanf("%d",&a);
	printf("Enter the value of b :\n");
	scanf("%d",&b);
	printf("Enter the value of rx :\n");
	scanf("%d",&rx);
	printf("Enter the value of ry :\n");
	scanf("%d",&ry);
	ahalf = a / 2;
	bhalf = b / 2;
	x1 = xc - ahalf;
	y1 = yc - bhalf;
	x2 = xc + ahalf;
	y2 = y1;
	x3 = x2;
	y3 = yc + bhalf;
	x4 = x1;
	y4 = y3;
    FILE* pgmimg;
    pgmimg = fopen("shear.pgm", "wb");
    // Writing Magic Number to the File
    fprintf(pgmimg, "P2\n");
    // Writing Width and Height
    fprintf(pgmimg, "%d %d\n", width, height);
    // Writing the maximum gray value
    fprintf(pgmimg, "255\n");
    int count = 0;
    x1 = x1 + (1) * (y4 - (y1 + b / 2));
    x2 = x2 + (1) * (y4 - (y2 + b / 2));
    drawLine(x1,y1,x2,y2);
    drawLine(x2,y2,x3,y3);
    drawLine(x3,y3,x4,y4);
    drawLine(x4,y4,x1,y1);
    ellipseMidPoint(xc , yc, ry, rx);
    reflection(&xc,&yc);
    reflection(&x1,&y1);
    reflection(&x2,&y2);
    reflection(&x3,&y3);
    reflection(&x4,&y4);
    yc += yc + yc / 2;
    y1 += 100;
    y2 += 100;
    y3 += 100;
    y4 += 100;
    drawLine(x1,y1,x2,y2);
    drawLine(x2,y2,x3,y3);
    drawLine(x3,y3,x4,y4);
    drawLine(x4,y4,x1,y1);
    ellipseMidPoint(xc , 2 * (x2 - x1), ry, rx);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp = image[j][i];

            // Writing the gray values in the 2D array to the file
            fprintf(pgmimg, "%d ", temp);
        }
        fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);
	//closegraph();
    return 0;
}
void drawLine (int x1, int y1, int x2, int y2) {
	int dx, dy, steps,i,shx = 2;
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

    image[(int)x][(int)y] = 255;
	x = x + x_inc;
	y = y + y_inc;
	}
}

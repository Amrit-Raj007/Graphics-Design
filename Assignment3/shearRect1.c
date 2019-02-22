#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
#define ROUND(a) ((int)(a + 0.5))
int image[1000][1000];
void drawLine(int,int,int,int);
void ellipse(int xc,int yc,int rx,int ry)
{
    int x, y, p;
    x=0;
    y=ry;
    p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
    while((2*x*ry*ry)<(2*y*rx*rx))
    {
        image[xc+x][yc-y] = 255;
        image[xc-x][yc+y] = 255;
        image[xc+x][yc+y] = 255;
        image[xc-x][yc-y] = 255;

        if(p<0)
        {
            x=x+1;
            p=p+(2*ry*ry*x)+(ry*ry);
        }
        else
        {
            x=x+1;
            y=y-1;
            p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
        }
    }
    p=((float)x+0.5)*((float)x+0.5)*ry*ry+(y-1)*(y-1)*rx*rx-rx*rx*ry*ry;

    while(y>=0)
    {
        image[xc+x][yc-y] = 255;
        image[xc-x][yc+y] = 255;
        image[xc+x][yc+y] = 255;
        image[xc-x][yc-y] = 255;

        if(p>0)
        {
            y=y-1;
            p=p-(2*rx*rx*y)+(rx*rx);
        }
        else
        {
            y=y-1;
            x=x+1;
            p=p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
        }
    }

}

int main (){
	int xc,a,Rx,x1,x2,x3,x4,yc,b,Ry,y1,y2,y3,y4,i,j,temp,ahalf,bhalf;
	int height = 1000, width = 1000;
	for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++)
            image[i][j] = 0;
    }
	printf("Enter the value of xc :\n");
	scanf("%d",&xc);
	printf("Enter the value of yc :\n");
	scanf("%d",&yc);
	printf("Enter the value of a :\n");
	scanf("%d",&a);
	printf("Enter the value of b :\n");
	scanf("%d",&b);
	printf("Enter the value of rx :\n");
	scanf("%d",&Rx);
	printf("Enter the value of ry :\n");
	scanf("%d",&Ry);
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
    fprintf(pgmimg, "P2\n");
    fprintf(pgmimg, "%d %d\n", width, height);
    fprintf(pgmimg, "255\n");
    int count = 0;
    x1 = x1 + (1) * (y4 - (y1 + b / 2));
    x2 = x2 + (1) * (y4 - (y2 + b / 2));
    drawLine(x1,y1,x2,y2);
    drawLine(x2,y2,x3,y3);
    drawLine(x3,y3,x4,y4);
    drawLine(x4,y4,x1,y1);
    ellipse(xc , yc, Ry, Rx);
    drawLine(x1,-y1,x2,-y2);
    drawLine(x2,-y2,x3,-y3);
    drawLine(x3,-y3,x4,-y4);
    drawLine(x4,-y4,x1,-y1);
    ellipse(xc ,-yc, Ry, Rx);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp = image[j][i];
            fprintf(pgmimg, "%d ", temp);
        }
        fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);
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

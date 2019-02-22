#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
int image[1500][1500];
void flood(int x, int y, int new_col, int old_col)
{
    //printf("\n%d %d",x ,y);
    if (image[x][y] == old_col) {
        //printf("a");
        image[x][y] = new_col;


        flood(x + 1, y, new_col, old_col);
        // printf("b");
        flood(x - 1, y, new_col, old_col);
                //printf("c");
        flood(x, y + 1, new_col, old_col);
        //printf("d");
        flood(x, y - 1, new_col, old_col);
        //printf("e");
    }
    //printf("b");
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
    image[(int)x][(int)y] = 255;
	x = x + x_inc;
	y = y + y_inc;
	}
}
void circlePlotPointsLeftLeft (int xC, int yC, int x, int y, int radiuss)
{
    image[ yC + y][xC + x+(radiuss)]=255;
    image[ yC + y][xC - x+(radiuss)]=255;
    image[ yC + x][xC + y+(radiuss)]=255;
    image[ yC + x][xC - y+(radiuss)]=255;
}

void circlePlotPointsRightLeft (int xC, int yC, int x, int y, int r)
{
    image[yC - y][xC + x - (r)]=255;
    image[yC - y][xC - x - (r)]=255;
    image[yC - x][xC + y - (r)]=255;
    image[yC - x][xC - y - (r)]=255;
}
void circlePlotPointsLeftRight (int xC, int yC, int x, int y, int r)
{

    image[yC - y][xC + x + (r)]=255;
    image[yC - y][xC - x + (r)]=255;
    image[yC - x][xC + y + (r)]=255;
    image[yC - x][xC - y + (r)]=255;
}
void circlePlotPointsRightRight (int xC, int yC, int x, int y, int radiuss)
{
    image[ yC + y][xC + x-(radiuss)]=255;
    image[ yC + y][xC - x-(radiuss)]=255;
    image[ yC + x][xC + y-(radiuss)]=255;
    image[ yC + x][xC - y-(radiuss)]=255;
}
void circleMidpointLeft(int xC, int yC, int radius){
    int x=0;
    int y=radius;
    int p = 1 - radius;
    circlePlotPointsRightLeft(xC,yC,x,y, radius);
    circlePlotPointsLeftLeft(xC,yC,x,y, radius);
    while(x < y) {
	x++;
	if(p < 0){
	    p += 2 * x +1;
	}
	else{
	    y--;
	    p += 2 * (x - y) + 1;
	}
	circlePlotPointsRightLeft(xC, yC, x, y, radius);
	circlePlotPointsLeftLeft(xC, yC,x,y,radius);
    }
}
void circleMidpointRight(int xC, int yC, int radius){
    int x=0;
    int y=radius;
    int p = 1 - radius;
    circlePlotPointsRightRight(xC,yC,x,y, radius);
    circlePlotPointsLeftRight(xC,yC,x,y, radius);
    while(x < y) {
	x++;
	if(p < 0){
	    p += 2 * x +1;
	}
	else{
	    y--;
	    p += 2 * (x - y) + 1;
	}
	//circlePlotPoints(xC, yC,x,y);
	circlePlotPointsRightRight(xC, yC, x, y, radius);
	circlePlotPointsLeftRight(xC, yC,x,y,radius);
    }
}
int main () {
    int height = 1500, width = 1500, i, j, temp, x1, y1, x2, y2, h, rad, c, v, l;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++)
            image[i][j] = 0;
    }
    FILE* pgmimg;
    pgmimg = fopen("floodFill.pgm", "wb");
    fprintf(pgmimg, "P2\n");
    fprintf(pgmimg, "%d %d\n", width, height);
    fprintf(pgmimg, "255\n");
    printf("Enter the co-ordinates of the first point of the top line:\n");
    scanf("%d %d",&x1,&y1);
    //printf("Enter the co-ordinates of the second point of the top line:\n");
    //scanf("%d %d",&x2,&y2);
    printf("Enter the length:\n");
    scanf("%d", &l);
    drawLine(x1,y1,x1 + l,y1);

    //printf("Enter the height of the figure:\n");
    //scanf("%d",&h);
    h = 300;
    drawLine(x1,y1 + h,x1 + l,y1+h);
    rad = (int)(h / 4);
    circleMidpointLeft(y1 + (int)(h / 2),x1,rad);
    circleMidpointRight(y1 + (int)(h / 2),x1 + l,rad);

//    image[x1 - rad][y1 + rad] = 255;
//    image[x1][y1 + 2 * rad] = 255;
//    image[x1 + rad][y1 + 3 * rad] = 255;
//    image[x2 + rad][y2 + rad] = 255;
//    image[x2][y2 + 2 * rad] = 255;
//    image[x2 - rad][y2 + 3 * rad] = 255;
    c = x1 + (int)(l / 2);
    v = y1 + (int)(h / 2);

    flood(c, v, 200, 0);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp = image[j][i];
            fprintf(pgmimg, "%d ", temp);
        }
        fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);
}

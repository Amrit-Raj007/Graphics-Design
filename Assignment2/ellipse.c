#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
#define ROUND(a) ((int)(a + 0.5))
void rotation(int , int , float,int,int );
int image[1000][1000];
float th;
void ellipsePlotPoints(int xC, int yC, int x, int y){
    rotation(xC + x, yC + y,th,xC,yC);
    rotation(xC - x, yC + y,th,xC,yC);
    rotation(xC + x, yC - y,th,xC,yC);
    rotation(xC - x, yC - y,th,xC,yC);
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
int main() {
    int xC, yC,Rx,Ry;
    int width=1000, height = 1000;
    printf("Enter the value for xC:\n");
    scanf("%d",&xC);
    printf("Enter the value for yC:\n");
    scanf("%d",&yC);
    printf("Enter the value for Rx:\n");
    scanf("%d",&Rx);
    printf("Enter the value for Ry:\n");
    scanf("%d",&Ry);
    printf("Enter the value of theta:\n");
    scanf("%f",&th);
    FILE* pgmimg;
    pgmimg = fopen("ellipse.pgm", "wb");

    // Writing Magic Number to the File
    fprintf(pgmimg, "P2\n");

    // Writing Width and Height
    fprintf(pgmimg, "%d %d\n", width, height);

    // Writing the maximum gray value
    fprintf(pgmimg, "255\n");
    int count = 0;
    int i, j, temp;
    ellipseMidPoint(xC, yC, Rx, Ry);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp = image[j][i];

            // Writing the gray values in the 2D array to the file
            fprintf(pgmimg, "%d ", temp);
        }
        fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);

    return 0;


}

#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
int image[1000][1000];
void main () {
    int xc, yc, r, i, j, temp, x1, y1, x2, y2;
    printf("Enter the co-ordinatates:\n");
    scanf("%d %d",&xc,&yc);
    printf("Enter the radius:\n");
    scanf("%d",&r);
    int height = 1000, width = 1000;
	for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++)
            image[i][j] = 0;
    }
    x1 = xc - r;
    y1 = yc;
    x2 = xc + (x1 - xc) * cos(-60) - (y1 - yc) * sin(-60);
    y2 = yc + (x1 - xc) * sin(-60) + (y1 - yc) * cos(-60);
    image [x1][y1] = 255;
    image[xc][yc] = 255;
    image[x2][y2] = 255;
    FILE* pgmimg;
    pgmimg = fopen("poly_fill.pgm", "wb");
    fprintf(pgmimg, "P2\n");
    fprintf(pgmimg, "%d %d\n", width, height);
    fprintf(pgmimg, "255\n");
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

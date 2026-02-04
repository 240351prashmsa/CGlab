#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    float x1, y1, x2, y2;
    float x3, y3, x4, y4;
    float a, t;

    
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    printf("Enter coordinates of starting point (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter coordinates of ending point (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    printf("Enter angle for rotation (in degrees): ");
    scanf("%f", &a);


    setcolor(RED);
    line((int)x1, (int)y1, (int)x2, (int)y2);
    outtextxy((int)x2 + 5, (int)y2 + 5, "Original Line");


    t = a * (3.14 / 180);
    x3 = (x1 * cos(t)) - (y1 * sin(t));
    y3 = (x1 * sin(t)) + (y1 * cos(t));

    x4 = (x2 * cos(t)) - (y2 * sin(t));
    y4 = (x2 * sin(t)) + (y2 * cos(t));

    setcolor(GREEN);
    line((int)x3, (int)y3, (int)x4, (int)y4);
    outtextxy((int)x4 + 5, (int)y4 + 5, "Rotated Line");

    getch();
    closegraph();
    return 0;
}

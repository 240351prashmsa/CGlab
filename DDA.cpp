#include <stdio.h>
#include <graphics.h>
#include <cmath>

int myRound(float a);

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, steps, k;
    float xincr, yincr, x, y, dx, dy;

    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);

    initgraph(&gd, &gm, (char*)"");

    dx = x2 - x1;
    dy = y2 - y1;

    if (fabs(dx) > fabs(dy))
        steps = (int)fabs(dx);
    else
        steps = (int)fabs(dy);

    xincr = dx / steps;
    yincr = dy / steps;

    x = x1;
    y = y1;

    putpixel(myRound(x), myRound(y), WHITE);

    for (k = 1; k <= steps; k++)
    {
        delay(100);
        x += xincr;
        y += yincr;
        putpixel(myRound(x), myRound(y), WHITE);
    }

    outtextxy(200, 20, (char*)"DDA Line Drawing Algorithm");
    outtextxy(x1 + 5, y1 - 5, (char*)"(x1,y1)");
    outtextxy(x2 + 5, y2 + 5, (char*)"(x2,y2)");

    getch();
    closegraph();
    return 0;
}

int myRound(float a)
{
    return (int)(a + 0.5f);
}

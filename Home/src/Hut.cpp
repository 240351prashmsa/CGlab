#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

/* Global variables */
int xc, yc;
float x, y;

void disp();

int main()
{
    int Rx, Ry;
    float p1, p2;
    int gd = DETECT, gm;

    char data[] = "C:\\MinGW\\lib\\libbgi.a";   // BGI path

    initgraph(&gd, &gm, data);

    printf("Enter the centre point (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter Rx and Ry: ");
    scanf("%d %d", &Rx, &Ry);

    /* -------- REGION 1 -------- */
    x = 0;
    y = Ry;

    p1 = (Ry * Ry) - (Rx * Rx * Ry) + (Rx * Rx) / 4.0;

    disp();

    while ((2 * Ry * Ry * x) <= (2 * Rx * Rx * y))
    {
        x++;

        if (p1 < 0)
        {
            p1 = p1 + (2 * Ry * Ry * x) + (Ry * Ry);
        }
        else
        {
            y--;
            p1 = p1 + (2 * Ry * Ry * x) - (2 * Rx * Rx * y) + (Ry * Ry);
        }

        disp();
    }

    /* -------- REGION 2 -------- */
    p2 = (Ry * Ry) * (x + 0.5) * (x + 0.5)
       + (Rx * Rx) * (y - 1) * (y - 1)
       - (Rx * Rx * Ry * Ry);

    while (y >= 0)
    {
        y--;

        if (p2 > 0)
        {
            p2 = p2 + (Rx * Rx) - (2 * Rx * Rx * y);
        }
        else
        {
            x++;
            p2 = p2 + (2 * Ry * Ry * x)
                     - (2 * Rx * Rx * y)
                     + (Rx * Rx);
        }

        disp();
    }

    getch();
    closegraph();
    return 0;
}

/* Plot all four symmetric points */
void disp()
{
    delay(5);
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}
 
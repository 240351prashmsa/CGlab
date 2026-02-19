#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void flood(int x, int y, int fill_col, int old_col);

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    rectangle(50, 50, 200, 200);

    flood(100, 100, BLUE, BLACK);

    getch();
    closegraph();
    return 0;
}

void flood(int x, int y, int fill_col, int old_col)
{
    if (x < 0 || y < 0 || x > getmaxx() || y > getmaxy())
        return;

    if (getpixel(x, y) == old_col)
    {
        putpixel(x, y, fill_col);

        flood(x + 1, y, fill_col, old_col);
        flood(x - 1, y, fill_col, old_col);
        flood(x, y + 1, fill_col, old_col);
        flood(x, y - 1, fill_col, old_col);
    }
}

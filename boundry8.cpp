#include <stdio.h>
#include <graphics.h>

void boundary_fill(int x, int y, int fcolor, int bcolor)
{
    if (x < 0 || y < 0 || x > getmaxx() || y > getmaxy())
        return;

    int current = getpixel(x, y);

    if ((current != bcolor) && (current != fcolor))
    {
        putpixel(x, y, fcolor);

        boundary_fill(x + 1, y, fcolor, bcolor);
        boundary_fill(x - 1, y, fcolor, bcolor);
        boundary_fill(x, y + 1, fcolor, bcolor);
        boundary_fill(x, y - 1, fcolor, bcolor);
    }
}

int main()
{
    int x, y, fcolor, bcolor;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    printf("Enter seed point (x y): ");
    scanf("%d %d", &x, &y);

    printf("Enter boundary color (0-15): ");
    scanf("%d", &bcolor);

    printf("Enter fill color (0-15): ");
    scanf("%d", &fcolor);

    setcolor(bcolor);
    rectangle(50, 50, 100, 100);

    boundary_fill(x, y, fcolor, bcolor);

    getch();
    closegraph();
    return 0;
}




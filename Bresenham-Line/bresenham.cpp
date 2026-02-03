#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // BGI path can be empty if using WinBGI

    int x1, y1, x2, y2;
    int dx, dy, p, x, y;

    printf("Enter the x-coordinate of the first point: ");
    scanf("%d", &x1);
    printf("Enter the y-coordinate of the first point: ");
    scanf("%d", &y1);
    printf("Enter the x-coordinate of the second point: ");
    scanf("%d", &x2);
    printf("Enter the y-coordinate of the second point: ");
    scanf("%d", &y2);

    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;

    p = 2 * dy - dx;

    while (x <= x2) {
        putpixel(x, y, 7);  // Draw pixel
        if (p >= 0) {
            y++;
            p = p + 2 * dy - 2 * dx;
        } else {
            p = p + 2 * dy;
        }
        x++;
    }

    getch();
    closegraph();
    return 0;
}
 

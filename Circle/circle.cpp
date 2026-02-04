#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void draw_circle(int, int, int);
void symmetry(int, int, int, int);

int main() {
    int xc, yc, R;
    int gd = DETECT, gm;

    // Use the MinGW BGI path
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    printf("Enter the center of the circle:\n");
    printf("Xc = ");
    scanf("%d", &xc);
    printf("Yc = ");
    scanf("%d", &yc);

    printf("Enter the radius of the circle: ");
    scanf("%d", &R);

    draw_circle(xc, yc, R);

    getch();
    closegraph();
    return 0;
}

void draw_circle(int xc, int yc, int rad) {
    int x = 0;
    int y = rad;
    int p = 1 - rad;

    symmetry(x, y, xc, yc);

    for (x = 0; y > x; x++) {
        if (p < 0)
            p += 2 * x + 3;
        else {
            p += 2 * (x - y) + 5;
            y--;
        }
        symmetry(x, y, xc, yc);
        delay(50);
    }
}

void symmetry(int x, int y, int xc, int yc) {
    putpixel(xc + x, yc - y, GREEN);
    putpixel(xc + y, yc - x, GREEN);
    putpixel(xc + y, yc + x, GREEN);
    putpixel(xc + x, yc + y, GREEN);
    putpixel(xc - x, yc + y, GREEN);
    putpixel(xc - y, yc + x, GREEN);
    putpixel(xc - y, yc - x, GREEN);
    putpixel(xc - x, yc - y, GREEN);
}

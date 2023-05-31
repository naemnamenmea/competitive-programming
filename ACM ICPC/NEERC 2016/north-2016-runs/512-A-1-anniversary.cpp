#include "stdio.h"
#include <fstream>

int main()
{
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);

    int w, h;
    int x1, y1, x2, y2;
    int Ax, Ay;
    int Bx, By;
    scanf("%d%d%d%d%d%d", &w, &h, &Ax, &Ay, &Bx, &By);

    if(Ax != Bx)
    {
        Ay = 0;
        By = h;
    }
    else
    {
        Ax = 0;
        Bx = w;
    }

    printf("%d %d %d %d", Ax, Ay, Bx, By);
}

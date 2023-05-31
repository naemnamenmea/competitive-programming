#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    FILE * fin = fopen("anniversary.in", "r");
    FILE * fout = fopen("anniverrsary.out", "w");

    int w, h, ax, ay, bx, by, sx, sy, ex, ey;
    fscanf(fin, "%d %d %d %d %d %d", &w, &h, &ax, &ay, &bx, &by);

    if (ax == bx) {
        sy = ay;
        ey = by;
        sx = 0;
        ex = w;
    } else {
        sx = ax;
        ex = bx;
        sy = 0;
        ey = h;
    }

    fprintf(fout, "%d %d %d %d", sx, sy, ex, ey);
    return 0;
}

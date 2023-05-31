#include "stdio.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Pair
{
    int x;
    int y;
};

int main()
{
    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);

    int H, W, h, w;
    int foldes = 0;
    scanf("%d%d%d%d", &W, &H, &w, &h);
    if( ((h > H) && (h > W)) || ((w > H) && (w > W)) )
    {
        printf("-1");
        return 0;
    }

    if((h > H) || (w > W))
    {
        int buf = h;
        h = w;
        w = buf;
    }

    while( !((h == H) && (w == W)) )
    {
        if(h != H)
        {
            if(h < (H/2 + H%2))
                H = (H/2 + H%2);
            else
                H = h;
            foldes++;
        }

        if(w != W)
        {
            if(w < (W/2 + W%2))
                W = (W/2 + W%2);
            else
                W = w;
            foldes++;
        }
    }

    printf("%d", foldes);

    fclose(stdin);
    fclose(stdout);

    return 0;
}







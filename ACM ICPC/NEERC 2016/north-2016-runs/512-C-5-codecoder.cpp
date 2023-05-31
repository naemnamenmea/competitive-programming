#include "stdio.h"
#include <fstream>

struct Pair
{
    int x;
    int y;
};

int main()
{
    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);

    Pair* arr;
    int len;
    scanf("%d", &len);
    arr = new Pair[len];

    for(int i = 0; i < len; i++)
        scanf("%d%d", &arr[i].x, &arr[i].y);

    Pair rateBuf;
    for(int i = 0; i < len; i++)
    {
        rateBuf.x = 0;
        rateBuf.y = 0;
        for(int j = 0; j < len; j++)
        {
            if(i == j)
                continue;
            else
            {
                if(arr[i].x >= arr[j].x)
                    rateBuf.x++;
                if(arr[i].y >= arr[j].y)
                    rateBuf.y++;
            }
        }
        printf("%d\n", (rateBuf.x > rateBuf.y) ? rateBuf.x : rateBuf.y);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

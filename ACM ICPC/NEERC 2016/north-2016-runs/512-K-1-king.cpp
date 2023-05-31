#include "stdio.h"
#include <fstream>

struct Date
{
    int d;
    int m;
    int y;
};

int main()
{
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);

    bool hasSon = false;
    int len, index = -1;
    Date* datesArr;

    Date kingDate, sonDate, bufDate;
    scanf("%d%d%d", &kingDate.d, &kingDate.m, &kingDate.y);
    kingDate.y -= 18;

    scanf("%d", &len);
    datesArr = new Date[len];

    for(int i = 0; i < len; i++)
    {
        scanf("%d%d%d", &bufDate.d, &bufDate.m, &bufDate.y);
        if( (bufDate.y < kingDate.y) ||
            ((bufDate.y == kingDate.y) && (bufDate.m < kingDate.m) ) ||
            ((bufDate.y == kingDate.y) && (bufDate.m == kingDate.m) && (bufDate.d <= kingDate.d)))
        {
            if(!hasSon ||
                (bufDate.y > sonDate.y) ||
                ((bufDate.y == sonDate.y) && (bufDate.m > sonDate.m) ) ||
                ((bufDate.y == sonDate.y) && (bufDate.m == sonDate.m) && (bufDate.d > sonDate.d)))
            {
                sonDate = bufDate;
                hasSon = true;
                index = i+1;
            }
        }
    }

    printf("%d", index);

    fclose(stdin);
    fclose(stdout);
}






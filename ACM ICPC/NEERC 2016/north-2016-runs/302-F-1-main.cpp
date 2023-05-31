#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   freopen("folding.in", "r", stdin);
   freopen("folding.out", "w", stdout);
    int w, h,max1, nw, nh, max2, min2, min1, c(0);

    scanf("%d %d", &w, &h);

    scanf("%d %d", &nw, &nh);
     max1 = max(w, h);
    max2 = max(nw, nh);
    min1 = min(w, h);
    min2 = min (nw, nh);
    if (max1 < max2 || min1 < min2) {
        printf("%d", -1);
    }
    else {
    if (w % 2 != 0)
        w++;
    if (h % 2 != 0)
        h++;




        while (max1 > max2) {
            max1 /= 2;
            c++;
        }
        while (min1 > min2) {
            min1 /= 2;
            c++;
        }
        printf("%d", c);
    }
    return 0;
}

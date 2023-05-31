#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
   freopen("folding.in", "r", stdin);
   freopen("folding.out", "w", stdout);
    int w, h,max1, nw, nh, max2, min2, min1, c1(99999999), c2(99999999);

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
         if (w >= nw && h >= nh) {
            int p = w/nw;
            if (w % nw != 0)
                p++;
            double c11 = log2(p);
            c1 = ceil(c11);
            p = h/nh;
            if (h % nh != 0)
                p++;
            c1 += ceil(log2(p));
        }


        if (w >= nh && h >= nw) {
            int p = w/nh;
            if (w % nh != 0)
                p++;
            c2 = ceil(log2(p));
            p = h/nw;
            if (h % nw != 0)
                p++;
            c2 += ceil(log2(p));
        }
       // cout << c1 << " " << c2 << endl;
        cout << min(c1, c2);

    }
    return 0;
}

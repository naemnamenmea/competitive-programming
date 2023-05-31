#include <iostream>
#include <cmath>
#include<cstdio>

using namespace std;

int main()
{
   freopen("folding.in","r",stdin);
   freopen("folding.out","w",stdout);
   long w, h, a, b, c, x, y;
   cin >> w >> h >> a >> b;
   if (w < h) {c = h; h = w; w = c;}
   if (a < b) {c = a; a = b; b = c;}
   if ((w < a) || (h < b)) {printf("-1");}
   else
   {
        if (log2(w/a) - trunc(log2(w/a))) {x = trunc(log2(w/a));}
        else {x = trunc(log2(w/a)) + 1;}
        if (log2(h/b) - trunc(log2(h/b))) {y = trunc(log2(h/b));}
        else {y = trunc(log2(h/b)) + 1;}
        cout << x + y;
    }
    return 0;
}

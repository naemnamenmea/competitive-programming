#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("anniversary.in" , "r", stdin);
    freopen("anniversary.out" , "w", stdout);

    int w, h , ax, ay, bx, by;

    cin >> w >> h >> ax >> ay >> bx >> by;

    if (h < w){
        if (ax < bx) {
            swap(ax ,bx);
            swap(ay, by);
        }

        if (ax == bx){
            printf("%d %d %d %d", ax - 1, 0, ax + 1, h);
        } else if (ay == by) printf("%d %d %d %d", ax, 0, bx, h);
            else printf("%d %d %d %d", bx, 0, ax, h);

    } else {
        if (ax < bx) {
            swap(ax ,bx);
            swap(ay, by);
        }

        if (ay == by)  printf("%d %d %d %d", ax, 0, bx, h);

        else if (ax == bx) printf ("%d %d %d %d", 0, ay,w, by);
         else printf("%d %d %d %d", ay, 0, by, h);

    }

    return 0;
}

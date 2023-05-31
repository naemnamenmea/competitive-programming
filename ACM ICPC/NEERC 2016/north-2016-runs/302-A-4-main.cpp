#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("anniversary.in" , "r", stdin);
    freopen("anniversary.out" , "w", stdout);

    int w, h , ax, ay, bx, by;

    cin >> w >> h >> ax >> ay >> bx >> by;

    if (h <= w){
        if (ax <= bx) {
            swap(ax ,bx);
            swap(ay, by);
        }

        if (ax == bx){
            printf("%d %d %d %d", ax - 1, 0, ax + 1, h);
        } else printf("%d %d %d %d", ax, 0, bx, h);

    } else {
        if (ax <= bx) {
            swap(ax ,bx);
            swap(ay, by);
        }

        if (ay == by){
            printf("%d %d %d %d", 0, ax - 1, h, ax + 1);
        } else printf("%d %d %d %d", 0, ax, h , bx);

    }

    return 0;
}

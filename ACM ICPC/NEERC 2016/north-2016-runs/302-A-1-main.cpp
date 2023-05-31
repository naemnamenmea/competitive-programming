#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("anniversary.in" , "r", stdin);
    freopen("anniversary.out" , "w", stdout);

    int w, h , ax, ay, bx, by;

    cin >> w >> h >> ax >> ay >> bx >> by;

    if (ax < bx){
        swap(ax, bx);
        swap(ay, by);
    }

    if (ax == bx){
        printf("%d %d %d %d", ax - 1, 0, bx + 1, h);
    } else if (ay == by) printf("%d %d %d %d", ax, 0, bx, h);
    else printf("%d %d %d %d",ax, 0, bx, h);


    return 0;
}

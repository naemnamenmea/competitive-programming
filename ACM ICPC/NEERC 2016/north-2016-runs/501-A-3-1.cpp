#include <bits/stdc++.h>

using namespace std;

#define TASK "anniversary"

int main() {
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int w, h, ax, ay, bx, by;
    cin >> w >> h >> ax >> ay >> bx >> by;
    if (ax != bx)
    {
        printf("%d %d %d %d\n", min(ax, bx), 0, min(ax, bx) + 1, h);
        return 0;
    }
    if (ay != by)
    {
        printf("%d %d %d %d\n", 0, min(ay, by), w, min(ay, by) + 1);
        return 0;
    }

    return 0;
}
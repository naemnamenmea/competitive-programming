#include <bits/stdc++.h>

using namespace std;

#define TASK "anniversary"

int main() {
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int w, h, ax, ay, bx, by;
    cin >> w >> h >> ax >> ay >> bx >> by;
    if (ax != ay)
    {
        printf("%d %d %d %d\n", min(ax, ay), 0, min(ax, ay) + 1, h);
        return 0;
    }
    if (bx != by)
    {
        printf("%d %d %d %d\n", 0, min(bx, by), w, min(bx, by) + 1);
        return 0;
    }

    return 0;
}
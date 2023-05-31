#include <bits/stdc++.h>

using namespace std;

#define TASK "folding"

const int inf= 1.01e9;

int res = inf;

int get(int x, int y)
{
    if (x <= y) return 0;
    return get(x, 2 * y) + 1;
}

void solve(int a, int b, int c, int d)
{
    if (a < c || b < d) return;
    res = min(res, get(a, c) + get(b, d));
}

int main() {
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    solve(a, b, c, d);
    solve(a, b, d, c);

    if (res == inf) res = -1;
    printf("%d\n", res);


    return 0;
}
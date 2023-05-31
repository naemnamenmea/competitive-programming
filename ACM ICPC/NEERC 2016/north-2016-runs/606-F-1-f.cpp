#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int solve(int a, int b)
{
    if (a < b)
        return INF;
    int w = 0;
    while (a > b)
    {
        ++w;
        (++a) /= 2;
    }
    return w;
}
                     
int main() {
    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = min(solve(x1, x2) + solve(y1, y2), solve(x1, y2) + solve(y1, x2));
    if (ans >= INF)
        cout << "-1\n";
    else
        cout << ans << "\n";
}

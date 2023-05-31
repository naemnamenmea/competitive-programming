#include <bits/stdc++.h>

using namespace std;

#define FNAME "king" 

const int MONTHS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int DELTA = 6570;

int convert(int d, int m, int y)
{
    int res = 0;
    res += (y - 1) * 365;
    for (int i = 0; i < m - 1; i++)
        res += MONTHS[i];
    res += d; 
    return res;
}

int main()
{
#ifdef FNAME
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    int d0, m0, y0, n;
    cin >> d0 >> m0 >> y0 >> n;
    int death = convert(d0, m0, y0);

    int ans = INT_MAX, res = -1;

    for (int i = 0; i < n; i++) {
        int d, m, y;
        cin >> d >> m >> y;
        int dt = convert(d, m, y);
        if (death - dt < DELTA) continue;
        if (death - dt < ans) {
            ans = death - dt;
            res = i + 1;
        }
    }

    cout << res;
    return 0; 
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200500;
int n;
int x[N], y[N];
ll cnt[2][2][2];

int main() {
    freopen("integral.in", "r", stdin);
    freopen("integral.out", "w", stdout);
    
    scanf("%d", &n);
    ll ans = 0;
    int pa = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", x+i, y+i);
        x[i] = abs(x[i]);
        y[i] = abs(y[i]);
        x[i] %= 2;
        y[i] %= 2;

        if (i >= 1)
        {
            pa += x[i-1]*y[i] + x[i]*y[i-1];
            pa %= 2;
        }
                
        for (int xp = 0; xp <= 1; ++xp)
            for (int yp = 0; yp <= 1; ++yp)
                ans += cnt[xp][yp][(pa + x[i]*yp + xp*y[i]) % 2];

        ++cnt[x[i]][y[i]][pa];
    }
    
    if ((pa + x[0]*y[n-1] + x[n-1]*y[0]) % 2 == 1)
        cout << "0\n";
    else
        cout << ans - n << "\n";
}

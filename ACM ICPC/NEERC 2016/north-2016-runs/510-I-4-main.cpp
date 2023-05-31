#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
 
#ifdef local
    #define files
    #define task "file"
#else
    #define files
    #define task "integral"
#endif
 
const int N = 200200;
 
int cnt[16], n, x[N], y[N];
 
int triag[2][2][N];
int pref[2][2][N];
int dp[2][2][N][2];
 
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
#ifdef files
    freopen(task".in", "r", stdin); 
    freopen(task".out", "w", stdout);   
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int x0 = 0; x0 < 2; x0++)
            for (int y0 = 0; y0 < 2; y0++)
            {   
                int dx1 = abs(x[i] - x0) & 1;
                int dy1 = abs(y[i] - y0) & 1;
                int ii = (i+1) % n;
                int dx2 = abs(x[ii] - x0) & 1;
                int dy2 = abs(y[ii] - y0) & 1;
                triag[x0][y0][i] = (dx1 * dy2 + dx2 * dy1) & 1; 
                pref[x0][y0][i] = (triag[x0][y0][i] + (i > 0 ? pref[x0][y0][i-1] : 0)) & 1;
                for (int t = 0; t < 2; t++)
                    dp[x0][y0][i][t] = (i > 0 ? dp[x0][y0][i-1][t] : (0)) + (pref[x0][y0][i] == t ? 1 : 0);
 
            }
    }
    long long ans = 0;
 
    for (int i = 0; i < n; i++)
    {
        int x0 = abs(x[i]) & 1;
        int y0 = abs(y[i]) & 1;
        if (pref[x0][y0][n-1] == 1)
        	continue; 
         
        int cur = pref[x0][y0][i];
        if (i > 1)
            ans += dp[x0][y0][i-2][cur];

        ans += dp[x0][y0][n-(i > 0 ? 1 : 2)][cur] - dp[x0][y0][i][cur];
             
    }   
 
    cout << ans - 2*n << "\n";
    return 0;
}
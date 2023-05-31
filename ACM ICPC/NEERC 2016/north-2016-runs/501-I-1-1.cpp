#include <bits/stdc++.h>

using namespace std;

#define TASK "integral"

const int N = 4e5 + 10;

int X[N], Y[N];
int S[N];
int C[N];

#define forn(i, n) for (int i = 0; i < (n); ++i)

int main() {
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%d%d", X + i, Y + i);
    forn(i, n) X[i] &= 1;
    forn(i, n) Y[i] &= 1;

    long long res = 0;
    forn(i1, 2) forn(i2, 2)
    {
        forn(ii, 2 * n)
        {
            int i = ii % n;
            int j = (i + 1) % n;
            S[ii + 1] = S[ii]  + (((X[i] - i1) * (Y[j] - i2) - (X[j] - i1) * (Y[i] - i2)) & 1);
            C[ii + 1] = C[ii] + (S[ii + 1] % 2 == 0);
        }
        if (S[n] % 2 != 0) continue;
        
        forn(i, n) if (X[i] == i1 && Y[i] == i2)
        {
            int val = C[i + n] - C[i];
            if (S[i] % 2) val = n - val;
            res += val - 3;
        }
    }
    printf("%I64d\n", res / 2);
            

        

    return 0;
}
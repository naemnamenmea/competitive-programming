#include "bits/stdc++.h"

using namespace std;

int const N = 200200;
pair<int, int> a[N];
int p[N];
int s[N];

long long m[2][2][2];

void update(int x) {
    m[a[x].first][a[x].second][s[x]]++;    
}

long long calc(int i) {
    long long ans = 0;
    for (int f = 0; f < 2; f++) {
        for (int ss = 0; ss < 2; ss++) {
            for (int x = 0; x < 2; x++) {
                if ((s[i] + x + a[i].first * ss + a[i].second * f) % 2 == 0) {
                    ans += m[f][ss][x];
                }
            }
        }
    }
    return ans;
}

int main() {
    freopen("integral.in", "r", stdin);
    freopen("integral.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x = abs(x)
        y = abs(y)
        a[i] = {x % 2, y % 2};
    }
    for (int i = 1; i < n; i++) {
        p[i] = a[i - 1].first * a[i].second - a[i - 1].second * a[i].first;
        p[i] = (p[i] + 10) % 2;
        s[i] = (s[i - 1] + p[i]) % 2;
    }
    long long ans = 0;
    for (int i = 2; i < n; i++) {
        update(i - 2);
        ans += calc(i);                
    }
    if ((s[n - 1] + s[0] + a[0].first * a[n - 1].second + a[0].second * a[n - 1].first) % 2 == 0)  {
        cout << ans - 1 << endl;
    } else {
        cout << 0 << endl;  
    }                         
}
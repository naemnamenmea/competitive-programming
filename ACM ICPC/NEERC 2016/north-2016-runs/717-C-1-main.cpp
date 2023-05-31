#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;

#define push_back pb

const int MAXN = 100 * 1000 + 1;

int ans[MAXN];
piii guys[MAXN];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> guys[i].first.first >> guys[i].first.second;
        guys[i].second = i;
    }
    sort(guys, guys + n);
    int p = 0;
    for (int i = 0; i < n - 1; i++) {
        if (guys[i].first.first < guys[i + 1].first.first && guys[i].first.second < guys[i + 1].first.second) {
            for (int j = p; j <= i; j++)
                ans[guys[j].second] = i;      
            p = i + 1;
        }
    }
    for (int j = p; j <= n - 1; j++)
        ans[guys[j].second] = n - 1;
    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "codecoder"
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    solve();
    return 0;
}
#define FNAME "codecoder"

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (n); i++)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin() v.end()

using namespace std;

typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int M = 1e5 + 100;

vector<pair<int, int> > ga, gb;
vector<int> g[M];
int a[M], b[M];
int pos[M];
int ans[M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        ga.pb({a[i], i});
        gb.pb({b[i], i});
    }
    sort(ga.begin(), ga.end()); reverse(ga.begin(), ga.end());
    sort(gb.begin(), gb.end()); reverse(gb.begin(), gb.end());

    for (int i = 0; i < n; i++) pos[ga[i].second] = i;
    for (int i = 0; i < n - 1; i++) {
        if (pos[gb[i].second] < pos[gb[i + 1].second]) continue;
        g[pos[gb[i].second]].pb(pos[gb[i + 1].second]);
    }
    int cur = n - 1;
    int last = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        for (auto ps : g[i]) cur = min(cur, ps);
        if (cur == i) {
            for (int j = i; j <= last; j++) {
                ans[ga[j].second] = n - 1 - last + (last - i + 1);
            }    
            cur = i - 1;
            last = i - 1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] - 1 << endl;

    return 0;
}
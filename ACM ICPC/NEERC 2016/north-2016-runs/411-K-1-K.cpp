#define FNAME "king"

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

int D, M, Y, n;
pair <pair <int, int> , pair <int, int> > a[10000];

int main() {
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);

    scanf("%d%d%d", &D, &M, &Y);
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d%d", &a[i].second.first, &a[i].first.second, &a[i].first.first);
        a[i].second.second = i;
    }
    sort(a, a + n);
    reverse(a, a + n);
    forn(i, n) {
        if (Y - a[i].first.first < 18) continue;
        if (Y - a[i].first.first > 18) {
            printf("%d\n", a[i].second.second + 1);
            return 0;
        }
        if (M < a[i].first.second) continue;
        if (M > a[i].first.second) {
            printf("%d\n", a[i].second.second + 1);
            return 0;
        }
        if (D >= a[i].second.first) {
            printf("%d\n", a[i].second.second + 1);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
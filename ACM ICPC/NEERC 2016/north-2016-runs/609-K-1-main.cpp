#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define forab(i,a,b) for( int i = (a); i < (b); i++)
#define forn(i,n) forab(i,0,n)

bool great(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 != y2) {
        return y1 > y2;
    }
    if (m1 != m2)
        return m1 > m2;
    return d1 > d2;
}

int main()
{
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("king.in", "r", stdin); freopen("king.out", "w", stdout);

    int dd, mm, yy;
    cin >> dd >> mm >> yy;

    int ans = -1;

    int cd, cm, cy;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d, m, y;
        cin >> d >> m >> y;
        if (yy - y > 18 || (yy - y == 18 && (m < mm || (m == mm && d <= dd)))) {
            if (ans == -1 || great(d, m, y, cd, cm, cy)) {
                ans = i + 1;
                cd = d;
                cm = m;
                cy = y;
            }
        }
    }
    cout << ans;
    return 0;
}

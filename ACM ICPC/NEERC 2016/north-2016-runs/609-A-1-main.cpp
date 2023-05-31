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



int main()
{
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("anniversary.in", "r", stdin); freopen("anniversary.out", "w", stdout);

    int w, h, ax, ay, bx, by;
    cin >> w >> h >> ax >> ay >> bx >> by;

    if (abs(ax - bx) > 1) {
        cout << min(ax, bx) + 1 << ' ' << 0 << ' ' << min(ax, bx) + 1 << ' ' << h << endl;
    } else if (abs(ay - by) > 1) {
        cout << 0 << ' ' << min(ay, by) + 1 << ' ' << w << ' ' << min(ay, by) + 1 << endl;
    } else if (abs(ax - bx) == 1) {
        cout << min(ax, bx) << ' ' << 0 << ' ' << max(ax, bx) << ' ' << h << endl;
    } else {
        cout << 0 << ' ' << min(ay, by) << ' ' << w << ' ' << max(ay, by) << endl;
    }


    return 0;
}

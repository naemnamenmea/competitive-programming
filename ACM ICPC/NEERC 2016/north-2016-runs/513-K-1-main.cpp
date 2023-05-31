#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int maxn = (1e5);
int a[maxn];
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);

    int d, m, y;
    cin >> d >> m >> y;
    int r = y * 365;
    rep(i, m)
        r += month[i];
    r += d;
    int n;
    cin >> n;
    rep(i, n){
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = z * 365;
        rep(j, y)
            a[i] += month[j];
        a[i] += x;
        //cout << i << " " << a[i] << endl;
    }

    int mi = (1e9);
    int j = -2;
   // cout << "ANS " << r - 18 * 365 << endl;
    rep(i, n)
        if (a[i] <= r - 18 * 365 && a[i] < mi){
            a[i] = mi;
            j = i;
        }

    cout << j + 1;

    return 0;
}

/*

22 10 2016
7
28 2 1999
22 7 1995
21 10 1998
23 10 1998
3 9 2000
1 4 2013
17 12 2004

22 10 2016
1
23 10 1998

*/

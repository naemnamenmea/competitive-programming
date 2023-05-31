#include <bits/stdc++.h>

using namespace std;

typedef long long lol;

#define foi freopen("king.in", "r", stdin);
#define foo freopen("king.out", "w", stdout);

int main()
{
    foi;
    foo;
    lol dk, mk, yk;
    cin >> dk >> mk >> yk;
    lol n;
    cin >> n;
    vector <lol> d, m, y;
    for (lol i = 0; i < n ; ++i)
    {
        lol di, mi, yi;
        cin >>  di  >>  mi  >>  yi;
        d.push_back(di);
        m.push_back(mi);
        y.push_back(yi);
    }
    lol ans = -1;
    lol kd  =   dk, km  =   mk, ky  =   yk;
    for (lol i = 0; i < n; ++i)
    {
        if (    (yk - y[i]) < 18)
            {
                goto shame;
            }
        if (    (ky - y[i]) >= 18 ) {

                if (    (km - m[i]) == 0) {
                    if (    (kd - d[i]) >= 0) {
                        ans = i + 1;
                        goto shame;
                    }
                }
                if (    (km - m[i]) > 0) {
                    ans = i + 1;
                    goto shame;
                }
        }
        shame: ;
    }
    cout << ans;
    return 0;
}

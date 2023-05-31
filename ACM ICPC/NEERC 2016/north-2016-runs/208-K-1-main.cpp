#include <bits/stdc++.h>

using namespace std;

struct date
{
    int y, m, d, id;
    read(int a)
    {
        cin >> d >> m >> y;
        id = a;
    }
    bool operator<(const date  & a) const
    {
        return  (y > a.y) ||
                (y == a.y) && (m > a.m) ||
                (y == a.y) && (m == a.m) && (d > a.d);
    }
};

date k, q;
int n;
set<date> a;

int main()
{
//##################################
#ifndef DEBUG
    #define prob "king"
    freopen(prob ".in",  "r", stdin);
    freopen(prob ".out",  "w", stdout);
#endif
//##################################
//##################################
#ifdef DEBUG
    freopen("../input.txt",  "r", stdin);
    freopen("../output.txt",  "w", stdout);
    //freopen("../debug.txt",  "w", stderr);
#endif
//##################################
    k.read(0);
    q.m = k.m;
    q.d = k.d + 1;
    q.y = k.y - 18;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        date x;
        x.read(i);
        a.insert(x);
    }
    for (auto i : a)
        if (q < i)
        {
            cout << i.id << endl;
            return 0;
        }
    cout << -1 << endl;
    return 0;
}

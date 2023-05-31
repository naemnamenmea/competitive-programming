#include <bits/stdc++.h>

using namespace std;

struct node
{
    int first, second;
    node(int a, int b)
    {
        first = a;
        second = b;
    }
    bool operator<(node const & a) const
    {
        return first < a.first;
    }
};

int n, q, prv, w[123456];
set<node> a, b;
unordered_set<int> p[100100];
unordered_set<int> v;

int main()
{
//##################################
#ifndef DEBUG
    #define prob "codecoder"
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.insert(node(x, i));
        b.insert(node(y, i));
    }
    q = 0;
    prv = -1;
    for (auto i : a)
        if (i.first != prv)
        {
            w[i.second] += q;
            q++;
            prv = i.first;
            v.insert(i.second);
            p[i.second] = v;
        }

    q = 0;
    prv = -1;
    v.clear();
    for (auto i : b)
        if (i.first != prv)
        {
            q++;
            prv = i.first;
            v.insert(i.second);
            for (auto j : v)
                if (!p[i.second].count(j))
                    w[i.second]++;
        }

    for (int i = 0; i < n; i++)
        cout << w[i] << endl;
    return 0;
}

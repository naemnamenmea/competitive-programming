#include <bits/stdc++.h>

using namespace std;

int n, q, w[100100];
map<int, vector<int>> a;
unordered_set<int> used;
bool t[100100];

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
        a[x].push_back(i);
        a[y].push_back(i);
    }
    for (auto i : a)
    {
        q = used.size();
        for (auto j : i.second)
        {
            used.insert(j);
            w[j] = q;
            t[j] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (t[i])
            w[i]--;
        cout << max(w[i], 0) << endl;
    }
    return 0;
}

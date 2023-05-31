#include <bits/stdc++.h>

using namespace std;

int n, q, w[100100];
map<int, vector<int>> a;
unordered_set<int> used;

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
        for (auto j : i.second)
        {
            used.insert(j);
            w[j] = used.size() - 1;
        }
    for (int i = 0; i < n; i++)
        cout << w[i] << endl;
    return 0;
}

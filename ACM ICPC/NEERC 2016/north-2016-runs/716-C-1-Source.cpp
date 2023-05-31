#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <random>
#include <bitset>

using namespace std;

const string filename = "codecoder";
const int inf = int (1e9) + 7;

int main ()
{
    freopen ((filename + ".in").c_str (), "r", stdin);
    freopen ((filename + ".out").c_str (), "w", stdout);

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<pair<int, int>> x (n);

    for (auto &it : x)
        cin >> it.first >> it.second;

    vector<pair<int, int>> y (n);

    for (int i = 0; i < n; i++)
        y[i] = pair<int, int> (x[i].second, x[i].first);

    vector<int> ord (n);

    for (int i = 0; i < n; i++)
        ord[i] = i;

    sort (ord.begin (), ord.end (), [&x](int a, int b) {
        return x[a] < x[b];
    });

    sort (x.begin (), x.end ());
    sort (y.begin (), y.end ());

    vector<int> best (n, -1), px (n), py (n);

    int mx = 0, my = 0;

    for (int i = 0; i < n; i++)
    {
        px[i] = mx = max (x[i].second, mx);
        py[i] = my = max (y[i].second, my);
    }

    unordered_map<int, int> sx, sy;

    for (int i = 0; i < n; i++)
    {
        sx[x[i].first] = i;
        sy[y[i].first] = i;
    }

    x.clear ();
    y.clear ();

    for (int pos = 0; pos < n;)
    {
        int i = pos;

        while (true)
        {
            int t = sx[py[sy[px[i]]]];

            if (i != t)
                i = t;
            else
                break;
        }

        while (pos <= i)
            best[pos++] = i;
    }

    px.clear ();
    py.clear ();

    vector<int> res (n);

    for (int i = 0; i < n; i++)
        res[ord[i]] = best[i];

    for (auto &it : res)
        cout << it << endl;

    return 0;
}

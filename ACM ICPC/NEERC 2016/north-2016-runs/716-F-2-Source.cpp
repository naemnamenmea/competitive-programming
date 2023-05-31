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

const string filename = "folding";
const int inf = 1e9 + 7;

int truelog (int n)
{
    int r = 0;

    while (n)
    {
        n >>= 1;
        r++;
    }

    return r;
}

int foo (int H, int W, int h, int w)
{
    if (W < w || H < h)
        return inf;
    return truelog ((W + w - 1) / w - 1) + truelog ((H + h - 1) / h - 1);
}

int main ()
{
    freopen ((filename + ".in").c_str (), "r", stdin);
    freopen ((filename + ".out").c_str (), "w", stdout);

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    //
    //    int n;
    //
    //    cin >> n;
    //
    //    vector<pair<int, int>> x (n);
    //
    //    for (auto &it : x)
    //        cin >> it.first >> it.second;
    //
    //    vector<pair<int, int>> y (n);
    //
    //    for (auto &it : y)
    //        it = pair<int, int> (it.second, it.first);
    //
    //    vector<int> ord (n);
    //
    //    for (int i = 0; i < n; i++)
    //        ord[i] = i;
    //
    //    sort (ord.begin (), ord.end (), [&x](int a, int b) {
    //        return x[a] < x[b];
    //    });
    //
    //    sort (x.begin (), x.end ());
    //    sort (y.begin (), y.end ());
    //
    //    vector<int> bx (n), by (n), px (n), py (n);
    //
    //    for (int pos = 0; pos < n; pos++)
    //    {
    //        int i = pos;
    //        bool flag = true;
    //
    //        while (flag)
    //        {
    //
    //        }
    //    }
    //
    //    return 0;
    //}

    int W, H, w, h;

    cin >> W >> H >> w >> h;

    int t = min (foo (W, H, w, h), foo (H, W, w, h));

    cout << (t < inf ? t : -1) << endl;

    return 0;
}

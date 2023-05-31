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

const string filename = "integral";
const int inf = int (1e9) + 7;

int main ()
{
    freopen ((filename + ".in").c_str (), "r", stdin);
    freopen ((filename + ".out").c_str (), "w", stdout);

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<int> v (n);

    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        v[i] = (a & 1) * 2 + (b & 1);
    }

    vector<char> type (n);

    for (int shift = 0; shift < 4; shift++)
    {
        int col = 0;

        for (int i = 1; i < n; i++)
        {
            int v1 = v[i - 1] ^ shift,
                v2 = v[i] ^ shift;

            col ^= ((v1 >> 1) & (v2 & 1)) ^ ((v2 >> 1) & (v1 & 1));

            type[i] |= col << shift;
        }
    }

    vector<vector<int>> cnt (4, vector<int> (2));

    for (auto it : type)
    {
        cnt[0][(it & 1) / 1]++;
        cnt[1][(it & 2) / 2]++;
        cnt[2][(it & 4) / 4]++;
        cnt[3][(it & 8) / 8]++;
    }

    long long res = 0;

    for (int i = 0; i < n; i++)
        res += cnt[v[i]][(type[i] & (1 << v[i])) >> v[i]] - 3;

    res /= 2;

    cout << res << endl;

    return 0;
}

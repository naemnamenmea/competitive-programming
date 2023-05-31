#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);

    int x, y, z;
    cin >> x >> y >> z;
    tuple<int, int, int> d = {z , y, x};
    vector<pair<tuple<int, int, int>, int>> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> z;
        a.push_back({make_tuple(z, y, x), i + 1});
    }
    sort(a.begin(), a.end());
    for (int i = n - 1; i > -1; --i) {
        auto t = a[i].first;
        get<0>(t) += 18;
        if (t <= d) {
            cout << a[i].second;
            return 0;
        }
    }

    cout << -1;

    return 0;
}
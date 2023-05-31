#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);

    int n, x, y;
    vector<pair<pair<int,int>, int>> a;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        a.push_back({make_pair(x, y), i}); 
    }
    sort(a.begin(), a.end());
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        auto it = m.find(a[i].first.second);
        if (it != m.end()) {
            it->second = max(i, it->second);
        } else {
            m[a[i].first.second] = i;
        }
    }

    int curr = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        int temp = it->second;
        it->second = curr;
        curr = max(curr, temp);
    }

    vector<int> ans(n);
    curr = 0;
    for (int i = 0; i < n; ++i) {
        int temp = m[a[i].first.second];
        if (temp <= i) {
            ans[a[i].second] = i;
        } else {
            ans[a[i].second] = temp;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << endl;

    return 0;
}
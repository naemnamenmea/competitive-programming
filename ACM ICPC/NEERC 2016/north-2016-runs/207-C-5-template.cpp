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
        m[a[i].first.second] = i;
    }

    int curr = m.begin()->second;
    for (auto it = m.begin(); it != m.end(); ++it) {
        int temp = it->second;
        it->second = max(curr, temp);
        curr = it->second;
    }

    vector<int> ans(n);
    curr = 0;
    int mm = -1;
    for (int i = 0; i < n; ++i) {
        mm = max(mm, a[i].first.second);
        auto it = m.find(mm);
        int temp = it->second;
        if (temp <= i) {
            ans[a[i].second] = i;
        } else {
            if (it->first == mm)
                ans[a[i].second] = temp;
            else
                ans[a[i].second] = temp + 1;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << endl;

    return 0;
}
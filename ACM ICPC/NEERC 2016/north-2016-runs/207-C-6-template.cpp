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
    vector<int> b;
    int tt = -1;
    for (int i = 0; i < n; ++i) {
        tt = max(tt, a[i].first.second);
        m[a[i].first.second] = i;
        b.push_back(tt);
    }

    int curr = -1;
    for (auto it = m.begin(); it != m.end(); ++it) {
        int temp = it->second;
        it->second = curr;
        curr = max(curr, temp);
    }

    vector<int> ans(n, 0);
    curr = 0;
    for (int i = n - 1; i > -1; --i) {
        auto it = m.find(b[i]);
        int temp = it->second;
        if (temp > -1) {
            if (temp > i) {
                ans[a[i].second] = max(i, ans[a[temp].second]);
            } else {
                ans[a[i].second] = i;
            }            
        } else {
            ans[a[i].second] = i;
        }
/*
        if (temp <= i) {
            ans[a[i].second] = i;
        } else {
            ans[a[i].second] = temp + 1;
        }
*/
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << endl;

    return 0;
}
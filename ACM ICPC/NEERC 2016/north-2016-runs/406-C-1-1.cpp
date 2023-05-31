#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("codecoder.in", "r", stdin);
    freopen ("codecoder.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> a[100001], b[100001];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a, a + n);
    sort(b, b + n);
    int ans[100001];
    for (int i = 0; i < n; i++) {
        ans[a[i].second] = max(ans[a[i].second], i);
        ans[b[i].second] = max(ans[b[i].second], i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}

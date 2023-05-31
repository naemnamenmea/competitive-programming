#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int) (x).size())
#define bend(x) (x).begin(), (x).end()
#define puba push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);

    int n, m, x1, y1, x2, y2;
    scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);

    if (x1 != x2) {
        cout << x1 << " 0 " << x2 << " " << m << "\n";
    } else {
        cout << "0 " << y1 << " " << n << " " << y2 << "\n";
    }

    return 0;
}
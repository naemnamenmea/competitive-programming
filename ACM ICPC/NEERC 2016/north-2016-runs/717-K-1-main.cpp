#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define push_back pb

int ml[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ysum = 0;

int read_date(int d, int m, int y) {
    int res = 0;
    res += y * ysum;
    for(int i = 0; i < m; i++)
        res += ml[i];
    res += d;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "king"
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);

    for(int i = 0; i < 12; i++)
        ysum += ml[i];

    int x,y,z;
    cin >> x >> y >> z;
    int kdeath = read_date(x, y, z);
    int n;
    cin >> n;
    int ans = -1;
    int maxb = -1;
    int y18 = ysum * 18;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        int date = read_date(x, y, z);
        if (date + y18 <= kdeath && date > maxb) {
            maxb = date;
            ans = i + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
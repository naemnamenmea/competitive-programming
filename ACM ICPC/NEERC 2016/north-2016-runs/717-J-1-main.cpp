#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define push_back pb

void solve() {
    int c;
    cin >> c;
    cout << "a = ? max ?\n";
    cout << "b = (a max a) / a\n";  // b == 1
    cout << "c = b + b\n";          // c == 2
    cout << "d = ? / ? / ?\n";        // d == 0
    char cur = 'd', next = 'e';
    for (int i = 7; i >= 0; i--) {
        cout << next << " = " << cur << " * c\n";
        next++, cur++; 
        if (c & (1 << i)) {
            cout << next << " = " << cur << " + b\n";
            next++, cur++;
        }
    }
    cout << cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "java2016"
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    solve();
    return 0;
}
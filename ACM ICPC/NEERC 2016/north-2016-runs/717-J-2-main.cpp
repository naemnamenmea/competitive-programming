#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define push_back pb

int highest(int c) {  // c > 0
    for (int i = 7; i >= 0; i--)
        if (c & (1 << i))
            return i;
}

void solve() {
    int c;
    cin >> c;
    if (!c) {
        cout << "? /?/ ?";
        return;
    }
    cout << "a = ? max ? max ? max ? max ?\n";
    cout << "b = a / a\n";  // b == 1
    cout << "c = b + b\n";          // c == 2
    cout << "d = b\n";        // d == 0
    char cur = 'd', next = 'e';
    for (int i = highest(c) - 1; i >= 0; i--) {
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
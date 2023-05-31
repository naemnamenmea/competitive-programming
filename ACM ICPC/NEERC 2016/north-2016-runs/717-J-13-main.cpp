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

    cout << "a = ? max ?\n";
    char cur = 'a', next = 'b';
    for (int i = 0; i < 8; i++) {
        cout << next << " = " << cur << " max " << cur << " max " << cur << " max " << cur << " max " << cur << '\n';
        cur++, next++;
    }

    cout << next << " = " << cur << " / " << (char) (cur - 2) << '\n';
    char one = next;
    cur++, next++;
    
    cout << next << " = " << cur << " + " << cur << '\n';
    char two = next;
    cur++, next++;

    cout << next << " = " << one << '\n';            
    
    for (int i = highest(c) - 1; i >= 0; i--) {
        next++, cur++;
        if (c & (1 << i)) {
            cout << next << " = (" << cur << " * " << two << ") + " << one << '\n';
        } else {
            cout << next << " = " << cur << " * " << two << '\n';
        }
    }
        
    cout << next;
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
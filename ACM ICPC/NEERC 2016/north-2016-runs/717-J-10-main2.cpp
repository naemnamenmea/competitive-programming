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
    cout << "a = ? max ? max ? max ? max ? max ?\n";
    cout << "b = a max a max a max a\n";
    cout << "c = b max b max b max b\n";
    cout << "d = c max c max c max c\n";
    cout << "e = d max d max d max d\n";
    cout << "f = e max e max e max e\n";
    cout << "g = f max f max f max f\n";
    cout << "h = g max g max g max g\n";
    cout << "i = h max h max h max h\n";
    cout << "j = i / e\n"; 
    cout << "k = j + j\n";      
    cout << "l = j\n";        
    char cur = 'l', next = 'm';
    for (int i = highest(c) - 1; i >= 0; i--) {
        cout << next << " = " << cur << " * k\n";
        next++, cur++; 
        if (c & (1 << i)) {
            cout << next << " = " << cur << " + j\n";
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
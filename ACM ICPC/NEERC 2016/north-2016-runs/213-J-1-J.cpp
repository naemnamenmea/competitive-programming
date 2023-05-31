#include <bits/stdc++.h>

using namespace std;

#define FILE "java2016"

int x;
const int A = 17;
const int B = 7;

int main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);

    cin >> x;

    if (x == 0) {
        cout << "? / ? / ?" << endl;
        return 0;
    }

    cout << "a = ? max ?" << endl;
    for (int i = 1; i <= A; ++i) {
        cout << char('a' + i) << " = " << char('a' + i - 1) << " max " << char('a' + i - 1) << endl;
    }

    char p = 'a' + A + 1;
    cout << p << " = " << char('a' + A) << " / " << char('a' + A) << endl;

    for (int i = A + 2; i <= A + B + 1; ++i) {
        cout << char('a' + i) << " = " << char('a' + i - 1) << " + " << char('a' + i - 1) << endl;
    }

    vector <char> a;
    for (int i = 1, j = 1; i <= x; i *= 2, ++j) {
        if (x & i) {
            a.push_back('a' + A + j);
        }
    }

    for (int i = 0; i < a.size() - 1; ++i) {
        cout << a[i] << " + ";
    }

    cout << a.back() << endl;
    return 0;
}

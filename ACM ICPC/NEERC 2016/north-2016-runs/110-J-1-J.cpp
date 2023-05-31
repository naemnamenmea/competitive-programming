#include <bits/stdc++.h>

using namespace std;

#define filename "java2016"

int main()
{
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
    int n;
    cin >> n;

    if (n == 0){
        cout << "? / ? / ?\n";
        return 0;
    }

    int c = 5;
    cout << "a = ? max ?\n";
    for (int i = 0; i < c; i++){
        cout << (char)('a' + 1 + i) << " = " << (char)('a' + i) << " max " << (char)('a' + i) << "\n";
    }
    for (int i = 0; i < c; i++){
        cout << (char)('a' + 1 + c + i) << " = " << (char)('a' + c + i) << " max " << (char)('a' + c + i) << "\n";
    }
    cout << (char)('a' + 2 * c + 1) << " = " << (char)('a' + c) << " max " << (char)('a' + c) << "\n";
    for (int i = 1; i < c; i++){
        cout << (char)('a' + 1 + 2 * c + i) << " = " << (char)('a' + 2 * c + i) << " min " << (char)('a' + 2 * c + i) << "\n";
    }
    cout << (char)('a' + 3 * c + 1) << " = " << (char)('a' + 2 * c) << " / " << (char) ('a' + 3 * c) << "\n";
    cout << (char)('a' + 3 * c + 2) << " = " << (char)('a' + 3 * c + 1) << " + " << (char) ('a' + 3 * c + 1) << "\n";
    for (int i = 2; i < 8; i++){
        cout << (char)('a' + 3 * c + 1 + i) << " = " << (char)('a' + 3 * c + 1 + i - 1) << " * " << (char) ('a' + 3 * c + 2) << "\n";
    }
    int ct = 0;
    while (n > 0){
        if (n & 1){
            cout << (char)('a' + 3 * c + 1 + ct);
            n >>= 1;
            if (n > 0)
                cout << " + ";
        }
        else{
            n >>= 1;
        }
        ct++;
    }
    cout << "\n";
    return 0;
}

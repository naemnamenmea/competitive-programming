#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("java2016.in","r",stdin);
    freopen("java2016.out","w",stdout);
    int n;
    cin >> n;
    if (n == 0) {
        cout << "? /?/ ?";
        return 0;
    }
    cout << "a = ?\na = a / a" << endl;
    cout << "b = a+a" << endl;
    int a = 1;
    while ((a * 2) < n) {
        cout << "a = a*b" << endl;
        a <<= 1;
    }
    cout << "c = a" << endl;
    n -= a;
    while (n) {
        //cerr << n << endl;
        while (a > n) {
            a /= 2;
            cout << "a = a/b" << endl;
        }
        n -= a;
        cout << "c = c + a" << endl;
    }
    cout << "c";
    return 0;
}

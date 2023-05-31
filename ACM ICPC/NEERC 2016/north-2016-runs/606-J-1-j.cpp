#include <bits/stdc++.h>

using namespace std;

const int W = 16;
const char E = 'a' + W + 1;

int main() {
    freopen("java2016.in", "r", stdin);
    freopen("java2016.out", "w", stdout);
    
    int n;
    cin >> n;
    cout << "a = ? + ?\n";
    for (int i = 0; i < W; ++i)
        cout << (char)('b'+i) << " =  " << (char)('a'+i) << " max " << (char)('a'+i) << "\n";
    cout << E << " = " << char(E-1) << " / " << char(E-1) << "\n";
    for (int i = 0; i < 7; ++i)
        cout << char(E+1+i) << " = " << char(E+i) << " + " << char(E+i) << "\n";

    if (n == 0)
        cout << E << "-" << E << "\n";
    else {
        int i = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                cout << char(E+i);
                if (n != 1)
                    cout << "+";
            }
            n /= 2;
            ++i;
        }
    }
}
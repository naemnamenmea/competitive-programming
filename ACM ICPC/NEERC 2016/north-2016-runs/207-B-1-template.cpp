#include <bits/stdc++.h>

using namespace std;

vector<char> a;

int solve(int n, int x, int y) {
    if (x < 0 || y < 0 || n < 2)
        return -1;
    if (n == 2) {
        if (x == 2 && y == 0) {
            a.push_back('B');
            a.push_back('B');
            return 0;
        }
        if (x == 0 && y == 2) {
            a.push_back('G');
            a.push_back('G');
            return 0;
        }
        if (x == 1 && y == 1) {
            a.push_back('B');
            a.push_back('G');
            return 0;
        }
        return -1;
    }
    if (x > 1) {
        a.push_back('B');
        return solve(n - 1, x - 2, y);
    } else if (y > 1) {
        a.push_back('G');
        return solve(n - 1, x, y - 2);
    }
    return -1;
}        

int main() {
    freopen("boysgirls.in", "r", stdin);
    freopen("boysgirls.out", "w", stdout);

    int n, x, y;

    cin >> n >> x >> y;
    string str;
    int k1 = n - x + 1, k2 = n - y + 1;
    if (n == 2) {
        if (-1 == solve (n, x, y)) {
            cout << "Impossible";
        } else {
            cout << a[0] << a[1];
        }
        return 0;
    }
    for (int i = 0; i < min(k1, k2); i++)
        str += "BG";
    if (k1 < k2)
        for (int i = k1; i < k2; i++)
            str += "B";
    else
        for (int i = k2; i < k1; i++)
            str += "G";
    if (str.size() > n)
    {
        cout << "Impossible";
        return 0;
    }
    if (str.size() == n) {
        cout << str;
        return 0;
    }
    int p = 0;
    string s = ""; 
    for (int i = n; i > str.size(); i--)
    {   
        if (p < 2)
        str += "G";
        else
        str += "B";
        p++;
        p %= 4; 
    }
    cout << str;
    for (int i = s.size() - 1; i >= 0; i--)
        cout << s[i];   

        
    return 0;
}
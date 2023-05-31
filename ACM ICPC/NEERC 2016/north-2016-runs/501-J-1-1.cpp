#include <bits/stdc++.h>

using namespace std;


#define pw(x) (1LL << (x))
#define TASK "java2016"

string go(int n, int k)
{
    if (n == pw(k))
    {
        return (string)"" + (char)('a' + k);
    }
    if (n & pw(k))
    {
        string s = go(n - pw(k), k - 1);
        if (s.size() > 1) s = "(" + s + ")";
        return s + " + " + (char)('a' + k);
    }
    return go(n, k - 1);
}

int main() {
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("(?/?)/?\n");
        return 0;
    }

    
    cout << "z = (((((? max ?) max ?) max ?) max ?) max ?) max ?" << endl;
    cout << "y = (((((z max z) max z) max z) max z) max z) max z" << endl;
    cout << "x = (((((z min z) min z) min z) min z) min z) min z" << endl;
    cout << "a = y / x" << endl;
    for (int i = 1; i <= 7; ++i)
    {
        char c = 'a' + i;
        char c2 = 'a' + i - 1;
        cout << c << " = " << c2 << " + " << c2 << endl;
    }

    cout << go(n, 7) << endl;

    return 0;
}
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

int cnt = 0;

void out(string s)
{
    for (int i = 0; i < s.size(); ++i) if (s[i] != ' ') cnt++;
    cout << s << endl;
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

    
    out("z = (((((((((((((? max ?) max ?) max ?) max ?) max ?) max ?) max ?) max ?) max ?) max ?) max ?) max ?) max ?) max ?");
    out("y = (((((((((((((z max z) max z) max z) max z) max z) max z) max z) max z) max z) max z) max z) max z) max z) max z");
    out("x = z min z");
    out("a = y / x");
    out("b = a + a");
    for (int i = 2; i <= 7; ++i)
    {
        char c = 'a' + i;
        char c2 = 'a' + i - 1;
        out((string)"" + c + " = " + c2 + " * b");
    }

    out(go(n, 7));

    fprintf(stderr, " %d\n", cnt);

    return 0;
}
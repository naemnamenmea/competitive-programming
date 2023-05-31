#include <bits/stdc++.h>

using namespace std;

#define FILENAME "king"

#define fori(n) for (int i = 0; i < n; ++i)
#define forj(n) for (int j = 0; j < n; ++j)
#define fori1(n) for (int i = 1; i < n; ++i)
#define forj1(n) for (int j = 1; j < n; ++j)
#define pb push_back

#define INF 1000000007

void readln() {}
void readln(auto& a, auto&... b)
{
    cin >> a;
    readln(b...);
}

void writeln() {cout << "\n";}
void writeln(auto a, auto... b)
{
    cout << a << " ";
    writeln(b...);
}

int main()
{
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    int d, m, y;
    readln(d, m, y);
    int n;
    readln(n);
    int ansy = -1, ansm = -1, ansd = -1;
    int pos = -1;
    fori(n)
    {
        int cd, cm, cy;
        readln(cd, cm, cy);
        if ((cm == m && cd <= d) || cm < m)
        {
            if (y - cy >= 18 && (ansy < cy || (ansy == cy && (ansm < cm || (ansm == cm && ansd < cd)))))
            {
                ansy = cy;
                ansm = cm;
                ansd = cd;
                pos = i + 1;
            }
        } else {
            if (y - cy - 1 >= 18 && (ansy < cy || (ansy == cy && (ansm < cm || (ansm == cm && ansd < cd)))))
            {
                ansy = cy;
                ansm = cm;
                ansd = cd;
                pos = i + 1;
            }
        }
    }
    writeln(pos);
    return 0;
}

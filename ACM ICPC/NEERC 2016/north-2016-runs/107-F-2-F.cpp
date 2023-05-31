#include <bits/stdc++.h>

using namespace std;

#define FILENAME "folding"

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

int w, h, W, H;

int g(int x, int y)
{
    if (y > x)
        return INF;
    int k = 0;
    while (x > y)
        x = (x + 1) / 2,
        k++;
    return k;
}

int f(int w, int h)
{
    return g(W, w) + g(H, h);
}

int main()
{
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    readln(W, H, w, h);
    int ans1 = f(w, h);
    int ans2 = f(h, w);
    int ans = min(ans1, ans2);
    writeln(ans >= INF ? -1 : ans);
    return 0;
}

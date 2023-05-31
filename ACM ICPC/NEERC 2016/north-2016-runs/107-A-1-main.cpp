#include <bits/stdc++.h>

using namespace std;

#define FILENAME "anniversary"

#define fori(n) for (int i = 0; i < n; ++i)
#define forj(n) for (int j = 0; j < n; ++j)
#define fori1(n) for (int i = 1; i < n; ++i)
#define forj1(n) for (int j = 1; j < n; ++j)
#define pb push_back

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
    int w, h, ax, ay, bx, by;
    readln(w, h, ax, ay, bx, by);
    if (ay == by)
        writeln(ax, 0, bx, h);
    else
        writeln(0, ay, w, by);
    return 0;
}

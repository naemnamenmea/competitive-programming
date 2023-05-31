#include <bits/stdc++.h>

using namespace std;

#define FILENAME "digital"

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

vector<vector<vector<int>>> digits(10);

struct state
{
    int carry = 0;
    vector<int> a;
    string s = "", t = "", f = "";
    state(){}
};

int main()
{
    digits[0] =
    {   {0, 1, 0},
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1},
        {0, 1, 0}};
    digits[1] =
    {   {0, 0, 0},
        {0, 0, 1},
        {0, 0, 0},
        {0, 0, 1},
        {0, 0, 0}};
    digits[2] =
    {   {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0},
        {0, 1, 0}};
    digits[3] =
    {   {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0}};
    digits[4] =
    {   {0, 0, 0},
        {1, 0, 1},
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    digits[5] =
    {   {0, 1, 0},
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0}};
    digits[6] =
    {   {0, 1, 0},
        {1, 0, 0},
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    digits[7] =
    {   {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0},
        {0, 0, 1},
        {0, 0, 0}};
    digits[8] =
    {   {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    digits[9] =
    {   {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0}};

    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    int w;
    readln(w);
    vector<vector<int>> a(9, vector<int>(2 * w + 1, 0));
    vector<vector<int>> b(9, vector<int>(2 * w + 1, 0));
    fori(9)
        forj(w + (i % 2))
            readln(a[i][j * 2 + (i % 2 == 0)]);

    string s = "", t = "", f = "";
    int cq, cw, ce;
    vector<state> states, newStates;
    state sss;
    sss.a.resize(9, 0);
    states.pb(sss);
    for (int i = w - 1; i >= 0; --i)
    {
        //writeln(i);
        bool ok = false;
        int mx = -1;
        for (state& sss : states)
            for (int q = 0; q < 10; ++q)
                for (int w = 0; w < 10; ++w)
                {
                    int e = (q + w + sss.carry) % 10;
                    int is = (q + w + sss.carry) / 10;
                    //writeln(sss.s, sss.t, sss.f);
                    //writeln();
                    for (int x = 0; x < 3; ++x)
                        for (int y = 0; y < 9; ++y)
                            b[y][2 * i + x] = 0;

                    for (int y = 0; y < 9; ++y)
                        b[y][2 * i + 2] = sss.a[y]; // copy prev a[i]
                    for (int x = 0; x < 3; ++x)
                        for (int y = 0; y < 5; ++y)
                            b[y + 0][2 * i + x] = max(b[y + 0][2 * i + x], digits[q][y][x]);

                    for (int x = 0; x < 3; ++x)
                        for (int y = 0; y < 5; ++y)
                            b[y + 2][2 * i + x] = max(b[y + 2][2 * i + x], digits[w][y][x]);

                    for (int x = 0; x < 3; ++x)
                        for (int y = 0; y < 5; ++y)
                            b[y + 4][2 * i + x] = max(b[y + 4][2 * i + x], digits[e][y][x]);

                    if (false)
                    {
                    writeln(q, w, e);
                    for (int y = 0; y < 9; ++y)
                    {
                        for (int x = 0; x < 3; ++x)
                            cout << (b[y][2 * i + x] == 0 ? '.' : 'X');
                        writeln();
                    }
                        writeln();
                    }
                    int cur = true;
                    for (int x = 1; x < 3; ++x)
                        for (int y = 0; y < 9; ++y)
                            cur &= a[y][2 * i + x] == b[y][2 * i + x];
                    if (cur)
                    {
                        state nnn;
                        nnn.a.resize(9);
                        for (int y = 0; y < 9; ++y)
                            nnn.a[y] = b[y][2 * i];
                        nnn.carry = is;
                        nnn.s = sss.s + char(q + '0');
                        nnn.t = sss.t + char(w + '0');
                        nnn.f = sss.f + char(e + '0');

                        bool was = false;
                        for (state aaa : newStates)
                        {
                            bool now = aaa.carry == nnn.carry;
                            for (int y = 0; y < 9; ++y)
                                now &= nnn.a[y] == aaa.a[y];
                            was |= now;
                        }
                        if (!was)
                            newStates.pb(nnn);
                    }
                }
        states = newStates;
        newStates.clear();
    }
    if (false) {
        fori(9)
        {
            forj(a[i].size())
                cout << (a[i][j] == 0 ? '.' : 'X');
            writeln();
        }
    }
    int i;
    for (i = 0; i < states.size(); ++i)
        if (states[i].carry == 0)
        {
            state sss = states[i];
            bool temp = true;
            for (int y = 0; y < 9; ++y)
                temp &= sss.a[y] == a[y][0];
            if (!temp)
                continue;
            reverse(sss.s.begin(), sss.s.end());
            reverse(sss.t.begin(), sss.t.end());
            reverse(sss.f.begin(), sss.f.end());
            writeln("YES");
            writeln(sss.s);
            writeln(sss.t);
            writeln(sss.f);
            return 0;
        //    writeln(sss.carry);
          //  writeln();
        }
    writeln("NO");
    return 0;
}

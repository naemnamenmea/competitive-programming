#include <bits/stdc++.h>

using namespace std;

const int N = 100500;
string s;

void imp() {
    cout << "Impossible\n";
    exit(0);
}

int main() {
    freopen("boysgirls.in", "r", stdin);
    freopen("boysgirls.out", "w", stdout);
    
    int n, _x, _y;
    cin >> n >> _x >> _y;
    int bg = _x + _y - n;
    int bb = _x - bg;
    int gg = _y - bg;
    if (bg < 0 || bb < 0 || gg < 0)
        imp();
        
    if (n % 2 == 1)
    {
        if (bg % 2 == 1 || bg + bb + gg != n)
            imp();
        if (bg == 0)
        {
            if (bb == n)
                for (int i = 0; i < n; ++i)
                    s += "B";
            else if (gg == n)
                for (int i = 0; i < n; ++i)
                    s += "G";
            else
                imp();
        } else {
            for (int i = 0; i < bg / 2 - 1; ++i)
            {
                s += "B";
                s += "G";
            }
            for (int i = 0; i < bb + 1; ++i) s += "B";
            for (int i = 0; i < gg + 1; ++i) s += "G";
        }
        static char s1[N];
        for (int i = 0; i < n; ++i)
            s1[(2*i) % n] = s[i];
        cout << s1 << "\n";
    } else {
        if (bg % 2 == 1 || bg + bb + gg != n)
            imp();
        if (bg == 0)
        {
            if (bb == 0)
                for (int i = 0; i < n; ++i)
                    s += "G";
            else if (bb == n)
                for (int i = 0; i < n; ++i)
                    s += "B";
            else if (bb == n/2)
            {
                for (int i = 0; i < n/2; ++i) s += "B";
                for (int i = 0; i < n/2; ++i) s += "G";
            } else
                imp();
        } else if (bg == 2)
        {
            if (bb >= n/2)
            {
                for (int i = 0; i < n/2; ++i) s += "B";
                bb -= n / 2;
            } else if (gg >= n/2)
            {
                for (int i = 0; i < n/2; ++i) s += "G";
                gg -= n / 2;
            } else
                imp();
            for (int i = 0; i < gg + 1; ++i)
                s += "G";
            for (int i = 0; i < bb + 1; ++i)
                s += "B";
        } else {
            int bg1 = (bb % 4 == 0 ? bg / 2 : bg / 2 - 1);
            int bg2 = bg - bg1;
            int bb1 = 0, gg1 = 0;
            int bb2 = bb, gg2 = gg;
            if (bb2 >= n/2 - bg1)
            {
                bb2 -= n/2 - bg1;
                bb1 += n/2 - bg1;
            } else {
                bb1 = bb2;
                bb2 = 0;
                int rem = n/2 - bg1 - bb1;
                gg2 -= rem;
                gg1 += rem;
            }
            if (bg1 < 0 || bb1 < 0 || gg1 < 0 || bb1 > n/2 || gg1 > n/2 || bg1 > n/2) imp();
            if (bg2 < 0 || bb2 < 0 || gg2 < 0 || bb2 > n/2 || gg2 > n/2 || bg2 > n/2) imp();
            
            for (int i = 0; i < bg1 / 2 - 1; ++i)
            {
                s += "B";
                s += "G";
            }
            for (int i = 0; i < bb1 + 1; ++i) s += "B";
            for (int i = 0; i < gg1 + 1; ++i) s += "G";
            for (int i = 0; i < bg2 / 2 - 1; ++i)
            {
                s += "B";
                s += "G";
            }
            for (int i = 0; i < bb2 + 1; ++i) s += "B";
            for (int i = 0; i < gg2 + 1; ++i) s += "G";
        }
        static char s1[N];
        for (int i = 0; i < n/2; ++i)
            s1[2*i] = s[i];
        for (int i = 0; i < n/2; ++i)
            s1[2*i+1] = s[i+n/2];
        cout << s1 << "\n";
    }
}
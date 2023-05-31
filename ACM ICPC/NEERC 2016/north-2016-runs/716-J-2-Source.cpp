#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <random>
#include <bitset>

using namespace std;

const string filename = "java2016";
const int inf = int (1e9) + 7;

int main ()
{
    freopen ((filename + ".in").c_str (), "r", stdin);
    freopen ((filename + ".out").c_str (), "w", stdout);

    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    //int n, x, y;

    //cin >> n >> x >> y;

    //int bb, bg, gg;

    //bg = x + y - n;
    //bb = n - y;
    //gg = n - x;

    //if (bg < 0 || bb < 0 || gg < 0 || bg % 2 != 0)
    //    cout << "Impossible" << endl;
    //else
    //{
    //    if (bg == 0)
    //    {
    //        if (gg != 0 && bb != 0 && gg != bb)
    //            cout << "Impossible" << endl;
    //        else if (bb == gg)
    //        {
    //            for (int i = 0; i < gg; i++)
    //                cout << "BG";
    //            cout << endl;
    //        }
    //        else
    //            cout << string (max (bb, gg), gg < bb ? 'B' : 'G').c_str () << endl;
    //    }
    //    else if (bg % 4 == 0)
    //    {
    //        cout << string (bb, 'B').c_str () << "BB" << string (gg, 'G') << "GG";
    //        bg -= 4;
    //        for (int i = 0; i < bg / 4; i++)
    //            cout << "BBGG";
    //        cout << endl;
    //    }
    //    else
    //    {
    //        string res = "BG";

    //        bg -= 2;

    //        cout << string (bb, 'B').c_str () << "BB" << string (gg, 'G') << "GG";
    //        bg -= 4;
    //        for (int i = 0; i < bg / 4; i++)
    //            cout << "BBGG";
    //        cout << endl;
    //    }
    //}

    int n;

    cin >> n;


    cout << "a = ? max ?" << endl;

    for (int i = 1; i < 18; i++)
        cout << char ('a' + i) << " = " << char ('a' + i - 1) << " max "
        << char ('a' + i - 1) << endl;

    for (int i = 18; i < 26; i++)
        cout << char ('a' + i) << " = " << char ('a' + i - 1) << " + "
        << char ('a' + i - 1) << endl;

    int t = 256 - n;
    char pos = 'r';

    while (t)
    {
        if (t & 1)
        {
            cout << pos;

            if (t > 1)
                cout << " + ";
        }

        t >>= 1;
        pos++;
    }

    cout << endl;

    return 0;
}

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
#include <cassert>

using namespace std;

const string filename = "boysgirls";
const int inf = int (1e9) + 7;

int main ()
{
    freopen ((filename + ".in").c_str (), "r", stdin);
    freopen ((filename + ".out").c_str (), "w", stdout);

    int n, x, y;

    cin >> n >> x >> y;

    int bb, bg, gg;

    bg = x + y - n;
    bb = n - y;
    gg = n - x;

    string res;

    if (bg < 0 || bb < 0 || gg < 0 || bg % 2 != 0)
    {
        cout << "Impossible" << endl;

        return 0;
    }
    else
    {
        if (bg % 4 == 0)
        {
            if (bg == 0)
            {
                if (n % 2 == 0 && x == y && 2 * x == n)
                {
                    for (int i = 0; i < n / 2; i++)
                        res += "BG";
                }
                else if (x == 0 || y == 0)
                {
                    res = string (n, x == 0 ? 'G' : 'B');
                }
                else
                {
                    cout << "Impossible" << endl;

                    return 0;
                }
            }
            else if (bg <= n)
            {
                int t = bg / 4;

                int x1 = x - 2 * t;
                int y1 = y - 2 * t;

                for (int i = 0; i < t - 1; i++)
                    res += "BBGG";

                for (int i = 0; i < x1 - 2 * (t - 1); i++)
                    res += "B";

                for (int i = 0; i < y1 - 2 * (t - 1); i++)
                    res += "G";
            }
            else
            {
                cout << "Impossible" << endl;

                return 0;
            }
        }
        else
        {
            if (bg <= n)
            {
                int t = bg / 4;

                if (y != bg)
                {
                    int x1 = x - 2 * (t + 1),
                        y1 = y - 2 * t - 1;

                    res += "B";

                    if (t == 0)
                    {
                        if (x == y)
                        {
                            cout << "Impossible" << endl;

                            return 0;
                        }
                        else
                        {
                            if (bb > gg)
                            {
                                res = string (n, 'B');

                                for (int i = 0; i < gg + 1; i++)
                                    res[2 * i] = 'G';
                            }
                            else
                            {
                                res = string (n, 'G');

                                for (int i = 0; i < bb + 1; i++)
                                    res[2 * i] = 'B';
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < t - 1; i++)
                            res += "GGBB";

                        res += "GG";
                        res += string (x1 - 2 * (t - 1), 'B');
                        res += string (y1 - 2 * t, 'G');
                    }
                }
                else if (x != bg)
                {
                    int y1 = y - 2 * (t + 1),
                        x1 = x - 2 * t - 1;

                    res += "G";

                    if (t == 0)
                    {
                        if (x == y)
                        {
                            cout << "Impossible" << endl;

                            return 0;
                        }
                        else
                        {
                            if (bb > gg)
                            {
                                res = string (n, 'B');

                                for (int i = 0; i < gg + 1; i++)
                                    res[2 * i] = 'G';
                            }
                            else
                            {
                                res = string (n, 'G');

                                for (int i = 0; i < bb + 1; i++)
                                    res[2 * i] = 'B';
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < t - 1; i++)
                            res += "BBGG";

                        res += "BB";
                        res += string (y1 - 2 * (t - 1), 'G');
                        res += string (x1 - 2 * t, 'B');
                    }
                }
                else
                {
                    cout << "Impossible" << endl;

                    return 0;
                }
            }
            else
            {
                cout << "Impossible" << endl;

                return 0;
            }
        }
    }

    assert (res.size () == n);

    cout << res.c_str () << endl;

    return 0;
}

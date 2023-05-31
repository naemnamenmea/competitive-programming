#include <bits/stdc++.h>

using namespace std;

#define filename "boysgirls"

int a[200000];
int n;

void fill_ans(int start, int len, int bg, int bb, int gg)
{
    int cur = start;
    int cntb = 0;

    int cntg = 0;
    int last = -1;
    int total = 0;

    for(; total < len;)
    {
        if (cntb < bb)
        {
            a[cur] = 0;

            cur = (cur + 2) % n;
            total++;
            for(; cntb < bb; cntb++)
            {
                a[cur] = 0;
                cur = (cur + 2) % n;
                total++;
            }
            last = 0;
        }
        else if (cntg < gg)
        {
            a[cur] = 1;
            total++;

            for(; cntg < gg; cntg++)
            {
                a[cur] = 1;
                cur = (cur + 2) % n;
                total++;
            }

            last = 1;
        }
        else
        {
            if (last == -1)
            {
                a[cur] = 0;
            }
            else
            {
                a[cur] = 1 - last;
            }
            last = a[cur];
            cur = (cur + 2) % n;
            total++;
        }
    }
}

int main()
{
    //freopen(filename".in", "r", stdin);
    //freopen(filename".out", "w", stdout);

    int b, g;

    cin >> n >> b >> g;

    int bg = (b + g - n);
    int bb = b - bg;
    int gg = g - bg;

    //cerr << bg << " " << bb << " " << gg << "\n";

    if (bg < 0 || bg % 2 == 1 || bb + gg + bg != n)
    {
        cout << "Impossible";
    }
    else
    {
        if (n % 2 == 1)
        {
            fill_ans(0, n, bg, bb, gg);
        }
        else
        {
            int len = n / 2;

            int cnt = -1;

            for(int c = 2; c < bg && c <= len && (bg - c) <= len; c += 2)
            {
               if (c <= len && (bg - c) <= len){
                    cnt = c;
                    break;
               }
            }

            int bg1 = cnt;
            int bg2 = bg - cnt;
            int bb1 = min(bb, len - bg1);
            int bb2 = bb - bb1;
            int gg1 = min(gg, len - bg1 - bb1);
            int gg2 = gg - gg1;

            if (cnt < 0){
                if (bb >= len){
                    bg1 = 0;
                    bb1 = len;
                    gg1 = 0;
                    bg2 = bg - bg1;
                    bb2 = bb - bb1;
                    gg2 = gg - gg1;

                    if (bb2 >= 0 && gg2 >= 0 && bg2 >= 0){
                        if (!(bg2 == 0 && bb2 > 0 && bg2 > 0)){
                            cnt = 0;
                        }
                    }
                }
                else if (gg >= len){
                    bg1 = 0;
                    bb1 = 0;
                    gg1 = len;
                    bg2 = bg - bg1;
                    bb2 = bb - bb1;
                    gg2 = gg - gg1;

                    if (bb2 >= 0 && gg2 >= 0 && bg2 >= 0){
                        if (!(bg2 == 0 && bb2 > 0 && bg2 > 0)){
                            cnt = 0;
                        }
                    }
                }

                if (cnt < 0 || (bg2 == 0 && bb2 > 0 && gg2 > 0)){
                    cout << "Impossible";
                    return 0;
                }
            }

            fill_ans(0, len, bg1, bb1, gg1);
            fill_ans(1, len, bg2, bb2, gg2);
        }

        for(int i = 0; i < n; i++)
            if (a[i])
                cout << "G";
            else
                cout << "B";
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define taskname "folding"
#define taski taskname".in"
#define tasko taskname".out"

#define inp freopen(taski, "r", stdin)
#define outp freopen(tasko, "w", stdout)

int H, W, h, w;

int cnt = 1000000000;

int main()
{
    inp; outp;
    ios_base::sync_with_stdio(false);
    cin >> W >> H >> w >> h;
    int WW, HH;

    WW = W; HH = H;

    if (H >= h && W >= w){
        int cur_cnt = 0;
        while (H > h)
        {
            int newH = H / 2 + (H % 2 == 1 ? 1 : 0);
            H = newH;
            cur_cnt++;
        }
        while (W > w){
            int newW = W / 2 + (W % 2 == 1 ? 1 : 0);
            W = newW;
            cur_cnt++;
        }
        cnt = min(cnt, cur_cnt);
    }

    W = HH;
    H = WW;

    if (H >= h && W >= w){
        int cur_cnt = 0;
        while (H > h)
        {
            int newH = H / 2 + (H % 2 == 1 ? 1 : 0);
            H = newH;
            cur_cnt++;
        }
        while (W > w){
            int newW = W / 2 + (W % 2 == 1 ? 1 : 0);
            W = newW;
            cur_cnt++;
        }
        cnt = min(cnt, cur_cnt);
    }

    cout << (cnt ==  1000000000 ? -1 : cnt) << endl;
    return 0;
}

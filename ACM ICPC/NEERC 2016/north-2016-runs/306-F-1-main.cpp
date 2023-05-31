#include <bits/stdc++.h>

using namespace std;

#define taskname "folding"
#define taski taskname".in"
#define tasko taskname".out"

#define inp freopen(taski, "r", stdin)
#define outp freopen(tasko, "w", stdout)

int H, W, h, w;

int main()
{
    inp; outp;
    ios_base::sync_with_stdio(false);
    cin >> W >> H >> w >> h;
    if (H < h || W < w) swap(W, H);
    if (H < h || W < w) {
        cout << -1  << endl;
        return 0;
    }

    int cnt = 0;
    while (H > h)
    {
        int newH = H / 2 + (H % 2 == 1 ? 1 : 0);
        H = newH;
        cnt++;
    }
    while (W > w){
        int newW = W / 2 + (W % 2 == 1 ? 1 : 0);
        W = newW;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}

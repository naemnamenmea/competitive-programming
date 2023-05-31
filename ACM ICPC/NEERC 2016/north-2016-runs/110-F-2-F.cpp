#include <bits/stdc++.h>

using namespace std;

#define filename "folding"

int get1(int W, int H, int w, int h){
    int ct = 0;
    while (W > w){
        W = (W + 1) / 2;
        ct++;
    }
    while (H > h){
        H = (H + 1) / 2;
        ct++;
    }
    return ct;
}

int main(){
	//freopen(filename".in", "r", stdin);
	//freopen(filename".out", "w", stdout);
    int W,H;
    int w, h;
    cin >> W >> H >> w >> h;
    if (W > H) swap(W, H);
    if (w > h) swap(w, h);
    if (W < w || H < h){
        cout << -1;
        return 0;
    }
    int ct = get1(W, H, w, h);
    if (W >= h && H >= w){
        ct = min(ct, get1(W, H, h, w));
    }
    cout << ct;
	return 0;
}

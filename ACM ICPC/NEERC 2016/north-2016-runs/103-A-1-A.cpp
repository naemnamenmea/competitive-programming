#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin v.end
#define pb push_back
#define F first
#define S second

const int MAXN = 1e5 + 7;

int main(){
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);
    int w, h, x1, x2, y1, y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2;
    if (y1 == y2){
        cout << min(x1, x2) << " " << "0 " << max(x1, x2) << " " << h;
        return 0;
    }
    if (x1 == x2){
        cout << "0 " << min(y1, y2) << " " << w << " " << max(y1, y2);
        return 0;
    }
    if (x1 > x2){
        swap(x1, x2);
        swap(y1, y2);
    }
    cout << "0 " << y2 << " " << w << " " << y1;

    return 0;
}


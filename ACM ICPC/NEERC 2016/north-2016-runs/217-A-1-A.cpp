#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

struct point{
    int x, y;

    point(){}

    point(int _x, int _y){
        x = _x;
        y = _y;
    }
};

int w, h;

int main(){
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);
    cin >> w >> h;
    point ans1, ans2;
    point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    if (abs(a.x - b.x) > 1){
        ans1.x = (a.x + b.x) / 2;
        ans1.y = 0;
        ans2.x = (a.x + b.x) / 2;
        ans2.y = h;
        cout << ans1.x << ' ' << ans1.y << ' ' << ans2.x << ' ' << ans2.y << endl;
        return 0;
    }
    if (abs(a.y - b.y) > 1){
        ans1.x = 0;
        ans1.y = (a.y + b.y) / 2;
        ans2.x = w;
        ans2.y = (a.y + b.y) / 2;
        cout << ans1.x << ' ' << ans1.y << ' ' << ans2.x << ' ' << ans2.y << endl;
        return 0;
    }
    if (a.x == b.x){
        ans1.x = 0;
        ans1.y = min(a.y, b.y);
        ans2.x = w;
        ans2.y = max(a.y, b.y);
        cout << ans1.x << ' ' << ans1.y << ' ' << ans2.x << ' ' << ans2.y << endl;
        return 0;
    }
    ans1.x = min(a.x, b.x);
    ans1.y = 0;
    ans2.x = max(a.x, b.x);
    ans2.y = h;
    cout << ans1.x << ' ' << ans1.y << ' ' << ans2.x << ' ' << ans2.y << endl;
    return 0;
}

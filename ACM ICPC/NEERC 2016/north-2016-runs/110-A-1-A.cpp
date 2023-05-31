#include <bits/stdc++.h>

using namespace std;

#define filename "anniversary"

int main(){
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
    int w, h, ax, ay, bx, by;
    cin >> w >> h >> ax >> ay >> bx >> by;
    if (ax != bx){
        cout << ax << " " << 0 << " " << bx << " " << h;
    }else
        cout << 0 << " " << ay << " " << 0 << " " << by;
	return 0;
}

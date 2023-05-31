#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;



int main(){
    freopen("anniversary.in","rt",stdin);
    freopen("anniversary.out","wt",stdout);
    long long w,h, ax, ay, bx, by;
    cin >> w >> h >> ax  >> ay >> bx >> by;
    if (abs(ax-bx)>=2){
        if (ax<bx){
            cout << ax+1 << ' ' << 0 << ' ' << ax+1 << ' ' << h;
        }else{
            cout << bx+1 << ' ' << 0 << ' ' << bx+1 << ' ' << h;
        }
    }else{
        if (abs(ay-by)>=2){
            if (ay<by){
                cout << 0 << ' ' << ay+1 << ' ' << w << ' ' << ay+1;
            }else{
                cout << 0 << ' ' << by+1 << ' ' << w << ' ' << ay+1;
            }
        }else{
                if (ax==bx){
                    cout << 0 << ' ' << ay << ' ' << w << ' ' << by;
                }else{
                    if (ay==by){
                        cout << ax << ' ' << 0 << ' ' << bx << ' ' << h;
                    }else{
                        if (((ax<bx)&&(ay<by))||((bx<ax)&&(by<ay))){
                            if (ax<bx){
                                cout << ax << ' ' << h << ' ' << bx << ' ' << 0;
                            }else{
                                cout << bx << ' ' << h << ' ' << ax << ' ' << 0;
                            }
                        }else{
                            if (ax<bx){
                                cout << ax << ' ' << 0 << ' ' << bx << ' ' << h;
                            }else{
                                cout << bx << ' ' << 0 << ' ' << ax << ' ' << h;
                            }
                        }
                    }
                }

        }
    }


    return 0;
}

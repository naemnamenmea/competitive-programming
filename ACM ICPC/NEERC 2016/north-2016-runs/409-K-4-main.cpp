#include <iostream>
#include <cstdio>
using namespace std;

int main()
{   freopen("king.in","r",stdin);
    freopen("king.out","w",stdout);
    int d, m, y, n;
    int dm = 0;
    int mm = 0;
    int ym = 0;
    int cm = -1;
    int vm = 9999;
    cin >> d >> m >> y;
    cin >> n;
    for (int i = 1; i<=n; i++){
        int m1, d1, y1;
        int v = 0;
        cin >> d1 >> m1 >> y1;
        if (m > m1) {v = y - y1;}
        else if ((m==m1) && (d >= d1)) {v = y - y1;}
             else {v = y - y1 - 1;}
        if ((v < vm) && (v > 17)){ ym = y1;vm = v; cm = i;dm = d1; mm = m1; }
        if ((v == vm) && (v > 17)) { if (y1 == ym) {if ((m1 == mm)&&(d1 > dm )) {ym = y1; vm = v; cm = i;dm = d1; mm = m1;}
                                               else if (m1 > mm) {ym = y1; vm = v; cm = i;dm = d1; mm = m1;}}
                                   else if (y1 > ym)  {ym = y1;vm = v; cm = i;dm = d1; mm = m1;}}
        //cout << v <<" "<< mm <<" "<<dm<< " "<< ym <<"\n";
    }
    cout << cm;
    return 0;
}

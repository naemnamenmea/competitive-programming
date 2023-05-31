#include <iostream>
#include <cstdio>
using namespace std;

int main()
{   freopen("king.in","r",stdin);
    freopen("king.out","w",stdout);
    int d, m, y, n;
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
        if ((v < vm) && (v > 17)){ vm = v; cm = i; }
        //cout << v <<" "<< i<< " "<< n <<"\n";
    }
    cout << cm;
    return 0;
}

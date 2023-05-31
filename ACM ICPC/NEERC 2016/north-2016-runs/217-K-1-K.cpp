#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;

struct date{
    int d, m, y, id;

    date(){}

    date(int _d, int _m, int _y, int _id){
        d = _d;
        m = _m;
        y = _y;
        id = _id;
    }
};

date kingD, sons[N];
int n;

bool comp(date a, date b){
    if (a.y < b.y)
        return true;
    if (a.y > b.y)
        return false;
    if (a.m < b.m)
        return true;
    if (a.m > b.m)
        return false;
    if (a.d < b.d)
        return true;
    if (a.d > b.d)
        return false;
    return true;
}

int main(){
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);
    cin >> kingD.d >> kingD.m >> kingD.y;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> sons[i].d >> sons[i].m >> sons[i].y;
        sons[i].y += 18;
        sons[i].id = i;
    }
    sort(sons, sons + n, comp);
    date ans;
    ans.id = -1;
    for (int i = 0; i < n; i++){
        if (comp(sons[i], kingD)){
            ans = sons[i];
        }
    }
    if (ans.id == -1)
        cout << -1 << endl;
    else
        cout << ans.id + 1 << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define forab(i,a,b) for( int i = (a); i < (b); i++)
#define forn(i,n) forab(i,0,n)

const int MXC = 24;

int main()
{
    //freopen("input.txt", "r", stdin);    freopen("output.txt", "w", stdout);
    freopen("java2016.in", "r", stdin); freopen("java2016.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char *res = new char[500];
    res[0] = 0;

    int out = 0;
    int n;
    scanf("%d", &n);

    sprintf(res+strlen(res), "a=?max?\n");
    forab(i,1,MXC){
        sprintf(res+strlen(res), "%c=%cmax%c\n", 'a'+i, 'a'+i-1, 'a'+i-1);
    }

    sprintf(res+strlen(res), "y=%c/%c\n", 'a'+MXC-1, 'a'+MXC-1);

    sprintf(res+strlen(res), "z=y+y\n");

    if(n==0){
        sprintf(res+strlen(res), "y-y\n");
        assert(strlen(res) <= 256);
        printf(res);
        return 0;
    }
    int cur = 1;
    while (cur*2 <= n){
        cur *= 2;
    }
    string ans = "y";
    cur /= 2;
    while (cur>0){
        ans = "("+ans+")*z";
        if(cur & n){
            ans = ans + "+y";
        }
        cur /= 2;
    }

    sprintf(res+strlen(res), "%s\n", ans.c_str());

    assert(strlen(res) <= 256);
    printf(res);
    //printf("%d\n", strlen(res));

    return 0;
}
//

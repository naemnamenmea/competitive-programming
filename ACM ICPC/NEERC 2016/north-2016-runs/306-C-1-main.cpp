#include <bits/stdc++.h>

using namespace std;

#define taskname "codecoder"
#define taski taskname".in"
#define tasko taskname".out"

#define inp freopen(taski, "r", stdin)
#define outp freopen(tasko, "w", stdout)

#define mp make_pair
#define fi first
#define se second

const int N=(int)2e5+5;
int n,a,b,ans[N],Ans[N];
pair < pair <int,int > ,int > p[N];
set <pair <int,int > > s;

int main()
{
    inp;outp;
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        p[i]=mp(mp(a,b),i);
    }
    sort(p,p+n);
    for(int i=n-1;i>=0;i--)
    {
        a=p[i].fi.fi;
        b=p[i].fi.se;
        if(s.empty()||s.begin()->fi > b)
        {
            ans[i]=i;
            s.insert(mp(b,ans[i]));
            continue;
        }
        auto it=s.lower_bound(mp(b,0));
        it--;
        ans[i]=it->se;
        s.insert(mp(b,ans[i]));
    }
    for(int i=0;i<n;i++)
        Ans[p[i].se]=ans[i];
    for(int i=0;i<n;i++)
        cout << Ans[i] << endl;
    return 0;
}

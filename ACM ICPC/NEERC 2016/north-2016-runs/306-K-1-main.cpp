#include <bits/stdc++.h>

using namespace std;

#define taskname "king"
#define taski taskname".in"
#define tasko taskname".out"

#define inp freopen(taski, "r", stdin)
#define outp freopen(tasko, "w", stdout)

const int inf=(int)1e9;
int d,m,y,dayYear,ttime,n,s,M[200],Y[200],D[200],death,besttime,ans;
int cMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    inp; outp;
    ios_base::sync_with_stdio(false);
    cin >> d >> m >> y;
    d--;m--;
    for(int i=0;i<12;i++)
        dayYear+=cMonth[i];
    for(int i=0;i<m;i++)
        s+=cMonth[i];
    death=d+s+y*dayYear;
    besttime=inf;
    cin >> n;
    ans=-2;
    for(int i=0;i<n;i++)
    {
        cin >> D[i] >> M[i] >> Y[i];
        D[i]--;M[i]--;
        s=0;
        for(int j=0;j<M[i];j++)
            s+=cMonth[j];
        ttime=D[i]+s+Y[i]*dayYear;
        if(death-ttime<besttime&&death-ttime>=dayYear*18)
        {
            ans=i;
            besttime=death-ttime;
        }
    }
    cout << ans+1;
    return 0;
}

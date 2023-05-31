#include <bits/stdc++.h>

using namespace std;

#define taskname "boysgirls"
#define taski taskname".in"
#define tasko taskname".out"

#define inp freopen(taski, "r", stdin)
#define outp freopen(tasko, "w", stdout)

const string im="Impossible";

int a,x,y,n;

int main()
{
    inp; outp;
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    if(x+y<n)
    {
        cout << im;
        return 0;
    }
    if(x+y>2*n)
    {
        cout << im;
        return 0;
    }
    if(x+y==n+1)
    {
        cout << im;
        return 0;
    }
    if(x+y==n)
    {
        if(x!=0&&y!=0)
        {
            cout << im;
            return 0;
        }
        if(x==0)
        {
            for(int i=0;i<n;i++)
                cout << 'G';
        } else
        {
            for(int i=0;i<n;i++)
                cout << 'B';
        }
        return 0;
    }
    a=x+y-n;
    if(a%2==1)
    {
        cout << im;
        return 0;
    }
    int last=0;
    for(int i=0;i<a;i++)
        if(i%4<2)
        {
            cout << 'B';
            last=0;
        }else
        {
            cout << 'G';
            last=1;
        }
    for(int i=0;i<(n-a);i++)
        if((i+last)%2==0)cout << 'G'; else cout << 'B';
    return 0;
}

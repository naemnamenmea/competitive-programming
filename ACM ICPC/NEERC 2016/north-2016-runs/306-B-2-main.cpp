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
    if(a%2==0)
    {
        for(int i=0;i<a-2;i++)
            if(i%2==0)cout << 'G'; else cout << 'B';
        for(int i=0;i<(x-y+n-2)/2;i++)
            cout << 'B';
        for(int i=0;i<(y-x+n-2)/2;i++)
            cout << 'G';
        return 0;
    }
    cout << im;
    return 0;
}

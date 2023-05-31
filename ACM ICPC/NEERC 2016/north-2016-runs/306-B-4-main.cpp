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
    //swap(x,y);
    a=x+y-n;
    if(a%2==1)
    {
        cout << im;
        return 0;
    }
    int last=0;
    int t=min(n-y,n-x);
    int d= max(n-y,n-x);
    for(int i=0;i<t;i++)
        if(i%2==0)
        {
            cout << 'B';
            last=0;
        } else
        {
            cout << 'G';
            last=1;
        }
    bool need=true;
    for(int i=0;i<a;i++)
        if(i+last==0)
        {
            cout << "GG";
            if(need&&y>x)
            {
                for(int j=0;j<y-x;j++)
                    cout << "G";
                need=false;
            }
        } else
        {
            cout << "BB";
            if(need&&x>y)
            {
                for(int j=0;j<x-y;j++)
                    cout << "B";
                need=false;
            }
        }
    return 0;
}

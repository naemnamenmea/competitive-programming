#include <bits/stdc++.h>

using namespace std;

#define taskname "boysgirls"
#define taski taskname".in"
#define tasko taskname".out"

#define inp freopen(taski, "r", stdin)
#define outp freopen(tasko, "w", stdout)
int n,i,j,k,a,b,x,y,l,r;
int main()
{
    inp; outp;
    ios_base::sync_with_stdio(false);
    cin>>n>>l>>r;
    for( i=0;i<=n;i++ )
    {
        x=i;
        y=n-i;
        a=x;
        b=y;
        if( y )a++;
        if( x )b++;
//        cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
        if( l==a && r==b )
        {
            for( j=1;j<=x;j++ )cout<<"B";
            for( j=1;j<=y;j++ )cout<<"G";
            cout<<endl;
            return 0;
        }
    }
    cout<<"Impossible\n";
    return 0;
}

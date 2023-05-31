#include<iostream>
using namespace std;
long long a,b,h,w,x,y,k1,k2,m;
int main()
{
 freopen("folding.in" , "r" , stdin);
 freopen("folding.out" , "w" , stdout);
    cin>>h>>w>>a>>b;
    x=max(h,w);
    y=min(h,w);
    if (b>a) swap(a,b);
    while(x>a){
            //cout<<x<<endl;
        m=(x%2)+(x/2);
        if (m<=a && a<x){
            k1++;
            x=a;
        } else if (a<m){
            k1++;
            x=m;
        }
    }
    while(y>b){
        //cout<<"*"<<y<<endl;
        m=(y%2)+(y/2);
        if (m<=b && b<y){
            k1++;
            y=b;
        } else if (b<m){
            k1++;
            y=m;
        }
    }
    if (y!=b || x!=a) cout<<-1<<endl; else cout<<k1<<endl;
    return 0;
}

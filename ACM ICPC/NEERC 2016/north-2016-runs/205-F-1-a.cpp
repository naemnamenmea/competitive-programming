#include<iostream>
using namespace std;
long long a,b,h,w,x,y,k1,k2,m;
int main()
{
  freopen("folding.in" , "r" , stdin);
   freopen("folding.out" , "w" , stdout);
    cin>>h>>w>>a>>b;
    x=h;
    y=w;
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
    if (y!=b || x!=a) k1=-1;
    x=h;
    y=w;
    while(x>b){
        m=(x%2)+(x/2);
        if (m<=b && b<x){
            k2++;
            x=b;
        } else if (b<m){
            k2++;
            x=m;
        }
    }
    while(y>a){
        m=(y%2)+(y/2);
        if (m<=a && a<y){
            k2++;
            y=a;
        } else if (a<m){
            k2++;
            y=m;
        }
    }
    if (y!=a || x!=b) k2=-1;
    cout<<min(k1,k2)<<endl;
    return 0;
}

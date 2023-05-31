#include<iostream>
using namespace std;
long long a,b,h,w,x,y,k1,k2;
int main()
{
freopen("folding.in" , "r" , stdin);
freopen("folding.out" , "w" , stdout);
    cin>>h>>w>>a>>b;
    x=h;
    y=w;
    if (x<a || y<b) {
        k1=-1;
    } else {
    while(x>a){
            //cout<<x<<endl;
        x/=2;
        k1++;
    }
    while(y>b){
        //cout<<"*"<<y<<endl;
        y/=2;
        k1++;
    }
    }
    x=w;
    y=h;
    if (x<a || y<b) {
        k2=-1;
    } else {
    while(x>a){
            //cout<<x<<endl;
        x/=2;
        k2++;
    }
    while(y>b){
        //cout<<"*"<<y<<endl;
        y/=2;
        k2++;
    }
    }
    if (k1==-1 && k2==-1) cout<<-1<<endl; else
    if (k2==-1) cout<<k1<<endl; else
    if (k1==-1) cout<<k2<<endl; else cout<<min(k1,k2)<<endl;
    return 0;
}

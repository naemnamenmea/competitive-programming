#include<iostream>
using namespace std;
long long a,b,h,w,x,y,k;
int main()
{
 freopen("folding.in" , "r" , stdin);
 freopen("folding.out" , "w" , stdout);
    cin>>h>>w>>a>>b;
    x=max(h,w);
    y=min(h,w);
    if (b>a) swap(a,b);
    if (x<a || y<b) {
        cout<<-1<<endl;
        return 0;
    }
    while(x>a){
            //cout<<x<<endl;
            x/=2;
            k++;
    }
    while(y>b){
        //cout<<"*"<<y<<endl;
        y/=2;
        k++;
    }
    cout<<k<<endl;
    return 0;
}

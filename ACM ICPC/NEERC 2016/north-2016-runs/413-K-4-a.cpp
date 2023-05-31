#include <iostream>

using namespace std;
int daypr(int a,int b, int c)
{
    int day;
    day=c*365;
    if(b>1)
        day=day+31;
    if(b>2)
        day=day+28;
    if(b>3)
        day=day+31;
    if(b>4)
        day=day+30;
    if(b>5)
        day=day+31;
    if(b>6)
        day=day+30;
    if(b>7)
        day=day+31;
    if(b>8)
        day=day+31;
    if(b>9)
        day=day+30;
    if(b>10)
        day=day+31;
    if(b>11)
        day=day+30;
    day=day+a;
    return day;
}
int main()
{
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);
    int a1[101],a2[101],a3[101];
    long long day[101];
    int i=1,n,m=0;
    long long kol=0;
    cin>>a1[0]>>a2[0]>>a3[0];
    cin>>n;
    day[0]=daypr(a1[0],a2[0],a3[0]);

    while(i<=n)
    {
        cin>>a1[i]>>a2[i]>>a3[i];
        day[i]=daypr(a1[i],a2[i],a3[i]);
        if(((day[0]-day[i])>(365*18-1))&&(kol<day[i])) {kol=day[i];m=i;}
        i++;
    }
    if(m==0)
    cout<<"-1";
    else cout<<m;
}

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cmath>
using namespace std;

double area(long long int x1,long long int y1,long long int x2,long long int y2,long long int x3,long long int y3)
{
    double a1=x2-x1;
    double b1=y2-y1;
    double a2=x3-x1;
    double b2=y3-y1;
    return abs(b1*a2-a1*b2)/2;
}

int main()
{
    fstream fin ("integral.in");
    ofstream fout ("integral.out");
    int n;
    long long int m=0;
    fin>>n;
    long long int*x=new long long int [n];
    long long int*y=new long long int [n];
    fin>>x[0]>>y[0];
    int f=0;
    int p,q;
    for (int i=2;i<=n;i++)
    {
        fin>>p>>q;
        if ((p!=x[i-2])||(q!=y[i-2]))
            {x[i-1]=p;
            y[i-1]=q;}
        else
        f++;


    }

    double sum=0;
    for (int i=2;i<=n-1-f;i++)
        {
            sum+=area(x[0],y[0],x[i],y[i],x[i-1],y[i-1]);

        }
    if (int (sum)!=sum)
    {
        fout<<0;
        return 0;
    }
    double SUM=sum;
    sum =0;
     for (int i=2;i<n-1-f;i++)
        {
            sum+=area(x[0],y[0],x[i],y[i],x[i-1],y[i-1]);
            if ((int(sum)==sum)&&(sum!=0)&&(sum!=SUM)) m++;
        }

    for (int i=1;i<=n-3-f;i++)
    { sum=0;
        for(int j=i+2;j<=n-1-f;j++)
        {
            sum+=area(x[i],y[i],x[j],y[j],x[j-1],y[j-1]);
            if ((int(sum)==sum)&&(sum!=0)&&(sum!=SUM)) m++;
        }

    }
    fout<<m;

    return 0;
}

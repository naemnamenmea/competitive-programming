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
    return fabs(b1*a2-a1*b2)/2;
}

int main()
{
    fstream fin ("integralin.txt");
    ofstream fout ("integralout.txt");
    int n;
    long long m=0;
    fin>>n;
    long long*x=new long long[n];
    long long*y=new long long[n];
    for (int i=1;i<=n;i++)
    {
        fin>>x[i-1]>>y[i-1];
    }
    double sum=0;
    for (int i=2;i<=n-1;i++)
        {
            sum+=area(x[0],y[0],x[i],y[i],x[i-1],y[i-1]);

        }
    if (int (sum)!=sum)
    {
        fout<<0;
        return 0;
    }

    sum =0;
     for (int i=2;i<=n-1;i++)
        {
            sum+=area(x[0],y[0],x[i],y[i],x[i-1],y[i-1]);
            if (int(sum)==sum) m++;
        }

    for (int i=1;i<=n-3;i++)
    { sum=0;
        for(int j=i+2;j<=n-1;j++)
        {
            sum+=area(x[i],y[i],x[j],y[j],x[j-1],y[j-1]);
            if (int(sum)==sum) m++;
        }

    }
    if (n>5) fout<<m;
    else
    fout<<m-1;
    return 0;
}

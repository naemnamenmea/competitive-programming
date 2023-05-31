#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cmath>
using namespace std;

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    float a1=x2-x1;
    float b1=y2-y1;
    float a2=x3-x1;
    float b2=y3-y1;
    return fabs(b1*a2-a1*b2)/2;
}

int main()
{
    fstream fin ("integral.in");
    ofstream fout ("integral.out");
    int n;
    int m=0;
    fin>>n;
    int*x=new int[n];
    int*y=new int[n];
    for (int i=1;i<=n;i++)
    {
        fin>>x[i-1]>>y[i-1];
    }
    float sum=0;
    for (int i=2;i<=n-1;i++)
        {
            sum+=area(x[0],y[0],x[i],y[i],x[i-1],y[i-1]);

        }
    if (int (sum)!=sum)
    {
        fout<<0;
        return 0;
    }
    float SUM=sum;
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
    fout<<m-1;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,x,y,a,x1,y1;
    string g1,g2,g3;
    freopen("boysgirls.in", "r", stdin);
    freopen("boysgirls.out", "w", stdout);
    cin >> n >> x >> y;
    a=x+y-n;
    x1=x-a;
    y1=y-a;
    if(a<0)
    {
      cout << "Impossible";
    }
    else
    {

    if(a%2==1)
    {
        cout << "Impossible";
    }
    if(a==0)
    {
        if(n%2==1)
        {
           cout << "Impossible";
        }
        else
        {
            if((x1==n/2)&&(y1==n/2))
            {
                for(int i=0;i<n/2;i++)
                {
                    g3=g3+"B"+"G";
                }
                cout << g3;
            }
            else
            {
                if(x1==0)
                {
                    for(int i=0;i<n;i++)
                    {
                    g3=g3+"G";
                    }
                    cout << g3;
                }
                else
                {
                if(y1==0)
                {
                    for(int i=0;i<n;i++)
                    {
                    g3=g3+"B";
                    }
                    cout << g3;

                }
                else
                cout << "Impossible";
                }
            }
        }
    }
    if((n%2==1)&&(a%2==0)&&(a!=0))
    {
        for(int i=0;i<x1+1;i++)
        {
            g1=g1+"B";
        }
        for(int i=0;i<y1+1;i++)
        {
            g1=g1+"G";
        }
        for(int i=0;i<a-4;i++)
        {
            g1=g1+"B"+"G";
        }
        int j=0;
        for(int i=0;i<n;i++)
        {
            g3=g3+g1[j];
            j=(j+(n+1)/2)%n;
        }
    }
    if((n%2==0)&&(a%2==0)&&(a!=0))
    {
        if(a==2)
        {
            if(x1>=n/2)
            {
                for(int i=0;i<n/2;i++)
                {
                    g1=g1+"B";
                }
                for(int i=0;i<=x1-n/2;i++)
                {
                    g2=g2+"B";
                }
                for(int i=0;i<=y1;i++)
                {
                    g2=g2+"G";
                }
            }
            else
            {
                for(int i=0;i<n/2;i++)
                {
                    g1=g1+"G";
                }
                for(int i=0;i<=y1-n/2;i++)
                {
                    g2=g2+"G";
                }
                for(int i=0;i<=x1;i++)
                {
                    g2=g2+"B";
                }
            }
        }
        if(a>2)
        {

            if(x1>=n/2)
            {

                for(int i=0;i<n/2-1;i++)
                {
                    g1=g1+"B";
                }
                    g1=g1+"G";
                for(int i=0;i<x1-n/2+1;i++)
                {
                    g2=g2+"B";
                }
                for(int i=0;i<=y1;i++)
                {
                    g2=g2+"G";
                }
                for(int i=0;i<a-4;i++)
                {
                    g2=g2+"B";
                    g2=g2+"G";
                }
            }
            if(x1==n/2-1)
            {
                for(int i=0;i<n/2-1;i++)
                {
                    g1=g1+"B";
                }
                g1=g1+"G";
                for(int i=0;i<2;i++)
                {
                    g2=g2+"B";
                }
                for(int i=0;i<=y1;i++)
                {
                    g2=g2+"G";
                }
                for(int i=0;i<a-4;i++)
                {
                    g2=g2+"B";
                    g2=g2+"G";
                }

            }
            if(x1<n/2-1)
            {
                if((n/2-x1-1)%2==1)
                {

                    for(int i=0;i<x1+1;i++)
                    {
                        g1=g1+"B";
                    }
                    for(int i=0;i<(n/2-x1-1)/2;i++)
                    {
                        g1=g1+"G";
                        g1=g1+"B";
                    }
                    g1=g1+"G";
                    for(int i=0;i<y1+1;i++)
                    {
                        g2=g2+"G";
                    }
                    for(int i=0;i<(n/2-y1-1)/2;i++)
                    {
                        g2=g2+"B";
                        g2=g2+"G";
                    }
                    g2=g2+"B";

                }
                if((n/2-x1-1)%2==0)
                {
                    for(int i=0;i<x1;i++)
                    {
                        g1=g1+"B";
                    }
                    for(int i=0;i<(n/2-x1)/2;i++)
                    {
                        g1=g1+"G";
                        g1=g1+"B";
                    }
                    g1=g1+"G";
                    for(int i=0;i<2;i++)
                    {
                        g2=g2+"B";
                    }
                    for(int i=0;i<y1+1;i++)
                    {
                        g2=g2+"G";
                    }
                    for(int i=0;i<(n/2-y1-3)/2;i++)
                    {
                        g2=g2+"B";
                        g2=g2+"G";
                    }

                }

            }

        }
        for(int i=0;i<n/2;i++)
            {
                g3=g3+g1[i]+g2[i];
            }
        cout<<g3;
    }
    }
    return 0;
}

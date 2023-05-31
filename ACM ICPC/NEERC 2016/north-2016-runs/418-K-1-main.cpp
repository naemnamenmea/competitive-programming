#include <iostream>
#include <fstream>
using namespace std;



int main()
{
    ifstream fin ("king.in");
    ofstream fout ("king.out");
    int dayx,monthx,yearx;

    fin>>dayx>>monthx>>yearx;
    int n;
    fin>>n;
    int l=-1;

    int kyear=0;
   int  kmonth=0;
   int  kday=0;
   int myear,mmonth,mday;
    for(int i=1;i<=n;i++)
    {
        fin>>mday>>mmonth>>myear;
        if ((yearx-myear<18)||((yearx-myear==18)&&(monthx-mmonth<0))||((yearx-myear==18)&&(monthx==mmonth)&&(dayx-mday<0)))
            continue;
        else
            if ((myear>kyear)||((myear==kyear)&&(mmonth>kmonth))||((myear==kyear)&&(mmonth==kmonth)&&(mday>kday)))
                {kyear=myear; kmonth=mmonth;kday=mday;
                l=i;
                }
    }
        fout<<l;
}

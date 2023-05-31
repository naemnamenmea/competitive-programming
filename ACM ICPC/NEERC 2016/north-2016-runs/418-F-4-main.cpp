#include <iostream>
#include <fstream>
using namespace std;



int main()
{
    ifstream fin ("folding.in");
    ofstream fout ("folding.out");
    long long int W,H,w,h,maxx,minn;
    fin>>W>>H>>w>>h;
    maxx=W;
    minn=H;
    W=max(maxx,minn);
    H=min(maxx,minn);
    maxx=w;
    minn=h;
    w=max(maxx,minn);
    h=min(maxx,minn);
    if ((w<=W) && (h<=H))
    {
        long long int i=w,k1=0,l1=0,k2=0,l2=0;
        while (i<W)
        {
            i*=2;
            k1++;
        }
        i=h;
        while (i<H)
        {
            i*=2;
            l1++;
        }
        i=h;
        while (i<W)
        {
            i*=2;
            k2++;
        }
        i=w;
        while (i<H)
        {
            i*=2;
            l2++;
        }
        fout<<min(k1+l1,k2+l2);
    }
    else
        fout<<-1;
    return 0;
}

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
        long long int i=w,k=0,l=0;
        while (i<W)
        {
            i*=2;
            k++;
        }
        i=h;
        while (i<H)
        {
            i*=2;
            l++;
        }
        fout<<k+l;
    }
    else
        fout<<-1;
    return 0;
}

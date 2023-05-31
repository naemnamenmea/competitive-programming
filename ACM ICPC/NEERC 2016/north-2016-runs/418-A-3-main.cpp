#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("anniversary.in");
    ofstream fout ("anniversary.out");
    int w,h,ax,ay,bx,by,i=0,j=0;
    fin>>w>>h>>ax>>ay>>bx>>by;
    if ((ax-bx)*(ax-bx)+(ay-by)*(ay-by)>1)
    {
        if(abs(ax-bx)>=2)
        {
            fout<<min(ax,bx)+1<<" "<<0<<" "<<min(ax,bx)+1<<" "<<h;
            return 0;
        }
        if(abs(ay-by)>=2)
        {
            fout<<0<<" "<<min(ay,by)+1<<" "<<w<<" "<<min(ay,by)+1;
            return 0;
        }
        if((ax-bx)*(ax-bx)+(ay-by)*(ay-by)==2)
        {
         if((ax-bx)*(ay-by)>0)
         {
             int k=min(ax,bx);
             int l=max(ay,by);
             while ((k!=w) && (l!=0))
             {
                 k++;
                 l--;
             }
             fout<<k<<" "<<l<<" ";
             k=min(ax,bx),l=max(ay,by);
             while ((k!=0)&& (l!=h))
             {
                 k--;
                 l++;
             }
             fout<<k<<" "<<l;
             return 0;
         }
         else
         {
             int k=min(ax,bx),l=min(ax,by);
             while ((k!=w) && (l!=h))
             {
                 k++;
                 l++;
             }
             fout<<k<<" "<<l<<" ";
             while ((k!=0)&&(l!=0))
             {
                 k--;
                 l--;
             }
             fout<<k<<" "<<l;
             return 0;
         }
        }


    }
    if ((ax==bx) && (abs(ay-by)==1))
    {
        fout<<0<<" "<<max(ay,by)<<" "<<w<<" "<<min(ay,by);
        return 0;
    }
    if ((ay==by) && (abs(ax-bx)==1))
    {
        fout<<max(ax,bx)<<" "<<0<<" "<<min(ax,bx)<<" "<<h;
        return 0;
    }
    return 0;
}

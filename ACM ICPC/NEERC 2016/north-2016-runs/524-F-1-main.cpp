#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("folding.in");
    ofstream fout("folding.out");
    int w,h;
    int tw,th;
    int c;
    fin >> w >> h >> tw >> th;
    fin.close();

    if((tw>w)||(th>h))
    {
        c=w;
        w=h;
        h=c;
    }

    if((tw>w)||(th>h))
    {
        fout << -1;
        return 0;
    }


    int k=0;

    while(true)
    {
    if(w>tw)
    {
        if((w/2)>tw)
        {
            w=w-(w/2)+1;
            k++;
        }
        else
        {
            w=tw;
            k++;
        }
    }
    if(h>th)
    {
        if((h/2)>th)
        {
            h=h-(h/2)+1;
            k++;
        }
        else
        {
            h=th;
            k++;
        }
    }
    if((w==tw) && (h==th))
        break;
    }

    fout << k;
    fout.close();
    return 0;
}

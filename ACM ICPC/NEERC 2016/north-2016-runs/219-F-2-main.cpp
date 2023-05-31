#include <fstream>

using namespace std;

int main()
{
    ifstream in("folding.in");
    ofstream out("folding.out");
    int W, H, w, h,i=0;
    in>>W>>H>>w>>h;
    if (W<H)
    {
        swap(W,H);
    }
    if (w<h)
    {
        swap(w,h);
    }
    if (h>H||w>W)
        {
        out<<-1;
    }
    else {
        while (W!=w||H!=h){
            if (w<W/2)
            {
                W=W/2+(W%2);
                i++;
            } else if (W!=w)
            {
                 W=w; i++;
            }

            if (h<H/2)
            {
                H=H/2+(H%2);
                i++;
            }
            else if (H!=h)
            {
                H=h; i++;
            }

        }
        out<<i;
    }



    return 0;
}

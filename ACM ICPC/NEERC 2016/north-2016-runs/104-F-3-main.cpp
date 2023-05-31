#include <iostream>

using namespace std;

int main()
{
int x,y,w,h,k; float s;

 FILE *In, *Out;
In=fopen("folding.in","r");
Out=fopen("folding.out","w");
fscanf(In,"%d", & x );
fscanf(In,"%d", & y );
fscanf(In,"%d", & w );
fscanf(In,"%d", & h );
k=0;s=x*y;
if ((w>x && w>y) || (h>x && h>y)) {k=-1;} else{
    if (w>x || w>y || h>x || h>y) { k=k+1;

        while (s>w*h)

            {s=s/2;k++;}    }

         else



                                            {while (s>w*h) {s=s/2;k++;};};}
          fprintf(Out,"%d", k);

    return 0;
}

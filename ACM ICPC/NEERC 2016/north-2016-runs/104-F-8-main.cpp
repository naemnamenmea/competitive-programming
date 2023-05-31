#include <iostream>

using namespace std;

int main()
{
long int x,y,w,h,k,l;
 FILE *In, *Out;
In=fopen("folding.in","r");
Out=fopen("folding.out","w");
fscanf(In,"%d", & x );
fscanf(In,"%d", & y );
fscanf(In,"%d", & w );
fscanf(In,"%d", & h );
k=0;
if ((w>x && w>y) || (h>x && h>y)) {k=-1;} else{
    if (w>x || w>y || h>x || h>y) { l=x,x=y,y=l;

        while (x>=w)

            {if (x==w) {k--;} ; x=x/2;k++;}
            while (y>=h)

            {if (y==h) {k--;} ; y=y/2;k++;}   }

         else {

while (x>=w)
            {if (x==w) {k--;} ;x=x/2;k++;}
            while (y>=h)

            {if (y==h)  {k--;}; y=y/2;k++;} } }


          fprintf(Out,"%d", k);

    return 0;
}

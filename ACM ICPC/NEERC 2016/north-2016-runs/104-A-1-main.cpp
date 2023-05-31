#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<array>
#include<math.h>
using namespace std;

int main()
{
int w,h,ax,ay,bx,by;
int x2m,x1m;
FILE *In, *Out;
In=fopen("anniversary.in","r");
Out=fopen("anniversary.out","w");
fscanf(In,"%d", & w );
fscanf(In,"%d", & h );
fscanf(In,"%d", & ax );
fscanf(In,"%d", & ay );
fscanf(In,"%d", & bx );
fscanf(In,"%d", & by );

x2m=((h*bx)/by)+((h*bx)%by);
if (x2m%10!=0) {x2m=x2m-1;} else {x2m=(x2m/10)-1;}


 fprintf(Out,"0","%d" );
     fprintf(Out," ");
                    fprintf(Out,"0","%d" );
                              fprintf(Out," ");
                        fprintf(Out,"%d",x2m);
                        fprintf(Out," ");
                          fprintf(Out,"%d",h);

    return 0;
}

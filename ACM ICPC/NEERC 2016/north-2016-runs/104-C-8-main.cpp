#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<array>
using namespace std;

int main()
{

int i,n,d;
FILE *In, *Out;
In=fopen("codecoder.in","r");
Out=fopen("codecoder.out","w");
fscanf(In,"%d", & n );


int a[2*n]; int b[n];


for ( i=0;i<n;i++){
   fscanf(In,"%d", & a[i]);
   fscanf(In,"%d", & b[i]);}



     for (i=0;i<n;i++){
        d=0;
        for (int j=0;j<n;j++){ if (i!=j) {
            if (a[i]>a[j] || b[i]>b[j] || a[i]>b[j] ||  b[i]>a[j]) {d++;}
                    }}

                    fprintf(Out,"%d", d);
                              fprintf(Out," ");
                       }

    return 0;
}

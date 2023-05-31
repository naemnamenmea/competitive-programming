#include <stdio.h>
#include <math.h>
int main () {
FILE * bgin;
FILE * bgout;
int all,x,y;
bgin = fopen("folding.in","r");
bgout = fopen("folding.out","w");
int a,b,c,d,l,m,p,a1,a2;
fscanf(bgin, "%d%d", &a, &b);
fscanf(bgin, "%d%d", &c,&d);
float k,n;
//a=63; b=80; c=9; d=8;
k=(float)a/c;
if ((a/c) < 1) {
    l=-1;
}
else {
    l=0;
    while (k>1) {
        l++;
        k=k/2;
    }
}

k=(float)b/d;

if ((b/d) < 1) {
    m=-1;
}
else {
    m=0;
    while (k>1) {
        m++;
        k=k/2;
    }
}
if ((l==-1)||(m==-1))
       a1=-1;
    else
    a1=l+m;

p=d;
d=c;
c=p;

k=(float)a/c;
if ((a/c) < 1) {
    l=-1;
}
else {
    l=0;
    while (k>1) {
        l++;
        k=k/2;
    }
}


k=(float)b/d;

if ((b/d) < 1) {
    m=-1;
}
else {
    m=0;
    while (k>1) {
        m++;
        k=k/2;
    }
}
    if ((l==-1)||(m==-1))
        a2=-1;
    else
    a2=l+m;

if ((a1==-1)&&(a2==-1)) {
    fprintf(bgout,"%d",-1);
}
else if (a1==-1){
        fprintf(bgout,"%d",a2);
}
else if (a2==-1){
        fprintf(bgout,"%d",a1);
}
else if (a1<a2) fprintf(bgout,"%d",a1);
else fprintf(bgout,"%d",a2);

return 0;
}

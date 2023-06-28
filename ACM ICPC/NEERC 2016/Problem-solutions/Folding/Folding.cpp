#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int W,H;
    int w,h;
    scanf("%d%d",&W,&H);
    scanf("%d%d",&w,&h);
    if(W<w||H<h) swap(W,H);
    if(W<w||H<h) {
        printf("-1\n");
        return 0;
    }
    int t=0;
    while(W>w||H>h) {
        if(W==h*2||H==w*2) swap(W,H);
        if(W>w) {W-=W/2;t++;}
        if(H>h) {H-=H/2;t++;}
    }
    printf("%d\n",t);
    return 0;
}
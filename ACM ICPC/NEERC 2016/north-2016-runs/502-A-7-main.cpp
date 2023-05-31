#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("anniversary.in");
    ofstream out("anniversary.out");
    long long w,h,ay,ax,by,bx;
    in>>w>>h>>ax>>ay>>bx>>by;
    if (bx<ax ){
        swap(bx,ax);
        swap(by,ay);
    }
    if (ax!=bx && ay!=0 && (by!= h || bx!= ax+1)  ){
        if (ay!=h && (by!=0 || bx!=ax+1)){
            out<<ax<<" 0 "<<ax+1<<" "<<h;
        };
    };
    if ((ay==0 && (by ==h || bx == ax+1)))
        {
        out<<bx<<" "<<0<<" "<<ax<<" "<<h; };

       if ((ay==h && (by == 0 || bx == ax+1))&&(ax!=bx))
       {
         out<<ax<<" 0 "<<bx<<" "<<h;
       };

            if(ax==bx) {out<<0<<" "<<ay+1<<" "<<w<<" "<<ay+1;};



}

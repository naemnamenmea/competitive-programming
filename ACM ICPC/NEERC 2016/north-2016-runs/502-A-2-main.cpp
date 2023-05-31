#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("anniversary.in");
    ofstream out("anniversary.out");
    int w,h,ay,ax,by,bx;
    in>>w>>h>>ax>>ay>>bx>>by;
    if (bx<ax ){
        swap(bx,ax);
        swap(by,ay);
    }
    if (ay!=0 && (by!= h || bx!= ax+1) ){
        if (ay!=h && (by!=0 || bx!=ax+1)){
            out<<ax<<" 0 "<<ax+1<<" "<<h;
        }
    }
    if ((ay==0 && (by ==h || bx == ax+1)) ||(ay==h && (by == 0 || bx == ax+1)))
        {
        out<<bx<<" "<<0<<" "<<ax<<" "<<h;
    }


}

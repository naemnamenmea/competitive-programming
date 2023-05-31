#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("anniversary.in");
    ofstream out("anniversary.out");
    int w,h,ay,ax,by,bx;
    in>>w>>h>>ax>>ay>>bx>>by;

    if (ay!=0 && by!= h){
        if (ay!=h && by!=0){
            out<<ax<<" 0 "<<ax+1<<" "<<h;
        }
    }
    if ((ay==0 && by ==h) ||(ay==h && by == 0)){
        out<<"0 1 "<<w<<" 1";
    }


}

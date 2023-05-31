#include <iostream>
#include <fstream>

int sqr(int y){
if (y<0){
    return y*(-1);
}
else{
    return y;
}}
using namespace std;

int main()
{
    int a,b,x1,x2,y1,y2;
    ifstream in("anniversary.in");
    ofstream out("anniversary.out");

    in>>a>>b;
    in>>x1>>y1;
    in>>x2>>y2;

    if (sqr(x1-x2) >=2){
        if (x1>x2){
            out<<x1-1<<" 0 "<<x1-1<<" "<<b;
        }
        else{
            out<<x2-1<<" 0 "<<x2-1<<" "<<b;
        }
    }
    else{
        if (sqr(y1-y2) >= 2){
            if (y1>y2){
                out<<0<<" "<<y1-1<<" "<<a<<" "<<y1-1;
            }
            else{
                out<<0<<" "<<y2-1<<" "<<a<<" "<<y2-1;
            }
        }
        else{
            if (y1>=y2){
                out<<x1<<" 0 "<<x2<<" "<<b;
            }
            else{
                out<<x2<<" 0 "<<x1<<" "<<b;
            }
        }
    }

}

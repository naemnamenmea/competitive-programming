#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("folding.in");
    ofstream out("folding.out");
    float a,b,c,d,kol=0;

    in>>a>>b;
    in>>c>>d;
    if (a<b){
        swap(a,b);
    }
    if (c<d){
        swap(c,d);
    }
    if (c>a || d>b){
        out<<-1;
    }
    else{
    while (a>c){
        a /=2;
        kol++;
    }
    while (b>d){
        b /=2;
        kol++;
    }
    out<<kol;
    }

}

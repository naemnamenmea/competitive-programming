#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("folding.in");
    ofstream out("folding.out");
    double a,b,c,d,kol=0,n=1;

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
         while(n<a){
            n *=2;

         }

         while(n>c){
            n/=2;
            kol++;
         }

         n=1;
         while(n<b){
            n *=2;

         }

         while(n>d){
            n/=2;
            kol++;
         }

out<<kol;
    }

}

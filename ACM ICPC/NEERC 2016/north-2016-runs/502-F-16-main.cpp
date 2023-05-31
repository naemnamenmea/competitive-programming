#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("folding.in");
    ofstream out("folding.out");
    long long a,b,c,d,kol=0,n=1;

    in>>a>>b;
    in>>c>>d;

    if (a== c){}
       else{
            if (a==d){
                swap(c,d);
            }
            else{
                if (b ==c){
                    swap(c,d);
                }
                    else{
                        if (b==d){}
                            else{
                                if (a<b ){
                        swap(a,b);
                                    }
                                if (c<d ){
                                    swap(c,d);
                                        }
                            }
                    }
            }
        }




    if (c>a || d>b){
        out<<-1;
    }
    else{
         if (a!=c){
         while(a>c){
            a /=2;
            kol++;

         }


         }
         n=1;
         if (b!=d){
         while(b>d){
            b /=2;
            kol++;

         }


         }
out<<kol;
    }

}

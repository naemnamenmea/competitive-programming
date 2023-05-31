#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("folding.in");
    ofstream out("folding.out");
    float a,b,c,d,t,y,u,i;
    int kol=0;

    in>>a>>b;
    in>>c>>d;
    t=a;y=b;u=c;i=d;

    //if (a== c){}
      /* else{
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
*/



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

         if (b!=d){
         while(b>d){
            b /=2;
            kol++;

         }


         }

         int kol1=0;
         a=t;b=y;c=u;d=i;
         swap(c,d);
         if (a!=c){
         while(a>c){
            a /=2;
            kol1++;

         }


         }

         if (b!=d){
         while(b>d){
            b /=2;
            kol1++;

         }


         }
         int kol2=0;
         a=t;b=y;c=u;d=i;
         swap(a,b);
         if (a!=c){
         while(a>c){
            a /=2;
            kol2++;

         }


         }

         if (b!=d){
         while(b>d){
            b /=2;
            kol2++;

         }


         }
         int kol3=0;
         a=t;b=y;c=u;d=i;
         swap(a,b);
         swap(c,d);
         if (a!=c){
         while(a>c){
            a /=2;
            kol3++;

         }


         }

         if (b!=d){
         while(b>d){
            b /=2;
            kol3++;

         }


         }

out<<min(min(kol,kol1),min(kol2,kol3));

}
}

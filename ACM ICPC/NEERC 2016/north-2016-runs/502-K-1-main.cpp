#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int t,z[10000][3],q,w,e,n;
void st(){
z[t][0] = e;
z[t][1] = w;
z[t][2] = q;
}
void ssort(){
    for (int i =0;i<n;i++){
        for (int j=0;j<n;j++){
            if (z[i][0]<z[j][0]){
                swap(z[i][0],z[j][0]);
                swap(z[i][1],z[j][1]);
                swap(z[i][2],z[j][2]);
            }
            else{
                if (z[i][0] == z[j][0] && z[i][1]<z[j][1]){
                    swap(z[i][0],z[j][0]);
                swap(z[i][1],z[j][1]);
                swap(z[i][2],z[j][2]);
                }
                else{
                    if(z[i][0] == z[j][0] && z[i][1]==z[j][1] && z[i][2]<z[j][2]){
                        swap(z[i][0],z[j][0]);
                swap(z[i][1],z[j][1]);
                swap(z[i][2],z[j][2]);

                    }
                }
            }
        }
    }
}
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int a,b,c,f[10000][3];
    in>>a>>b>>c;

    in>>n;

    for (t =0 ;t<n;t++){
        in>>q>>w>>e;
        if (e+18 <c){
            st();
        }
        else{
        if (e+18 == c && w<b){
            st();
        }
        else{
            if (e+18 == c && w== b && q<=a){
                st();
            }
        }
    }
    f[t][0] = e;
    f[t][1] = w;
    f[t][2] = q;
    }
    ssort();
    if (z[n-1][0] == 0){
        out<<"-1";
    }
    else{
        for (t =0;t<n;t++){
            if (z[n-1][0] == f[t][0] &&z[n-1][1] == f[t][1] &&z[n-1][2] == f[t][2] ){
                out<<t+1;
                break;
            }
        }
}
}

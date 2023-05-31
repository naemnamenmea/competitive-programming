#include <fstream>

using namespace std;

int main(){
    ifstream in("boysgirls.in");
    int n, b, g;
    in>>n>>b>>g;
    in.close();

    ofstream out("boysgirls.out");
    if(!((b - 1) + (g - 1) != n) || b == 0 || g == 0){
        if(b < g){
            for(int i = 0; i < (b - 1); i++){
                out<<"BG";
            }
            for(int i = (b - 1); i < (g - 1); i++){
                out<<"G";
            }
        }
        else{
            for(int i = 0; i < (g - 1); i++){
                out<<"GB";
            }
            for(int i = (g - 1); i < (b - 1); i++){
                out<<"B";
            }
        }
    }
    else{
        out<<"Impossible";
    }

    out.close();
}

#include <fstream>

using namespace std;

int main(){
    ifstream in("folding.in");
    long W, H, w, h;
    in>>W>>H>>w>>h;
    in.close();

    ofstream out("folding.out");
    if(W < w){
        if(W < h){
            out<<-1;
            return 0;
        }
        else if(H < w){
            out<<-1;
            return 0;
        }
        else{
            long tmp = w;
            w = h;
            h = tmp;
        }
    }
    else if(H < h){
        if(H < w){
            out<<-1;
            return 0;
        }
        else if(W < h){
            out<<-1;
            return 0;
        }
        else{
            long tmp = w;
            w = h;
            h = tmp;
        }
    }

    long folds = 0;
    while(W > w){
        W = W%2 + W/2; //long(W/2.0 + 0.5);
        ++folds;
    }
    while(H > h){
        H = H%2 + H/2; //long(H/2.0 + 0.5);
        ++folds;
    }

    out<<folds;

    out.close();
    return 0;
}

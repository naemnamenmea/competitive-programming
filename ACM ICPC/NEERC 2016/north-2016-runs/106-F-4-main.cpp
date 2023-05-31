#include <fstream>

using namespace std;

int main(){
    ifstream in("folding.in");
    long W, H, w, h;
    in>>W>>H>>w>>h;
    in.close();

    int swapped = 0;
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
            swapped = 1;
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
            swapped = 1;
        }
    }

    long folds = 0;
    int TW = W;
    int TH = H;
    while(W > w){
        W = W%2 + W/2;
        ++folds;
    }
    while(H > h){
        H = H%2 + H/2;
        ++folds;
    }

    if(!swapped){
        long foldsALT = 0;
        while(TW > h){
            TW = TW%2 + TW/2;
            ++foldsALT;
        }
        while(TH > w){
            TH = TH%2 + TH/2;
            ++foldsALT;
        }
        folds = min(folds, foldsALT);
    }

    out<<folds;

    out.close();
    return 0;
}

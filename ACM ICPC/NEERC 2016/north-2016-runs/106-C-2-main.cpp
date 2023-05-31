#include <fstream>

using namespace std;

int main(){
    ifstream in("codecoder.in");
    int n;
    in>>n;
    int* cc = new int[n];
    int* tf = new int[n];

    for(int i = 0; i<n; i++){
        in>>cc[i]>>tf[i];
    }
    in.close();

    bool** citizen = new bool*[n];
    int* totalValues = new int[n];

    for(int i = 0; i < n; i++){
        totalValues[i] = 0;
        citizen[i] = new bool[n];
        for(int j = 0; j < n; j++){
            citizen[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((cc[i] > cc[j]) || (tf[i] > tf[j])){
                citizen[i][j] = true;
            }
        }
    }

    delete [] cc;
    delete [] tf;

    for(int i = 0; i < n; i++){
        bool* citizen1 = citizen[i];
        for(int j = 0; j < n; j++){
            if(citizen1[j]){
                bool* citizen2 = citizen[j];
                for(int k = 0; k < n; k++){
                    if(k != i){
                        citizen1[k] = citizen1[k] || citizen2[k];
                    }
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(citizen1[j]){
                totalValues[i]++;
            }
        }
    }

    ofstream out("codecoder.out");

    for(int i = 0; i<n; i++){
        out<<totalValues[i]<<endl;
    }

    for(int i = 0; i < n; i++){
        delete [] citizen[i];
    }
    delete [] citizen;
    delete [] totalValues;

    out.close();
}

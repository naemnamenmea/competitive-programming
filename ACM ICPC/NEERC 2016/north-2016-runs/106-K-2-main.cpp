#include <fstream>
#include <cmath>

using namespace std;

void work(int i, int dead_y, int dead_m, int dead_d, int n, int* year, int* month, int* day, int& currMinI, int& currMinYear, int& currMinMonth, int& currMinDay){
    if(year[i] > currMinYear){
        currMinYear = year[i];
        currMinMonth = month[i];
        currMinDay = day[i];
        currMinI = i;
    }
    else if(year[i] == currMinYear){
        if(month[i] > currMinMonth){
            currMinMonth = month[i];
            currMinDay = day[i];
            currMinI = i;
        }
        else if(month[i] == currMinMonth){
            if(day[i] > currMinDay){
                currMinDay = day[i];
                currMinI = i;
            }
        }
    }
}

int main(){
    int dead_y, dead_m, dead_d;
    int n;
    int* year;
    int* month;
    int* day;

    int currMinI = 101;
    int currMinYear = -1;
    int currMinMonth = 13;
    int currMinDay = 32;

    ifstream in("king.in");
    in>>dead_d>>dead_m>>dead_y;
    in>>n;
    year = new int[n];
    month = new int[n];
    day = new int[n];
    for(int i = 0; i < n; i++){
        in>>day[i]>>month[i]>>year[i];
    }
    in.close();

    for(int i = 0; i < n; i++){
        if(dead_y - year[i] > 18){
            work(i, dead_d, dead_m, dead_d, n, year, month, day, currMinI, currMinYear, currMinMonth, currMinDay);
        }
        else if(dead_y - year[i] == 18){
            if(dead_m > month[i]){
                work(i, dead_d, dead_m, dead_d, n, year, month, day, currMinI, currMinYear, currMinMonth, currMinDay);
            }
            else if(dead_m == month[i]){
                if(dead_d >= day[i]){
                    work(i, dead_d, dead_m, dead_d, n, year, month, day, currMinI, currMinYear, currMinMonth, currMinDay);
                }
            }
        }
    }

    delete [] year;
    delete [] month;
    delete [] day;

    ofstream out("king.out");
    if(currMinI == 101){
        out<<-1;
    }
    else{
        out<<(currMinI + 1);
        //out<<endl<<currMinDay<<" "<<currMinMonth<<" "<<currMinYear;
    }

    out.close();
}

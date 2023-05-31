#include <bits/stdc++.h>

using namespace std;

string s;


int main(){
    cin.tie();
    ios_base::sync_with_stdio(0);
    ifstream cin("boysgirls.in");
    ofstream cout("boysgirls.out");
    int n, a, b;
    cin >> n >> a >> b;
    if (!a){
        if (b == n){
            for (int i = 0; i < n; ++i){
                cout << "G";
            }
            return 0;
        }
        else{
            cout << "Impossible";
            return 0;
        }
    }
    if (!b){
        if (a == n){
            for (int i = 0; i < n; ++i){
                cout << "B";
            }
            return 0;
        }
        else{
            cout << "Impossible";
            return 0;
        }
    }
    if (a == 1 && b == 1){
        cout << "BG";
        return 0;
    }
    if (a == 1 || b == 1){
        cout << "Impossible";
        return 0;
    }
    if (a == b){
        int  t = a - 2;
        if (2 * t == n){
            for (int i = 0; i < t; ++i)
                cout << "B";
            for (int i = 0; i < t; ++i)
                cout << "G";
            return 0;
        }
        if (2 * t + 4 == n){
            for (int i = 0; i < t + 2; ++i){
                cout << "BG";
            }
            return 0;
        }
        cout << "Impossible";
        return 0;
    }
    int a_num = a - 2;
    int b_num = b - 2;
    if (a_num + b_num == n){
        for (int i = 0; i < a_num; ++i){
            cout << "B";
        }
        for (int i = 0; i < b_num; ++i){
            cout << "G";
        }
        return 0;
    }
    else if (b_num + a_num + 2 == n){
        if (a_num < b_num){
            for (int i = 0; i < a_num + 1; ++i){
                cout << "BG";
            }
            for (int i = 0; i < b_num - a_num; ++i){
                cout << "G";
            }
            return 0;
        }
        else{
            for (int i = 0; i < a_num - b_num; ++i){
                cout << "B";
            }
            for (int i = 0; i < b_num + 1; ++i){
                cout << "BG";
            }
            return 0;
        }
    }
    cout << "Impossible";
    return 0;

}

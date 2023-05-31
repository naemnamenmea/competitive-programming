#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("folding.in");
    ofstream cout("folding.out");
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b){
        double t = a;
        a = b;
        b = t;
    }
    if (c < d){
        double t = c;
        c = d;
        d = t;
    }
    if (a == c && b == d){
        cout << 0;
        return 0;
    }
    if (c > a || b < d){
        cout << -1;
        return 0;
    }
        int res = 0;
        while (a > c){
            a /= 2;
            res++;
        }
        while (b > d){
            b /= 2;
            res++;
        }
        cout << res;
        return 0;
/*
    if (a == c && b > d){
        cout << 1;
        return 0;
    }
    if (a > b && b > d){
        cout << 2;
        return 0;
    }
    cout << -1;
    return 0;*/
    return 0;
}

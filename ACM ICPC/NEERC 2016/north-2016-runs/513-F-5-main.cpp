#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("folding.in");
    ofstream cout("folding.out");
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long a2 = a, b2 = b;
    if (a < b){
        long long t = a;
        a = b;
        b = t;
    }
    if (c < d){
        long long t = c;
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
        a = a / 2 + a % 2;
        res++;
    }
    while (b > d){
        b = b / 2 + b % 2;
        res++;
    }
    int res2 = 0;
    while (a2 > d){
        a2 = a2 / 2 + a2 % 2;
        res2++;
    }
    while (b2 > c){
        b2 = b2 / 2 + b2 % 2;
        res2++;
    }
 //   cout << res << endl;
    cout << min(res, res2);
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
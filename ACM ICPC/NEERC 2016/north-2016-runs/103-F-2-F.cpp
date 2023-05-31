#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin v.end
#define pb push_back
#define F first
#define S second

const int MAXN = 1e5 + 7;

int main(){
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a < x || b < y){
        swap(x, y);
        if (a < x || b < y){
            cout << -1;
            return 0;
        }
    }
    int ans = 2;
    if (x == a){
        ans--;
    }
    while (x < (a / 2 + a % 2)){
        ans++;
        a = (a / 2 + a % 2);
    }
    if (y == b){
        ans--;
    }
    while (y < (b / 2 + b % 2)){
        ans++;
        b = (b / 2 + b % 2);
    }
    int ans1 = ans;
    swap(x, y);
    if (x <= a && b <= y){
        ans = 2;
        if (x == a){
            ans--;
        }
        while (x < (a / 2 + a % 2)){
            ans++;
            a = (a / 2 + a % 2);
        }
        if (y == b){
            ans--;
        }
        while (y < (b / 2 + b % 2)){
            ans++;
            b = (b / 2 + b % 2);
        }
    }
    cout << min(ans, ans1);
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("folding.in", "r", stdin); freopen("folding.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a < b) swap(a, b);
    if(c < d) swap(c, d);
    if(c > a || d > b) {
    	cout << -1;
    	return 0;
    }
    int ans = 0;
    while(c < a) {
    	ans++;
    	c *= 2;
    }
    while(d < b) {
    	ans++;
    	d *= 2;
    }
    
    cout << ans << '\n';	
    return 0;
}

#include <bits/stdc++.h>

using namespace std;


int cnt(int a, int b, int c, int d) {
	if(c > a || d > b) {
    	return 1e9;
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
    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("folding.in", "r", stdin); freopen("folding.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = min(cnt(a, b, c, d), cnt(a, b, d, c));
    ans = min(ans, cnt(b, a, c, d));
    ans = min(ans, cnt(b, a, d, c));
    if(ans == 1e9) {
    	ans = -1;
    }	
    
    
    cout << ans << '\n';	
    return 0;
}

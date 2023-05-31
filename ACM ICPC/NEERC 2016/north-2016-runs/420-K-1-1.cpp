#include <bits/stdc++.h>

using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get(int d, int m, int y) {
	int ret = 0;
	int now = (y - 1) * 365 + d;
	for (int i = 1; i < m; i++) now += days[i - 1];
	return now;
}

int main() {
    freopen("king.in","r",stdin);
    freopen("king.out","w",stdout);
    int d, m, y, n;
    scanf("%d%d%d", &d, &m, &y);
    scanf("%d", &n);                               
    int kek = get(d, m, y);
    int ans = -(int)2e9;
    int who = -1;
    int need = 18 * 365;
    for (int i = 1; i <= n; i++) {
    	int a, b, c;
    	scanf("%d%d%d", &a, &b, &c);
    	int lol = get(a, b, c);
    	if (kek - lol + 1 > need) {
    		if (lol > ans) {
    			ans = lol;
    			who = i;
    		}
    	} 	
    }
    printf("%d\n", who);
	return 0;
}
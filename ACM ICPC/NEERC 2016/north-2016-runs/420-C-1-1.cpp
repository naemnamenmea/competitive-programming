#include <bits/stdc++.h>

using namespace std;

const int N = 2000500;

int n;
int a[N], b[N], f[N];

int main() {
    freopen("codecoder.in","r",stdin);
    freopen("codecoder.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
    	scanf("%d%d", &a[i], &b[i]);
    	int pos = min(a[i], b[i]);
    	f[pos]++;        
    }
    for (int i = 1; i <= (int)1e6 + 100; i++) f[i] += f[i - 1];
    for (int i = 1; i <= n; i++) {
    	int ans = f[max(a[i], b[i]) - 1];
    	if (min(a[i], b[i]) < max(a[i], b[i])) --ans;
    	printf("%d\n", ans);
    }           
	return 0;
}
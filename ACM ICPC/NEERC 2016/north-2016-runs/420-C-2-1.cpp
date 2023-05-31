#include <bits/stdc++.h>

using namespace std;

const int N = 2000500;

int n;
int a[N], b[N], f[N], g[N];

int main() {
    freopen("codecoder.in","r",stdin);
    freopen("codecoder.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
    	scanf("%d%d", &a[i], &b[i]);
    	int pos = min(a[i], b[i]);
    	int lol = max(a[i], b[i]);
    	f[pos]++;        
    	g[pos] = max(g[pos], lol);
    }
    for (int i = 1; i <= (int)1e6 + 100; i++) f[i] += f[i - 1];
    for (int i = 1; i <= (int)1e6 + 100; i++) g[i] = max(g[i], g[i - 1]);
    for (int i = 1; i <= n; i++) {
    	int mda = max(a[i], b[i]);
    	mda = max(mda, g[mda - 1]);
    	int ans = f[mda - 1];
    	if (min(a[i], b[i]) < mda) --ans;
    	printf("%d\n", ans);
    }           
	return 0;
}
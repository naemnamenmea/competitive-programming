#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 200500;

int n;
int x[N], y[N];
int cnt[N];
int t[N];
int a[N], p[N], f[N], s[N];

int kek(int x, int y) {
	return min(x, y);
}

int main() {
    freopen("intergral.in","r",stdin);
    freopen("intergral.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    vector< pair<int, int> > vecs;
    for (int i = 2; i <= n; i++) {
    	int dx = abs(x[i] - x[i - 1]);
    	int dy = abs(y[i] - y[i - 1]);
    	dx %= 2;
    	dy %= 2;
    	vecs.pb(mp(dx, dy));
    }
    int dx = abs(x[1] - x[n]);
    int dy = abs(y[1] - y[n]);
    dx %= 2;
    dy %= 2;
    vecs.pb(mp(dx, dy));
    for (int i = 1; i <= n; i++) {
    	a[i] = kek(vecs[i - 1].F, vecs[i - 1].S);
    }
    p[0] = f[0] = s[0] = 0;
   // cnt[0]++;
    for (int i = 1; i <= n; i++) {
    	p[i] = (p[i - 1] ^ a[i]);
    	f[i] = (f[i - 1] ^ vecs[i - 1].F);
    	s[i] = (s[i - 1] ^ vecs[i - 1].S);
    	int val = p[i] + f[i] * 2 + s[i] * 4;
    	cnt[val]++;
    //	cout << p[i] << " " << f[i] << " " << s[i] << endl;
    }
    t[1] = cnt[1] * (cnt[2] + cnt[4] + cnt[7] + cnt[0]);
    t[2] = cnt[5] * (cnt[0] + cnt[4] + cnt[3]);
    t[3] = cnt[3] * (cnt[0] + cnt[2] + cnt[5]);
    t[4] = cnt[6] * (cnt[7] + cnt[5] + cnt[3] + cnt[0]);
    t[5] = cnt[2] * (cnt[3] + cnt[4] + cnt[1] + cnt[7]);
    t[6] = cnt[4] * (cnt[7] + cnt[5] + cnt[1] + cnt[2]);
    t[7] = cnt[0] * (cnt[1] + cnt[5] + cnt[3] + cnt[6]);
    int ans = t[1] + t[2] + t[3] + t[4] + t[5] + t[6] + t[7];
    ans /= 2;
    long long anss = n * (n - 1LL) / 2LL - 1LL * ans - 1LL * n;
    cout << anss << endl;
    return 0;
}
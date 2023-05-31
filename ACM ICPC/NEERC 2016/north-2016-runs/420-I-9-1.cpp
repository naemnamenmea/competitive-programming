#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define F first
#define S second
 
const int N = 300500;
 
int n;
int x[N], y[N];
long long cnt[N];
long long t[N];
int a[N], p[N], f[N], s[N];
 
int kek(int x, int y) {
    return min(x, y);
}

inline int abss(int x) {
	if (x < 0) return -x;
	return x;
}
 
int main() {
    freopen("integral.in","r",stdin);
    freopen("integral.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    vector< pair<int, int> > vecs;
    long long area = 0LL;
    for (int i = 2; i <= n; i++) {
        int dx = abss(x[i] - x[i - 1]);
        int dy = abss(y[i] - y[i - 1]);
        area += (1LL * ((long long)x[i - 1] - (long long)x[i]) * ((long long)y[i] + (long long)y[i - 1]));
        dx %= 2;
        dy %= 2;
        vecs.pb(mp(dx, dy));
    }                 
   	int dx = abs(x[1] - x[n]);
    int dy = abs(y[1] - y[n]);
    area += (1LL * ((long long)x[1] - (long long)x[n]) * ((long long)y[1] + (long long)y[n]));
    area = abs(area);
    if (area % 2LL == 1LL) {
   		cout << 0 << endl;
   		return 0;
   	}
    dx %= 2;
    dy %= 2;
    vecs.pb(mp(dx, dy));
    for (int i = 1; i <= n; i++) {
        a[i] = (vecs[i - 1].F & vecs[i - 1].S);
    }
    p[0] = f[0] = s[0] = 0;
    //cnt[0]++;
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i - 1] ^ a[i]);
        f[i] = (f[i - 1] ^ vecs[i - 1].F);
        s[i] = (s[i - 1] ^ vecs[i - 1].S);
        int val = p[i] + f[i] * 2 + s[i] * 4;
        cnt[val]++;
    //  cout << p[i] << " " << f[i] << " " << s[i] << endl;
    }
    long long anss = 0LL;                                                      
    for (int i = 0; i < 8; i++) {
         
        for (int j = 0; j < 8; j++) {
            int val = (i ^ j);
            if (val == 1 || val == 5 || val == 3) anss += (1LL * cnt[i] * cnt[j]);
        }
    }
    //long long ans = t[1] + t[2] + t[3] + t[4] + t[5] + t[6] + t[7] + t[8];
    anss /= 2LL;
    long long ansss = n * (n - 1LL) / 2LL - 1LL * anss - 1LL * n;
    cout << ansss << endl;
    return 0;
}
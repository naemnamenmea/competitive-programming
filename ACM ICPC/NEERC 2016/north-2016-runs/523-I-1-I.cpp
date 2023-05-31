#define FNAME "integral"

#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);++i)
#define forit(i,V) for(__typeof(V.begin()) i=V.begin();i!=V.end();++i)
#define fornr(i,N) for(int i=int(N)-1;i>=0;--i)
#define forab(i,a,b) for(int i=(a);i<int(b);++i)
#define all(V) (V).begin(),(V).end()
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define sz(V) (int)((V).size())

typedef long long ll;
typedef pair<int,int> pii;
typedef long double LD;
typedef vector<int> vi;

const int N = 4e5 + 100;

ll s[N];
int x[N], y[N], cnt[N][2][2][2];

int main(){
	assert(freopen(FNAME".in","r",stdin));
	assert(freopen(FNAME".out","w",stdout));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> x[i] >> y[i];
		x[i + n] = x[i], y[i + n] = y[i];
	}
	x[2 * n] = x[0], y[2 * n] = y[0];
	forab(i, 1, n + 1) {
		s[i] = s[i - 1] + (x[i] - x[i - 1]) * 1ll * (y[i] + y[i - 1]);		
	}
	forab(i, n + 1, 2 * n + 1) {
		s[i] = s[i - n] + s[n];
	}
	forab(i, 1, 2 * n + 1) {
		int xx = x[(i - 1) % n], yy = y[(i - 1) % n];
		forn(q, 2)
			forn(w, 2)
				forn(e, 2)
					cnt[i][q][w][e] = cnt[i - 1][q][w][e];
		cnt[i][s[i - 1] % 2][abs(xx) % 2][abs(yy) % 2]++;
	}
	ll ans = 0;
	forn(i, n) {
		forn(q, 2)
			forn(w, 2)
				forn(e, 2) {
					int mod = q - (s[i] % 2) + ((abs(y[i]) % 2) + e) * (w - (abs(x[i]) % 2));
					mod %= 2;
					if (mod == 0) {
						ans += cnt[i + n - 1][q][w][e] - cnt[i + 2][q][w][e];
		//				cout << i << " " << q << " " << w << " " << e << " " << ans << '\n';
					}
				}
	}
	cout << ans / 2 << '\n';
	return 0;
}
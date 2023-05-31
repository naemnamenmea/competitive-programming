#define FNAME "hard"

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
#define fs first
#define sc second
#define sz(V) (int)((V).size())

typedef long long LL;
typedef pair<int,int> pii;
typedef long double LD;
typedef vector<int> vi;

const int MAX_N = 65;

int dp[MAX_N][MAX_N];
pii pr[MAX_N][MAX_N];

int main(){
	assert(freopen(FNAME".in","r",stdin));
	assert(freopen(FNAME".out","w",stdout));
	
	forn (i, 61)
		forn (j, 61)
			dp[i][j] = 1e9;
	dp[0][0] = 0;
	forab (h, 1, 61)
		dp[h][0] = dp[0][h] = 0;
	forab (h, 1, 61)
		forab (w, 1, 61) {
			forab (j, 1, 61) {
				if (h % j == 0 && w >= j) {
					if (dp[h][w] > dp[h][w - j] + h / j)
						dp[h][w] = dp[h][w - j] + h / j, pr[h][w] = mp(1, j);
				}
				if (w % j == 0 && h >= j) {
					if (dp[h][w] > dp[h - j][w] + w / j)
						dp[h][w] = dp[h - j][w] + w / j, pr[h][w] = mp(0, j);
				}
			}
		}
	int t, w, h;
	scanf("%d", &t);
	forn (tt, t) {
		scanf("%d%d", &w, &h);
		printf("%d\n", dp[w][h]);
		
		while (w > 0 && h > 0) {
			auto np = pr[w][h];
			int j = np.sc;
			if (np.fs == 0) {
				forn (i, h / j) {
					printf("%d %d %d\n", w - np.sc, i * j, j);
				}
				w -= np.sc;
		 	} else {
				forn (i, w / j) {
					printf("%d %d %d\n", i * j, h - np.sc, j);
				}		 	
		 		h -= np.sc;
		 	}
		}
	}
	
	return 0;
}
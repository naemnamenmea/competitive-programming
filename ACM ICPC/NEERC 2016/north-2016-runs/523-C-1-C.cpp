#define FNAME "codecoder"

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

const int MAX_N = 2e5 + 5;

pii a[2][MAX_N];
int pl[2][MAX_N], neigh[2][MAX_N], pr[2][MAX_N], minn[2], ans[MAX_N];

int main(){
	assert(freopen(FNAME".in","r",stdin));
	assert(freopen(FNAME".out","w",stdout));
	
	int n;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d%d", &a[0][i].fs, &a[1][i].fs), a[0][i].sc = i, a[1][i].sc = i;	
	sort(a[0], a[0] + n);
	sort(a[1], a[1] + n);
	forn (j, 2) 
		forn (i, n)
			pl[j][a[j][i].sc] = i;	
	forn (j, 2)
		forn (i, n)
			neigh[j][i] = pl[j ^ 1][a[j][i].sc];
	int last = n - 1;
	forn (j, 2) {
		pr[j][n] = n;
		fornr (i, n)
			pr[j][i] = min(pr[j][i + 1], neigh[j][i]);
	}
	int cnt = n - 1;
	while (last != -1) {
		minn[0] = last;
		minn[1] = last + 1;
		int cur = 0;
		int oldLast = last;
		while (minn[0] != minn[1]) {
			minn[cur ^ 1] = pr[cur][minn[cur]];
			cur ^= 1;
		}
		last = minn[0] - 1;
		//printf("%d %d %d %d %d\n", minn[0], last + 1, oldLast, cnt, a[0][last + 1].sc);
		//printf("l=%d r=%d\n", last + 1, oldLast + 1);
		forab (i, last + 1, oldLast + 1) {
			//printf("%d %d\n", a[0][i].sc, cnt);
			ans[a[0][i].sc] = cnt;
		}
		cnt -= (oldLast - last);
	}
	forn (i, n)
		printf("%d\n", ans[i]);
	return 0;
}
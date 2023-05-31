#define FNAME "boysgirls"

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

typedef long long LL;
typedef pair<int,int> pii;
typedef long double LD;
typedef vector<int> vi;

int a, b, c;

void imp() {
	puts("Impossible");
	exit(0);
}

void printAns(int cntB1, int cntG1, int cntB2, int cntG2, int b2, int g2) {
	assert(cntB1 + cntB2 == cntG1 + cntG2);
	assert(b2 >= 2 * cntB2);
	assert(g2 >= 2 * cntG2);
	assert(cntB1 >= 0);
	assert(cntG1 >= 0);
	assert(cntB2 >= 0);
	assert(cntG2 >= 0);
	assert(cntG1 + b2 - 2 * cntB2 == b);
	assert(cntB1 + g2 - 2 * cntG2 == c);
	assert((cntB2 + cntG2) * 2 == a);
	int itNum = cntB1 + cntB2;
	//printf("%d %d %d %d %d\n", cntB1, cntB2, cntG1, cntG2, b2);
	forn (i, itNum) {
		if (cntB1 > 0) {
			printf("B");
			cntB1--;
		} else {
			if (cntB2 > 1)
				printf("BB"), cntB2--, b2 -= 2;
			else {
				forn (j, b2)
					printf("B");
				b2 = 0;
				cntB2 = 0;
			}
		}

		if (cntG1 > 0) {
			printf("G");
			cntG1--;
		} else {
			if (cntG2 > 1)
				printf("GG"), cntG2--, g2 -= 2;
			else {
				forn (j, g2)
					printf("G");
				g2 = 0;
				cntG2 = 0;
			}
		}

	}
	exit(0);
}

int main(){
	assert(freopen(FNAME".in","r",stdin));
	assert(freopen(FNAME".out","w",stdout));
	
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);	
	if (x == 0) {
		if (y == n) {
			forn(i, n)
				printf("G");
			puts("");
		} else
			imp();
		return 0;
	}
	if (y == 0) {
		if (x == n) {
			forn(i, n)
				printf("B");
			puts("");
		} else
			imp();
		return 0;
	}
	c = n - x, b = n - y, a = x + y - n;
	if (a % 2 != 0 || a < 0)
		imp();
	forn (i, a / 2 + 1) {
		int cntB2 = i, cntG2 = a / 2 - i;
		int k = cntB2 - cntG2;
		int l = max(0, k), r = min(b, c + k);
		int z = -1;
		if (cntB2 == 0) {
			if (cntG2 == 0) {
				if (b == c + k)
					z = b;
			} else
				z = b;					
		}
		else {
			if (cntG2 == 0)
				z = c + k;
			else
				z = l;
		}
		if (z >= l && z <= r && z >= 0) {
			printAns(z - k, z, cntB2, cntG2, b + 2 * cntB2 - z, c + 2 * cntG2 + k - z); 
		}
	}
	imp();
	return 0;
}
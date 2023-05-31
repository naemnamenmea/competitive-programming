#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back

int a[111][16][2];
int b[111][16][2];
int c[111][16][2];
bool vis[111][16][2];
pair<int, int> lst[111][16][2];

int mas[9][111];

vector<pair<int, int> > dig[10];
int l[9][2];

int check(int curmask, int A, int B, int C, vector<int> wtf) {
	memset(l, 0, sizeof(l));
	vector<int> omg;
	omg.pb(A);
	omg.pb(B);
	omg.pb(C);
	if (curmask == 15 && A ==7 && B == 4 && C == 1) {
		A = 7;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < sz(dig[omg[i]]); j++) {
			int li = dig[omg[i]][j].first;
			int po = dig[omg[i]][j].second;
			l[li+2*i][po] = 1;
		}
	}
	vector<int> wtf2;
	int step = 0;
	int nxtmask = 0;
	int idx = 0;
	for (int j = 0; j < 9; j++) {
		if (j % 2) {
			wtf2.pb(l[j][0] | !!(curmask & (1 << step)));
			if (wtf[idx] != wtf2[idx]) {
				return -1;
			}
			idx++;
			wtf2.pb(l[j][1]);
			idx++;
			if (l[j][1]) nxtmask |= (1 << step);
			step++;
		}
		else {
			wtf2.pb(l[j][0]);
			if (wtf[idx] != wtf2[idx]) {
				return -1;
			}
			idx++;
		}
	}

	return nxtmask;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	freopen("digital.in", "rt", stdin);
freopen("digital.out", "wt", stdout);
	dig[0] = { mp(0, 0), mp(1, 0), mp(1, 1), mp(3, 0), mp(3, 1), mp(4, 0) };
	dig[1] = { mp(1, 1), mp(3, 1) };
	dig[2] = { mp(0, 0), mp(1, 1), mp(2, 0), mp(3, 0), mp(4, 0) };
	dig[3] = { mp(0, 0), mp(1, 1), mp(2, 0), mp(3, 1), mp(4, 0) };
	dig[4] = { mp(1, 0), mp(1, 1), mp(2, 0), mp(3, 1) };
	dig[5] = { mp(0, 0), mp(1, 0), mp(2, 0), mp(3, 1), mp(4, 0) };
	dig[6] = { mp(0, 0), mp(1, 0), mp(2, 0), mp(3, 0), mp(3, 1), mp(4, 0) };
	dig[7] = { mp(0, 0), mp(1, 1), mp(3, 1) };
	dig[8] = { mp(0, 0), mp(1, 0), mp(1, 1), mp(2, 0), mp(3, 0), mp(3, 1), mp(4, 0) };
	dig[9] = { mp(0, 0), mp(1, 0), mp(1, 1), mp(2, 0), mp(3, 1), mp(4, 0) };
	vis[0][0][0] = true;
	int w;
	scanf("%d", &w);
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < w + (j % 2); i++) {
			scanf("%d", &mas[j][i]);
		}
	}

	for (int i = 0; i < w; i++) {
		bool ok = false;
		for (int curmask = 0; curmask < 16; curmask++) {
			for (int ost = 0; ost < 2; ost++) {
				if (!vis[i][curmask][ost]) continue;
				for (int A = 0; A < 10; A++) {
					for (int B = 0; B < 10; B++) {
						for (int C = 0; C < 10; C++) {
							vector<int> wtf;
							for (int j = 0; j < 9; j++) {
								if (j % 2) {
									wtf.pb(mas[j][i]);
									wtf.pb(mas[j][i + 1]);
								}
								else {
									wtf.pb(mas[j][i]);
								}
							}

							int diff = C - A - B;
							int nxtost = 0;
							if (ost == 1) diff += 10;
							if (diff < 0) continue;
							if (diff == 1) nxtost = 1;
							else if (diff == 0) nxtost = 0;
							else continue;

							int nxtmask = check(curmask, A, B, C, wtf);

							if (nxtmask != -1 && !vis[i + 1][nxtmask][nxtost]) {
								a[i + 1][nxtmask][nxtost] = A;
								b[i + 1][nxtmask][nxtost] = B;
								c[i + 1][nxtmask][nxtost] = C;
								lst[i + 1][nxtmask][nxtost] = mp(curmask, ost);
								vis[i + 1][nxtmask][nxtost] = true;
							}
						}
					}
				}
			}
		}
	}
	int need = 0;
	if (mas[1][w]) need |= 1;
	if (mas[3][w]) need |= 2;
	if (mas[5][w]) need |= 4;
	if (mas[7][w]) need |= 8;

	if (!vis[w][need][0]) {
		cout << "NO" << endl;
		return 0;
	}
	int curmask = need;
	int curost = 0;
	vector<int> resa;
	vector<int> resb;
	vector<int> resc;
	for (int i = w; i >= 1; i--) {
		resa.pb(a[i][curmask][curost]);
		resb.pb(b[i][curmask][curost]);
		resc.pb(c[i][curmask][curost]);
		int tmp = lst[i][curmask][curost].second;
		curmask = lst[i][curmask][curost].first;
		curost = tmp;
	}
	for (int i = sz(resa) - 1; i >= 0; i--) printf("%d", resa[i]);
	printf("\n");
	for (int i = sz(resb) - 1; i >= 0; i--) printf("%d", resb[i]);
	printf("\n");
	for (int i = sz(resc) - 1; i >= 0; i--) printf("%d", resc[i]);
	printf("\n");

	return 0;
}
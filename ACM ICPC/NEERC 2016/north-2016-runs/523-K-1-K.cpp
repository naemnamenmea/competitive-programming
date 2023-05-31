#define FNAME "king"

#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);++i)
#define fornr(i,n) for(int i=(int(n))-1;i>=0;--i)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long LL;
typedef pair<int,int> pii;

const int N = 105;

pair <pii, pii> a[N], date;

int main(){
	assert(freopen(FNAME".in","r",stdin));
	assert(freopen(FNAME".out","w",stdout));
	cin >> date.snd.fst >> date.fst.snd >> date.fst.fst;
	date.snd.snd = 1e9;
	date.fst.fst -= 18;
	int n; cin >> n;
	forn(i, n) {
		cin >> a[i].snd.fst >> a[i].fst.snd >> a[i].fst.fst;
		a[i].snd.snd = i + 1;
	}
	sort(a, a + n);
	int ok = -1;
	fornr(i, n) {
		if (a[i] <= date) {
			ok = a[i].snd.snd;
			break;
		}
	}
	cout << ok << '\n';
	
	return 0;
}
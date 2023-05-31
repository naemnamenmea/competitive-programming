#include <bits/stdc++.h>



using ll = long long;
using ld = long double;

#define mp make_pair
#define pb push_back

#define filename "codecoder"

using namespace std;

struct person {
	int x, y, id;
	person(){}
	person(int x, int y, int id) : x(x), y(y), id(id) {		
	}
};

bool cmpx(const person& a, const person & b) {
	return a.x < b.x;
}

bool cmpy(const person& a, const person &b) {
	return a.y < b.y;	
}

using persons = vector < person >;

persons a;

const int maxn = 1e5 + 100;
int ans[maxn];

int bs(const persons& a, int val) {
	int l = 0;
	int r = a.size() - 1;
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (a[mid].x <= val) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if (a[r].x <= val)
		return r;
	return l;
}

void print(int x) {
	cerr << x << endl;
	string s;
	cin >> s;
}

void solve(const persons& a, const persons& b) {
	int n = a.size();
	vector < int > ma1(n + 1, 0);
	vector < int > ma2(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		ma1[i] = max(ma1[i - 1], a[i - 1].y);
		ma2[i] = max(ma2[i - 1], b[i - 1].y);
	}
	for (int i = 1; i <= n; ++i) {
		ma1[i - 1] = ma1[i];
		ma2[i - 1] = ma2[i];
	}
//	for (int i = 0; i < n; ++i) {
//		cerr << a[i].x << " " << a[i].y << " " << a[i].id << endl;
//	}
//	for (int i = 0; i < n; ++i) {
//		cerr << b[i].x << " " << b[i].y << " " << b[i].id << endl;
//	}
	set < int > ids;
	ids.clear();
	int pos = 0;
	int pr1 = 0;
	int pr2 = 0;
	while (pos < n) {
//		cerr << pos << endl;
		int stpos = pos;
		pr1 = stpos;
		int finpos = pos;
		int where = 0;
		while (true) {
//			print(finpos);
			int cp = finpos;
			int val = ma1[cp];
			finpos = bs(b, val);
			val = ma2[finpos];
			finpos = bs(a, val);
			if (finpos == cp) {
				break;
			}			
		}		
		for (int i = stpos; i <= finpos; ++i) {
			ids.insert(a[i].id);
		}
		int sp = bs(b, ma1[finpos]);
		for (int i = pr2; i <= sp; ++i) {
			ids.insert(b[i].id);
		}
		int m = ids.size() - 1;
//		cerr << "new value " << m << endl;
		for (int i = stpos; i <= finpos; ++i) {
//			cerr << a[i].id << " ";			
			ans[a[i].id] = max(ans[a[i].id], m);
		}
//		cerr << endl;
		pr2 = sp + 1;
		pr1 = finpos;
//		cerr << stpos << " " << pr1 << endl;
		pos = finpos + 1;
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	int n = 0;
	cin >> n;
	vector < person > xx;
	vector < person > yy;
	for (int i = 0; i < n; ++i) {		
		int x, y;
		cin >> x >> y;
		a.push_back(person(x, y, i + 1));
		xx.push_back(person(x, y, i + 1));
		yy.push_back(person(y, x, i + 1));
	}
	sort(xx.begin(), xx.end(), cmpx);
	sort(yy.begin(), yy.end(), cmpx);
	solve(xx, yy);
	solve(yy, xx);
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
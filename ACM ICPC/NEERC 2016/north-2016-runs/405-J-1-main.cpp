#include <bits/stdc++.h>

using namespace std;
                   
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const double p = 0.982; 

int d[505], was[505], op[505];

pair <int, int> pr[505];

void update(int id, int nval, int a, int b, int cop) {
	if (d[id] == -1 || d[id] > nval) {
		d[id] = nval;
		pr[id] = make_pair(a, b);
		op[id] = cop;
	}
}

void precalc() {
	memset(d, -1, sizeof(d));
	d[255] = 1;
	int mx = 1;
	for (int i = 0;i < 256;i++) {
		int cur = -1;
		for (int j = 0;j < 256;j++) {
			if (!was[j] && d[j] != -1) {
				cur = j;
				break;
			}
		}
		was[cur] = 1;
		mx = max(mx, d[cur]);
		if (d[cur] == 14) {
			cerr << cur << "\n";
		}

		for (int j = 0;j < 256;j++) {
			if (d[j] == -1) continue;
			update((j + cur) % 256, d[cur] + d[j], cur, j, 0);
			update((cur - j + 256) % 256, d[cur] + d[j], cur, j, 1);
			update((cur * j) % 256, d[cur] + d[j], cur, j, 2);
			if (j > 0) {
				update((cur / j) % 256, d[cur] + d[j], cur, j, 3);
			} 
		}
	}
	cerr << mx << endl;
}

string get(int cur) {
	if (cur == 255) {
		return "k";
	}
	string a[4] = {"+", "-", "*", "/"};

	string res = "(" + get(pr[cur].first) + " " + a[op[cur]] + " " + get(pr[cur].second) + ")";
	return res;
}

void solve() {
	int c;
	cin >> c;

	precalc();
	cout << "a = ? max ?\n";
	for (char i = 'b';i <= 'k';i++) {
		cout << (char)i << " = " << char(i - 1) << " max " << char(i - 1) << "\n";
	}

	string s = get(c);
	cout << s << endl;
}

int main () {                   
	freopen ("java2016.in", "r", stdin);
	freopen ("java2016.out", "w", stdout);
	solve();

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 2e5;

struct prob {
	ld res[256];
	ld fail;
	prob() {
		fill(res, res + 256, ld(1) / 256);
		fail = 0;
	}
	double get(int x) const {
		return res[x % 256];
	}
};

prob max(const prob &a, const prob &b) {
	prob res;
	fill(res.res, res.res + 256, 0);
	res.fail = (ld(1) - a.fail) * (ld(1) - b.fail);
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			res.res[max(i, j)] += a.get(i) * b.get(j);
		}
	}
	return res;
}

prob div(const prob &a, const prob &b) {
	prob res;
	fill(res.res, res.res + 256, 0);
	res.fail = (ld(1) - a.fail) * (ld(1) - b.fail);
	for (int i = 0; i < 256; i++) {
		for (int j = 1; j < 256; j++) {
			res.res[i / j] += a.get(i) * b.get(j);
		}
	}
	res.fail += b.get(0);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("java2016.in", "r", stdin);
	freopen("java2016.out", "w", stdout);
#endif
//	prob aa = max(prob(), max(prob(), prob()));
	cout << "a = ? max ? max ?\n";
	for(int i = 0; i < 16; i++){
		char rs = 'a' + i;
		cout << char(rs + 1) << " = " << rs << " max " << rs << " max " << rs << "\n";
	}
	cout << "z = q / q\n";
	cout << "y = z + z\n";
	cout << "x = z + z\n";
	int c;
	cin >> c;
	if(c == 0){
		cout << "? /?/ ?";
		return 0;
	}
//	const int TMP = 2;
	for(int i = 1; i < 7; i++){
		char rs = 'x' - i;
		cout << rs << " = " << char(rs + 1) << " * y\n";
	}
	bool pr = false;
	char numx[] = {'z', 'y', 'w', 'v', 'u', 't', 's', 'r'};
	for(int i = 0; i < 8; i++){
		if(c & 1){
			if(pr){
				cout << " + ";
			}
			pr = true;
			cout << numx[i];
		}
		c >>= 1;
	}
	return 0;
	cout << "z + y + x + w + v + u + t + s\n";
	int count = 0;
	string s;
	for(;;){
		getline(cin, s);
		for(auto x : s){
			if(!isspace(x)){
				count++;
			}
		}
		if(cin.eof()){
			cout << count;
			return 0;
		}
	}
//	prob z = prob();
//	for(int i = 0; i < 15; i++){
//		prob zz = max(z, max(z, z));
//		z = zz;
//	}
//	cout << z.get(255);
	return 0;
}

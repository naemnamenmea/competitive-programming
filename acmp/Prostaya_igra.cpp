#include <bits/stdc++.h>

//#define Prostaya_igra
#ifdef Prostaya_igra

#ifdef LOCAL_KONTROL
#define IN "acmp/INPUT.TXT"
#define OUT "acmp/OUTPUT.TXT"
#else
#define IN "INPUT.TXT"
#define OUT "OUTPUT.TXT"
#endif

using namespace std;

unsigned int remainder(string number, int divisor) {
	unsigned int res = 0;
	for (auto c : number) {
		res = (res * 10 + c - '0') % divisor;
	}
	return res;
}

int main() {
	ifstream ifs(IN);
	ofstream ofs(OUT);
	cin.rdbuf(ifs.rdbuf());
	cout.rdbuf(ofs.rdbuf());

	string s;
	getline(cin, s);
	
	unsigned int rem = remainder(s, 3);
	if (rem == 0) {
		cout << 2 << endl;
	}
	else {
		cout << 1 << endl;
		cout << rem << endl;
	}
}

#endif // Prostaya_igra
#include <bits/stdc++.h>

//#define Abba_Tribe_Gold
#ifdef Abba_Tribe_Gold

#ifdef LOCAL_KONTROL
#define IN "acmp/INPUT.TXT"
#define OUT "acmp/OUTPUT.TXT"
#else
#define IN "INPUT.TXT"
#define OUT "OUTPUT.TXT"
#endif

using namespace std;

string compare(const string& a, const string& b) {
	if (a.size() != b.size()) {
		return a.size() > b.size() ? a : b;
	}

	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > b[i]) {
			return a;
		}
		if (a[i] < b[i]) {
			return b;
		}
	}
	return a;
}

int main() {
	//ifstream ifs(IN);
	//ofstream ofs(OUT);
	//cin.rdbuf(ifs.rdbuf());
	//cout.rdbuf(ofs.rdbuf());

	string a, b, c;

	cin >> a >> b >> c;

	cout << compare(a, compare(b, c)) << endl;

}

#endif // Abba_Tribe_Gold
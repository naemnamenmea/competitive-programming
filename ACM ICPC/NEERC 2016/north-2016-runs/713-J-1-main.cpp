#include <bits/stdc++.h>



using ll = long long;
using ld = long double;

#define mp make_pair
#define pb push_back

#define filename "java2016"

using namespace std;

const int MAXN = 256;

ld prob[256][10];
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	int c = 0;
	cin >> c;
	if (c == 0) {
		cout << "?/?/?";
		return 0;
	}
	map <string, string> macros;
	macros["a"] = "a=?max?";
	cout << macros["a"] << endl;
	macros["b"] = "b = a max a";
	cout << macros["b"] << endl;
	macros["c"] = "c = b max b";
	cout << macros["c"] << endl;
	macros["d"] = "d = c max c";
	cout << macros["d"] << endl;
	macros["e"] = "e = d max d";
	cout << macros["e"] << endl;
	macros["f"] = "f = e max e";
	cout << macros["f"] << endl;
	macros["g"] = "g = f max f";
	cout << macros["g"] << endl;
	macros["h"] = "h = g max g";
	cout << macros["h"] << endl;
	macros["i"] = "i = h max h";
	cout << macros["i"] << endl;
	macros["j"] = "j = i max i";
		cout << macros["j"] << endl;
	macros["k"] = "k = j max j";
		cout << macros["k"] << endl;
	macros["l"] = "l = k max k";
		cout << macros["l"] << endl;
	macros["n"] = "n = l max l";
		cout << macros["n"] << endl;
	macros["m"] = "m = n max n";
		cout << macros["m"] << endl;
	macros["o"] = "o = m max m";
		cout << macros["o"] << endl;
	macros["p"] = "p = o max o";
		cout << macros["p"] << endl;
   	macros["z"] = "z = p / p";
		cout << macros["z"] << endl;
	map < int, string > dig;
	dig[1] = "z";

	dig[2] = "q";
	macros["q"] = "q = z + z";
		cout << macros["q"] << endl;

	dig[4] = "r";
	macros["r"] = "r = q + q";
		cout << macros["r"] << endl;

	dig[8] = "t";
	macros["t"] = "t = r + r";
		cout << macros["t"] << endl;

	dig[16] = "s";
	macros["s"] = "s = t + t";
		cout << macros["s"] << endl;

	dig[32] = "w";
	macros["w"] = "w = s + s";
		cout << macros["w"] << endl;

	dig[64] = "u";
	macros["u"] = "u = w + w";
		cout << macros["u"] << endl;

	dig[128] = "y";
	macros["y"] = "y = u + u";
		cout << macros["y"] << endl;



	bool ok = false;

	for (int l = 7; l >= 0; l--) {
		int ma = (1 << l);
		if (c >= ma) {
			if (ok) cout << "+";
			cout << dig[ma];
			c -= ma;
			ok = true;
		}
	}
	
	return 0;
}
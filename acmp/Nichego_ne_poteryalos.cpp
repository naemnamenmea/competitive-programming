#include <bits/stdc++.h>
#include <regex>

//#define Nichego_ne_poteryalos
#ifdef Nichego_ne_poteryalos

#ifdef LOCAL_KONTROL
#define IN "acmp/INPUT.TXT"
#define OUT "acmp/OUTPUT.TXT"
#else
#define IN "INPUT.TXT"
#define OUT "OUTPUT.TXT"
#endif

using namespace std;

int main() {
	ifstream ifs(IN);
	ofstream ofs(OUT);
	cin.rdbuf(ifs.rdbuf());
	//cout.rdbuf(ofs.rdbuf());

	int q;
	multimap<string,string> sites;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string s;
		smatch match;
		regex re("^(.*)\s");
		getline(cin, s);
		regex_search(s, match, re);
		cout << match[1] << endl;
		if (match.str(1) == "Add") {
			//cout << "Add" << endl;
		}
		else if (s.find("Remove") == 0) {

		}
		else if (s.find("Search") == 0) {

		}
	}
}

#endif // Nichego_ne_poteryalos
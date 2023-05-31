#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
#ifdef LOCAL_KONTROL
	ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

	int n;
	cin >> n;
	map<pair<string, string>, size_t> m;
	set<string> unique;
	while (n--) {
		string s;
		cin >> s;
		for (size_t i = 0; i < s.size() - 3; ++i) {
			string s1 = s.substr(i, 3);
			string s2 = s.substr(i + 1, 3);
			unique.insert(s1);
			unique.insert(s2);
			++m[{s1, s2}];
		}
	}

	cout << unique.size() << endl;
	cout << m.size() << endl;

	for (auto& e : m) {
		cout << e.first.first << ' ' << e.first.second << ' ' << e.second << endl;
	}

	return 0;
}
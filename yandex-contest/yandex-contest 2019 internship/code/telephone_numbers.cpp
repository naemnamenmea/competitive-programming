#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void formatNumber(string& str) {
	char chars[] = "()\s -+";

	for (unsigned int i = 0; i < strlen(chars); ++i)
	{
		str.erase(std::remove(str.begin(), str.end(), chars[i]), str.end());
	}
}

void getNumTemplate(string& str) {
	size_t offset = str.find_first_of('-', 0);
	str = str.substr(0, offset);
	formatNumber(str);
}

bool match(const string& str, const string& ct) {
	if (str.size() != ct.size()) {
		return false;
	}
	for (size_t i = 0; i < ct.size(); ++i) {
		if (ct[i] == 'X') continue;
		if (ct[i] != str[i]) {
			return false;
		}
	}
	return true;
}
string formNumberRes(const string& str, const string& t) {
	string res = t;
	size_t j = 0;
	for (size_t i = 0; i < res.size(); ++i) {
		if (res[i] == '-' || j == str.size())
			break;

		if (res[i] == 'X') {
			res[i] = str[j++];
		}
		else if (res[i] >= '0' && res[i] <= '9') {
			j++;
		}
	}
	return res;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
#ifdef LOCAL_KONTROL
	ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

	int n, m;
	cin >> n;
	vector<string> tel_numbers(n);
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		getline(cin, tel_numbers[i]);
		formatNumber(tel_numbers[i]);
	}

	cin >> m;
	vector<pair<string, string>> templates(m);
	cin.ignore();
	for (int i = 0; i < m; ++i) {
		string s, tmp;
		getline(cin, s);
		tmp = s;
		getNumTemplate(tmp);
		templates[i] = { s,tmp };
	}

	for (const auto& e : tel_numbers) {
		for (const auto& t : templates) {
			if (match(e, t.second)) {
				cout << formNumberRes(e, t.first) << endl;
			}
		}
	}

	return 0;
}
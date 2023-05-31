#include <bits/stdc++.h>

using namespace std;

map<char, bool> used;
multimap<char, char> voc;

bool transform(char from, char to) {

	queue<char> open;

	for (auto it = used.begin(); it != used.end(); ++it) {
		it->second = false;
	}

	used[from] = true;
	open.push(from);

	while (!open.empty()) {
		char next = open.front();
		open.pop();

		if (next == to) {
			return true;
		}

		auto to_set = voc.equal_range(next);
		for (auto it = to_set.first; it != to_set.second; ++it) {
			if (!used[it->second]) {
				used[it->second] = true;
				open.push(it->second);
			}
		}
	}
	return false;
}

int main() {

	int n, m;
	cin >> n >> m;	

	for (int i = 0; i < n; ++i) {
		char c_from, c_to;
		cin >> c_from >> c_to;
		used.insert(make_pair(c_from, false));
		used.insert(make_pair(c_to, false));
		voc.insert(make_pair(c_from,c_to));
	}

	for (int i = 0; i < m; ++i) {
		string w_from, w_to;
		cin >> w_from >> w_to;

		bool flag = true;		

		if (w_from.size() == w_to.size()) {
			for (int j = 0; j < w_from.size(); ++j) {
				if (!transform(w_from[j], w_to[j])) {
					flag = false;
					break;
				}
			}
		}
		else flag = false;

		cout << (flag ? "yes" : "no") << endl;
	}

	return 0;
}
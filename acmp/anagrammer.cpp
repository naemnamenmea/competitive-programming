//#define __anagrammer
#ifdef __anagrammer

#pragma warning(disable: 4996)

#include <bits/stdc++.h>

using namespace std;

int anagrammer(string orig, string samp, string stack) {
	int count = 0;
	string newstack;
	if (samp == "") {
		return 1;
	}
	if (stack.length() != 0 && stack[stack.length() - 1] == samp[0]) {
		string tmp = samp.length() > 1 ? samp.substr(1) : "";
		newstack = stack.substr(0, stack.length() - 1);
		count = count + anagrammer(orig, tmp, newstack);
	}

	if (orig.length() > 0) {
		string tmp = orig.length() > 1 ? orig.substr(1) : "";
		newstack = stack + orig[0];
		count = count + anagrammer(tmp, samp, newstack);
	}

	return count;
}

int main() {
	freopen("input.txt", "r", stdin);
	
	string s1, s2;	
	cin >> s1 >> s2;
	cerr << s1 << endl << s2 << endl;
	cout << anagrammer(s1, s2, "") << endl;

	return 0;
}

#endif // __anagrammer
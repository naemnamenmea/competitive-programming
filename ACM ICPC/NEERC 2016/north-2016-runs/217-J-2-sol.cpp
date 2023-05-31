#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

const int C = 80;

int main() {
	freopen("java2016.in", "r", stdin);
	freopen("java2016.out", "w", stdout);
	int c;
	cin >> c;
	if (c == 0) {
		cout << "? / ? / ?" << endl;
		return 0;
    }
    printf("e = (");
    for (int i = 0; i < C; i++) {
    	printf("?");
    	if (i < C - 1)
    		printf(" + ");
    }
    printf(") / (");
    for (int i = 0; i < C; i++) {
    	printf("?");
    	if (i < C - 1)
    		printf(" + ");
    }
    printf(")\n");
	printf("a = (e max e) max (e max e)\nb = a / a\nc = a - a\nd = b + b\n");
	vector<int> v;
	while (c) {
		v.push_back(c & 1);
		c >>= 1;
	}
	string ans = "b";
	for (int i = (int)v.size() - 2; i >= 0; i--) {
		if (v[i])
			ans = "d * (" + ans + ") + b";
		else
			ans = "d * (" + ans + ") + c";
	}
	cout << ans << endl;
    return 0;
}
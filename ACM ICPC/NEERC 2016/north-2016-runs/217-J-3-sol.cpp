#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
	freopen("java2016.in", "r", stdin);
	freopen("java2016.out", "w", stdout);
	int c;
	cin >> c;
	if (c == 0) {
		cout << "? / ? / ?" << endl;
		return 0;
    }
    printf("a = (? max ?) max (? max ?)\n");
    printf("b = (a max a) max (a max a)\n");
    printf("c = (b max b) max (b max b)\n");
    printf("d = (c max c) max (c max c)\n");
    printf("e = (d max d) max (d max d)\n");
    printf("f = (e max e) max (e max e)\n");
    printf("g = (f max f) max (f max f)\n");
	printf("h = (g max g) max (g max g)\n");
	printf("i = (h / h) max (h / h)\n");
	printf("j = i max i\n");
	printf("k = j max j\n");
	printf("y = k\nx = y - y\nz = y + y\n");
	vector<int> v;
	while (c) {
		v.push_back(c & 1);
		c >>= 1;
	}
	string ans = "y";
	for (int i = (int)v.size() - 2; i >= 0; i--) {
		if (v[i])
			ans = "z * (" + ans + ") + y";
		else
			ans = "z * (" + ans + ") + x";
	}
	cout << ans << endl;
    return 0;
}
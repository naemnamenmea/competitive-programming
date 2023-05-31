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
    printf("a = ? max ?\n");
    printf("b = a max a\n");
    printf("c = b max b\n");
    printf("d = c max c\n");
    printf("e = d max d\n");
    printf("f = e max e\n");
    printf("g = f max f\n");
	printf("h = g max g\n");
	printf("i = h max h\n");
	printf("j = i max i\n");
	printf("k = j max j\n");
	printf("l = (k / k) max (k / k)\n");
	printf("m = l max l\n");
	printf("n = m max m\n");
	printf("o = n max n\n");
	printf("p = o max o\n");
	printf("r = p max p\n");
	printf("s = r max r\n");
	printf("t = s max s\n");
	printf("u = t max t\n");
	printf("v = u max u\n");
	printf("y = v\nx = y - y\nz = y + y\n");
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
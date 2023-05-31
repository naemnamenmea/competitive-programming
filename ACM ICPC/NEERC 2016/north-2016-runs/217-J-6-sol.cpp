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
    int cnt = 0;
    printf("a = ? max ?\n"); cnt += 7;
    printf("b = a max a\n"); cnt += 7;
    printf("c = b max b\n"); cnt += 7;
    printf("d = c max c\n"); cnt += 7;
    printf("e = d max d\n"); cnt += 7;
    printf("f = e max e\n"); cnt += 7;
    printf("g = f max f\n"); cnt += 7;
	printf("h = g max g\n");cnt += 7;
	printf("i = h max h\n");     cnt += 7;
	printf("j = i max i\n");              cnt += 7;
	printf("k = j max j\n");                       cnt += 7;
	printf("l = k max k\n");                             cnt += 7;
	printf("m = l max l\n");cnt += 7;
	printf("n = m max m\n");         cnt += 7;
	printf("o = n max n\n");                  cnt += 7;
	printf("p = o max o\n");                           cnt += 7;
	printf("r = p max p\n");                                    cnt += 7;
	printf("s = r max r\n");cnt += 7;
	printf("t = s max s\n");         cnt += 7;
	printf("u = t max t\n");                  cnt += 7;
	printf("v = (u / u) max (u / u)\n");  cnt += 15;
	printf("w = v max v\n");         cnt += 7;
    printf("y = w max w\n");         cnt += 7;
	printf("x = y - y\nz = y + y\n"); cnt += 13;
	// cout << cnt << endl;
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
#include<stdio.h>
#include<iostream>
#include<vector>
#include <algorithm>
#include<math.h>

using namespace std;

int main() {
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	//for (int i = 0; i < 100000; ++i) {
	//	cout << i << " " << i << '\n';
	//}
	//return 0;
	pair<int, int> mas[100002];
	int *f = new int[1000000];
	int *s = new int[1000000];
	int *f_ = new int[1000000];
	int *s_ = new int[1000000];
	for (int i = 0; i < 1000000; ++i) {
		f[i] = 0;
		f_[i] = 0;
		s[i] = 0;
		s_[i] = 0;
	}
	int n = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> mas[i].first >> mas[i].second;
		f[mas[i].first] = 1;
		s[mas[i].second] = 1;
	}
	for (int i = 0; i < 1000000; ++i) {
		f_[i] = tmp1;
		if (f[i] != 1) {
			tmp1++;
		}
		s_[i] = tmp2;
		if (s[i] != 1) {
			tmp2++;
		}
	}
	for(int i = 0; i < n; ++i) {
		int res1 = mas[i].first - f_[mas[i].first];
		int res2 = mas[i].second - s_[mas[i].second];
		cout << max(res1, res2) << '\n';
	}
	return 0;
}
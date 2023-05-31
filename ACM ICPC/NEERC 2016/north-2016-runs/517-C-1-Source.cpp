#define _CRT_SEURE_NO_WARNINGS
#define lim int(2e6) + 2
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("codecoder.in", "rt", stdin);
	freopen("codecoder.out", "wt", stdout);
	int n;
	scanf("%d", &n);
	int a, b;
	vector<int> inp(n);
	vector<int> ans(lim, 0);
	vector<int> count = ans;
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &a, &b);
		inp[i] = a + b;
		++count[inp[i]];
	}
	for (int i = lim - 1; i >= 0; --i){
		if (count[i] != 0){
			ans[i] = n - 1;
			n -= count[i];
		}
	}
	for (int i = 0; i < inp.size(); ++i)
		printf("%d\n", ans[inp[i]]);
	return 0;
}
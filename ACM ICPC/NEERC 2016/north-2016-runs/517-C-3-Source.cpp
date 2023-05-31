#define _CRT_SEURE_NO_WARNINGS
#define lim int(2e6) + 2
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct fen{
	vector<int> a;
	fen()
		: a(1e6 + 1, 0)
	{}
	void set(int pos){
		for (; pos < a.size(); pos |= pos + 1)
			++a[pos];
	}

	void unset(int pos){
		for (; pos < a.size(); pos |= pos + 1)
			--a[pos];
	}

	int get(int pos){
		int sum = 0;
		for (; pos >= 0; pos = (pos&(pos + 1)) - 1)
			sum += a[pos];
		return sum;
	}
};

struct st{
	int x;
	int y;
	int pos;
	int ans;
	st(){}
	st(int x, int y, int pos, int ans)
		: x(x)
		, y(y)
		, pos(pos)
		, ans(ans)
	{}
};

bool cmpx(const st &l, const st &r){
	return l.x < r.x;
}
bool cmpp(const st &l, const st &r){
	return l.pos < r.pos;
}

int main(){
	freopen("codecoder.in", "rt", stdin);
	freopen("codecoder.out", "wt", stdout);
	int n;
	scanf("%d", &n);
	fen fn;
	int a, b;
	vector<st> inp(n);
	vector<bool> used(1e6 + 1, 0);
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &inp[i].x, &inp[i].y);
		inp[i].pos = i;
		used[inp[i].y] = 1;
		fn.set(inp[i].y);
	}
	sort(inp.begin(), inp.end(), cmpx);

	int max = 0;
	inp[0].ans = 0;
	fn.unset(inp[0].y);
	used[inp[0].y] = false;
	inp[0].ans += fn.get(inp[0].y);
	for (int k = inp[0].y - 1; k > max; --k)
		if (used[k]){
		used[k] = false;
		fn.unset(k);
		}
	max = inp[0].y;
	for (int i = 1; i < n; ++i){
		inp[i].ans = inp[i - 1].ans;
		if (inp[i].y < max) continue;
		++inp[i].ans;
		fn.unset(inp[i].y);
		used[inp[i].y] = false;
		inp[i].ans += fn.get(inp[i].y);
		for (int k = inp[i].y - 1; k > max; --k)
			if (used[k]){
			used[k] = false;
			fn.unset(k);
			}
		max = inp[i].y;
	}
	sort(inp.begin(), inp.end(), cmpp);
	for (int i = 0; i < n; ++i)
		printf("%d\n", inp[i].ans);
	return 0;
}
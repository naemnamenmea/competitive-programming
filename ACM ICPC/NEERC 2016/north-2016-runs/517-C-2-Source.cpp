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
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &inp[i].x, &inp[i].y);
		inp[i].pos = i;
	}
	sort(inp.begin(), inp.end(), cmpx);
	for (int i = n - 1; i >= 0; --i){
		inp[i].ans = i + fn.get(inp[i].y);
		fn.set(inp[i].y);
	}
	sort(inp.begin(), inp.end(), cmpp);
	for (int i = 0; i < n; ++i)
		printf("%d\n", inp[i].ans);
	return 0;
}
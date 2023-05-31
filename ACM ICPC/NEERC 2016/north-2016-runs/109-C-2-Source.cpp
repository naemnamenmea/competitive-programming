#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

struct cit
{
	int cc, tf, n, rc, rt;
};

int main()
{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	const int maxN = 100000;
	int n;
	scanf("%d", &n);
	vector <cit> v(n);
	vector <bitset<maxN>> s(n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &v[i].cc, &v[i].tf);
		v[i].n = i;
	}

	sort(v.begin(), v.end(), [](cit a, cit b) {
		return a.cc < b.cc;
	});

	for (int i = 1; i < n; ++i)
	{
		s[v[i].n][v[i - 1].n] = 1;
		s[v[i].n] |= s[v[i - 1].n];
	}

	sort(v.begin(), v.end(), [](cit a, cit b) {
		return a.tf < b.tf;
	});

	for (int i = 1; i < n; ++i)
	{
		s[v[i].n][v[i - 1].n] = 1;
		s[v[i].n] |= s[v[i - 1].n];
	}

	for (int i = 0; i < n; ++i)
	{
		s[i][i] = 0;
		printf("%d\n", s[i].count());
	}

	return 0;
}
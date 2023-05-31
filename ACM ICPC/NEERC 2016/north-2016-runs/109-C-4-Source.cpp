#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct cit
{
	int cc, tf, n;
};

int main()
{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n;
	scanf("%d", &n);

	vector <cit> v(n);
	vector <set<int>> s(n);

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
		s[v[i].n].insert(v[i - 1].n);
		s[v[i].n].insert(s[v[i - 1].n].begin(), s[v[i - 1].n].end());
	}

	sort(v.begin(), v.end(), [](cit a, cit b) {
		return a.tf < b.tf;
	});

	for (int i = 1; i < n; ++i)
	{
		s[v[i].n].insert(v[i - 1].n);
		s[v[i].n].insert(s[v[i - 1].n].begin(), s[v[i - 1].n].end());
	}

	for (int i = 0; i < n; ++i)
	{
		s[i].erase(i);
		printf("%d\n", s[i].size());
	}

	return 0;
}
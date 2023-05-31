#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n;
	scanf("%d", &n);
	vector <set<int>> s(n);
	vector <pair<int, int>> v(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[i].first > v[j].first || v[i].second > v[j].second)
			{
				s[i].insert(j);
				s[i].insert(s[j].begin(), s[j].end());
			}
		}
	}
	set<int> answer;
	for (int i = 0; i < n; ++i)
	{
		answer.clear();
		for (auto beat : s[i])
		{
			answer.insert(beat);
			answer.insert(s[beat].begin(), s[beat].end());
		}
		answer.erase(i);
		printf("%d\n", answer.size());
	}
	return 0;
}
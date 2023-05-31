#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct tri
{
	int n, x, y;
};

bool comp1(tri a, tri b)
{
	return a.x > b.x;
}

bool comp2(tri a, tri b)
{
	return a.y < b.y;
}

bool comp3(tri a, tri b)
{
	return a.n < b.n;
}


int main()
{
	int n;
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<tri> arr(n);
	vector<int> sns(n);
	for (int i = 0; i < n; i++)
	{
		tri t;
		cin >> t.x >> t.y;
		t.n = i;
		arr[i] = t;
	}
	sort(arr.begin(), arr.end(), comp2);
	for (int i = 1; i < n; i++)
	{
		sns[arr[i].n] = arr[i - 1].n;
	}
	sns[arr[0].n] = -1;
	sort(arr.begin(), arr.end(), comp1);
	vector<int> pos(n);
	for (int i = 0; i < n; i++)
		pos[arr[i].n] = i;
	vector<int> dyn2;
	dyn2.assign(n, 0);
	for (int i = n - 1; i > -1; i--)
	{
		if (i == (n - 1))
		{
			if (sns[arr[i].n] != -1)
				dyn2[i] = pos[sns[arr[i].n]];
			else
				dyn2[i] = i;
		}
		else
		{
			dyn2[i] = dyn2[i + 1];
			if (sns[arr[i].n] != -1)
				dyn2[i] = min(dyn2[i], pos[sns[arr[i].n]]);
		}
	}
	vector<int> dyn(n);
	dyn[0] = 0;
	for (int i = 1; i < n; i++)
	{
		if (dyn2[i] < i)
			dyn[i] = dyn[dyn2[i]];
		else
			dyn[i] = i;
	}
	//sort(arr.begin(), arr.end(), comp3);
	vector<int> ans(n);

	for (int i = 0; i < n; i++)
		ans[arr[i].n] = n - 1 - dyn[i];
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;
	return 0;
}

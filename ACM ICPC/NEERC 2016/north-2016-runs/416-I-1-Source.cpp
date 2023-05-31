#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;


vector<pair<int, int> > arr;

vector<int> pref1;
vector<int> pref2;
vector<int> pref3;
vector<int> pref4;



int main()
{
	int n, m;
	freopen("integral.in", "r", stdin);
	freopen("integral.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(a % 2, b % 2));
	}
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < n; i++)
	{

	}

	return 0;
}
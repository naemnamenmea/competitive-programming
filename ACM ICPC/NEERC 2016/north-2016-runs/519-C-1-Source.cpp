#include<fstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {

	ifstream cin("codecoder.in");
	ofstream cout("codecoder.out");
	int n; cin >> n;

	vector< pair< pair<int, int>, int> > arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first.first >> arr[i].first.second;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end());

	vector<int> Max(n);
	Max[0] = arr[0].first.second;
	for (int i = 1; i < n; i++)		Max[i] = max(arr[i].first.second, Max[i-1]);

	vector<int> res(n);
	res[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--)
	{
		int j = n-1;
		while (arr[j].first.second > Max[i] && j > i) j--;
		if (j == i)
			res[i] = i;
		else
			res[i] = res[j];
	}

	vector<int> Ans(n);
	for (int i = 0; i < n; i++)
		Ans[ arr[i].second ] = res[i];

	for (int i = 0; i < n; i++) cout << Ans[i] << '\n';
	//system("pause");
	return 0;
}
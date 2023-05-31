//#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("king.in");
ofstream out("king.out");

int main()
{
	in.sync_with_stdio(false);
    int dK, mK, yK;
	in >> dK >> mK >> yK;
	int n;
	in >> n;
	int months[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sumMonths[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	vector< int > v(n);
	vector<int> ans(n);
	int d, m, y;
	for (int i = 0; i < n; i++) {
		in >> d >> m >> y;
		v[i] = (365 * yK + sumMonths[mK] - months[mK] + dK) - (365 * y + sumMonths[m] - months[m] + d);
		ans[i] = v[i];
	}
	sort(v.begin(), v.end());
	auto it = lower_bound(v.begin(), v.end(), 6570);
	if (it != v.end()) {
		for (int i = 0; i < n; i++) {
			if (*it == ans[i]) {
				out << i + 1;
				break;
			}
		}
	}
	else out << -1;
	return 0;
}
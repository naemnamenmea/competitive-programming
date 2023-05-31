#include <iostream>
#include <cstdio>

using namespace std;

const int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long presum[11];
 
int main() {
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	presum[0] = months[0];
	for(int i = 1; i < 12; i++)
		presum[i] = presum[i - 1] + months[i];
	int n;
	long long kingdays, sondays, years18;
	long long d, m, y;
	cin >> d >> m >> y;
	kingdays = d + presum[m - 1] + y * presum[11];
	years18 = 18 * presum[11];
	cin >> n;
	long long minold = -1, minind = -1;
	for(int i = 0; i < n; i++) {
		cin >> d >> m >> y;
		sondays = d + presum[m - 1] + y * presum[11];
		long long old = kingdays - sondays;
			if ((old >= years18) && (old < minold || minind == -1)) {
				minold = old;
				minind = i + 1;
			}
	 }
	cout << minind << endl;
	return 0;
}

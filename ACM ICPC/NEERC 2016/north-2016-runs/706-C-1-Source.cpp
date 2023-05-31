#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1111111;
int cnt1[N], cnt2[N], cnt3[N], cnt4[N];
vector< pair<int, int> > ratings;


int main() {
	const string _cur = "codecoder"; freopen((_cur + ".in").c_str(), "r", stdin); freopen((_cur + ".out").c_str(), "w", stdout);
	int n; cin >> n;
	int i;

	ratings.resize(n + 1);

	for (i = 0; i < N; i++) {
		cnt1[i] = 0;
		cnt2[i] = 0;
		cnt3[i] = 0;
	}

	for (i = 1; i <= n; i++)
	{
		int cc, tf;
		cin >> cc >> tf;
		ratings[i] = make_pair(cc, tf);
		cnt1[cc] += 1;
		cnt2[tf] += 1;
		cnt3[min(cc, tf)] += 1;
		cnt4[max(cc, tf)] += 1;
	}

	/*for (i = 1; i <= 10; i++)
	{
		cout << cnt1[i] << " ";
	}
	cout << endl;
	for (i = 1; i <= 10; i++)
	{
		cout << cnt2[i] << " ";
	}
	cout << endl;
	for (i = 1; i <= 10; i++)
	{
		cout << cnt3[i] << " ";
	}
	cout << endl;*/

	for (i = 2; i < N; i++) {
		cnt1[i] += cnt1[i - 1];
		cnt2[i] += cnt2[i - 1];
		cnt3[i] += cnt3[i - 1];
	}


	/*for (i = 1; i <= 10; i++)
	{
		cout << cnt1[i] << " ";
	}
	cout << endl;
	for (i = 1; i <= 10; i++)
	{
		cout << cnt2[i] << " ";
	}
	cout << endl;
	for (i = 1; i <= 10; i++)
	{
		cout << cnt3[i] << " ";
	}
	cout << endl;*/


	for (i = 1; i <= n; i++) {

		int f = ratings[i].first, s = ratings[i].second;
		int c1 = cnt1[f - 1], c2 = cnt2[s - 1];
		int c3 = cnt3[min(f, s)-1], c4 = cnt4[max(f, s)-1];


		//cout << f << " " << s << " " << c1 << " " << c2 << " " << c3 << " " << c4 << endl;

		// cout << max(max(a1, a2), max(a3, a4)) << endl;

		//cout << max(cnt3[ratings[i].first - 1], cnt3[ratings[i].second - 1]) << endl;

		/*if (c2 == 0) cout << c1;
		else if (c1 == 0) cout << c2;
		else 
		cout << c1 + c2 - (c3 - c4);*/

		cout << max(c1, c2);

		cout << endl;

	}

	return 0;
}

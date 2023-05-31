#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 2e5;

pair <int, pair<int, int> > king, son[N];

int main()
{
#ifdef KOBRA
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
#endif // KOBRA
	cin >> king.second.second >> king.second.first >> king.first;
	int n;
	cin >> n;
	int cur = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> son[i].second.second >> son[i].second.first >> son[i].first;
		if (king.first - son[i].first > 18 || (king.first - son[i].first == 18 && king.second >= son[i].second)) {
			if (cur == -1 || son[i] > son[cur]) {
				cur = i;
			}
		} 
	}
	cout << cur << '\n';
    return 0;
}

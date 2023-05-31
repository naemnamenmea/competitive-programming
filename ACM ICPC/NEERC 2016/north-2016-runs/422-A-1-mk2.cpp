#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 2e5;

int main()
{
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
#endif
	int w, h;
	pair<int, int> a, b;
	cin >> w >> h;
	cin >> a.first >> a.second >> b.first >> b.second;
	if(a > b){
		swap(a, b);
	}
	if(a.first < b.first){
		cout << a.first << " " << 0 << " " << a.first + 1 << " " << h;
	} else {
		cout << 0 << " " << a.second << " " << w << " " << a.second + 1;
	}
    return 0;
}

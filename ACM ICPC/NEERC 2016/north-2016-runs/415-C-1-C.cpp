#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>

using namespace std;
typedef long long ll;

struct Cit
{
	ll a;
	ll b;
	ll i;
};

Cit a[110000] = {};
ll ans[110000] = {};

bool less1(const Cit &c1, const Cit &c2)
{
	if (c1.a < c2.a && c1.b <= c2.b || c1.b < c2.b && c1.a <= c2.a)
		return true;
	return false;
}

unordered_map<ll, unordered_map<ll, ll>> m;

int main(){
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].a >> a[i].b;
		a[i].i = i;
	}
	sort(a, a + n, less1);
	int i = 0;
	while (i < n - 1)
	{
		if (less1(a[i], a[i + 1]))
		{
			ans[a[i].i] = i;
			i++;
			continue;
		}
		m[a[i].a][a[i].b] = 1;
		int j = i;
		ll sum = 0;
		while (j < n - 1 && !less1(a[j], a[j + 1]))
		{    
			j++;
			m[a[j].a][a[j].b] += 1;
			sum += m[a[j].a][a[j].b] - 1;
		}
		for (int k = i; k <= j; k++)
			ans[a[k].i] = j - sum;
		i = j + 1;
	}
	if (i == n - 1)
		ans[a[i].i] = n - 1;
	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
	return 0;
}


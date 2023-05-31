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
Cit b[110000] = {};

bool less1(const Cit &c1, const Cit &c2)
{
	if (c1.a < c2.a && c1.b < c2.b)
		return true;
	else
		return c1.a < c2.a;
}

bool less2(const Cit &c1, const Cit &c2)
{
	if (c1.a < c2.a && c1.b < c2.b)
		return true;
	else
		return c1.b < c2.b;
}

vector<set<ll>> v;

ll ans[110000] = {};


int main(){
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ans[i] = -1;
		cin >> a[i].a >> a[i].b;
		a[i].i = i;
		b[i] = a[i];
	}
	sort(a, a + n, less1);
	sort(b, b + n, less2);
	/*v.resize(n);
	sort(a, a + n, less1);
	for (int i = 0; i < n - 1; i++)
	{
		v[a[i].i].insert(a[i + 1].i);
	}
	sort(a , a + n, less2);
	for (int i = 0; i < n - 1; i++)
	{
		v[a[i].i].insert(a[i + 1].i);
	}
	for (int i = 0; i < n; i++)
	{
		dfs(i);
	}
    for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";*/
	int i = 0;
	while (i < n)
	{
		ll min1 = a[i].a;
		ll min2 = b[i].b;

		ll max1 = b[i].a;
		ll max2 = a[i].b;

		int j = i + 1;
		while (j < n && (a[j].a >= min1 && a[j].a <= max1 || a[j].b >= min2 && a[j].b <= max2))
		{
			min1 = min(min1, min(a[j].a, b[j].a));
			min2 = min(min2, min(a[j].b, b[j].b));

			max1 = max(max1, max(a[j].a, b[j].a));
			max2 = max(max2, max(a[j].b, b[j].b));
			j++;
		}
		for (int k = i; k < j; k++)
		{
			ans[a[k].i] = j - 1;
		}
		i = j;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
	return 0;
}


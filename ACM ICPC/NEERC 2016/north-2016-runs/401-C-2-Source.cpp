#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const double EPS = 1e-8;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<pii> vii;
typedef vector<tiii> viii;

#define FNAME "codecoder"

const int MAXN = 100005;
const int MAXR = 1000005;

int ans[MAXN], prmax[MAXN];
int fenw[MAXR];

void fenw_set(int i, int x)
{
	while (i < MAXR) {
		fenw[i] = max(fenw[i], x);
		i += i & -i;
	}
}

int query(int i)
{
	int res = 0;
	while (i) {
		res = max(res, fenw[i]);
		i -= i & -i;
	}
	return res;
}

int main()
{
#ifdef FNAME
	freopen(FNAME ".in", "r", stdin);
	freopen(FNAME ".out", "w", stdout);
#endif

	int n;
	cin >> n;

	viii a;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a.pb(mt(x, y, i));
	}
	sort(all(a));

	prmax[0] = B(a[0]);
	fenw_set(B(a[0]), 0);
	for (int i = 1; i < n; i++) {
		prmax[i] = max(prmax[i - 1], B(a[i]));
		fenw_set(B(a[i]), i);
	}

	for (int i = 0; i < n; i++) {
		int rightmost = query(prmax[i] - 1);
		ans[C(a[i])] = max(i, rightmost);
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;

	return 0;
}
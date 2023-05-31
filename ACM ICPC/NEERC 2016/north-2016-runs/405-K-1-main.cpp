#include <bits/stdc++.h>

using namespace std;
                   
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

struct trip {
	int d, m, y, id;

	bool operator < (trip x) const {
		 if (y != x.y)
		 	return y < x.y;
		 if (m != x.m)
		 	return m < x.m;
		return d < x.d;
	}

    bool operator <= (trip x) const {
		 if (y != x.y)
		 	return y < x.y;
		 if (m != x.m)
		 	return m < x.m;
		return d <= x.d;
	}

    trip () {}                       

	trip (int d, int m, int y) : d (d), m (m), y (y) {}

	trip good () {
		return trip (d, m, y + 18);
	}
	friend istream& operator >> (istream& cin, trip &x) {
		cin >> x.d >> x.m >> x.y;
		return cin;
	}
};

int n;
trip mas[111];


int main () {                   
	freopen ("king.in", "r", stdin);
	freopen ("king.out", "w", stdout);

	trip D;
	cin >> D;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> mas[i];
		mas[i].id = i;
	}

	sort (mas, mas + n);

	int ans = -1;

	for (int i = 0; i < n; i++) {
		if (mas[i].good () <= D) {
			ans = mas[i].id + 1;
		}
	}

	cout << ans << endl;


	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back

#ifdef local
	#define files
	#define task "file"
#else
	#define files
	#define task "king"
#endif

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date_t {
	int day, month, year;
	int id;

	ll day_num() const {
		ll res= year * 365ll;
		for (int i = 0; i < month; i++) {
			res += days[i];
		}
		return res + day;
	}
	
	bool operator < (const date_t &date) const {
		return day_num() < date.day_num();
	}

	static date_t read()  {
		int a, b, c;
		cin >> a >> b >> c;
		return {a, b, c};
	}

	bool good(date_t death) const {
		int yd = death.year - year;
		int md = death.month - month;
		int dd = death.day - day;
		if (yd > 18) return true;
		if (yd < 18) return false;
		if (md >= 1) return true;
		if (md <= -1) return false;
		if (dd >= 0) return true;
		return false;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

#ifdef files
	freopen(task".in", "r", stdin);	
	freopen(task".out", "w", stdout);	
#endif

	date_t death = date_t::read();

	vector<date_t> dates;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		dates.eb(date_t::read());
		dates.back().id = i;
	}

	sort(dates.begin(), dates.end());
	for (int i = n - 1; i >= 0; i--) {
		if (dates[i].good(death)) {                                               
			cout << dates[i].id+1 << endl;
			return 0;
		}
	}

	cout << -1;
	return 0;
}
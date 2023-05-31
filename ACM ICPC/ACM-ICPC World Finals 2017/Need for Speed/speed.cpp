#include <bits/stdc++.h>

#define iloop(i,l,r) for(int i = l; i < r; ++i)
#define iloopi(i,l,r) for(int i = l; i <= r; ++i)
#define dloop(i,l,r) for(int i = r-1; i >= l; --i)
#define dloopi(i,l,r) for(int i = r; i >= l; --i)    
#define itloop(it,container) for(auto it = container.begin(); it != container.end(); ++it)

using namespace std;

int const N = 1005;
double const EPS = 1e-7;
double const MAX = 2.e8;
double const MIN = -2.e8;
int n;
double t;
vector<double> s;
vector<double> d;

double f(double c) {
	double sum = 0.;
	iloop(i, 0, n) {
		sum += d[i] / (s[i] + c);
	}
	return 1./t * sum - 1.;
}

double devision(double l, double r) {
	double mid = (l + r) / 2.;
	//cout << l << ' ' <<  r << endl;
	if (abs(l - r) < EPS) return mid;

	if (f(mid)*f(r) > 0.)
		return devision(l, mid);
	else
		return devision(mid, r);
}

int main() {

	cin >> n >> t;

	iloop(i, 0, n) {
		double length, speed;
		cin >> length;
		d.push_back(length);
		cin >> speed; 
		s.push_back(speed);
	}

	auto sorted_s(s);
	sorted_s.push_back(MAX);
	itloop(it, sorted_s) 
		*it = -(*it);	
	sort(sorted_s.begin(), sorted_s.end());

	double r = MAX;
	dloopi(i, 0, n) {
		double l = sorted_s[i] + EPS;

		double res = devision(l, r);		
		if (abs(f(res)) < EPS) {
			cout << fixed << setprecision(6) << res << endl;
			break;
		}

		r = sorted_s[i] - EPS;
	}

	return 0;
}
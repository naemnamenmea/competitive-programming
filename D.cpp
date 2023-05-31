//#define D

#ifdef D

#include <bits/stdc++.h>

using namespace std;

std::tuple<int, double, double> solveQuadEq(const double &a, const double &b, const double &c) {
	double x1, x2;
	double d = (b*b) - (4. * a*c);
	if (d > 0)
	{
		double tx1, tx2;
		tx1 = (-b + sqrt(d)) / (2 * a);
		tx2 = (-b - sqrt(d)) / (2 * a);
		x1 = ((tx1 > tx2) ? tx2 : tx1);
		x2 = ((tx1 > tx2) ? tx1 : tx2);
		return std::make_tuple(2, x1, x2);
	}
	else if (d == 0)
	{
		x1 = -b / (2 * a);
		return std::make_tuple(1, x1, x1);
	}
	else return std::make_tuple(-2, 0., 0.);
}

int main() {
	double L, K, T1, T2, H;
	cin >> L >> K >> T1 >> T2 >> H;
	
	double F1, F2;

	if (H < L) {
		F1 = F2 = H;
	}
	else {
		double a = -T1;
		double b = H + K * (T1 + T2);
		double c = -L;

		auto res = solveQuadEq(a, b, c);

		double R = get<2>(res);

		cout << get<1>(res) << endl;
		cout << get<2>(res) << endl;
		//cout << R*T1 << endl;
	}

	cout << fixed << showpoint << setprecision(6);
	cout << F1 << ' ' << F2 << endl;
	return 0;
}

#endif // D

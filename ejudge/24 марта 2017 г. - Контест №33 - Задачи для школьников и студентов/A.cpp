#if !defined(LOCAL_KONTROL) || defined(A_24_03_2017)

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
T gcd(T a, T b) {
	return b ? gcd(b, a % b) : a;
}

int main() {

	int x, y;
	cin >> x >> y;

	int numerator = 6 - max(x, y) + 1;
	int denominator = 6;

	int gcd__ = gcd(numerator, denominator);

	numerator /= gcd__;
	denominator /= gcd__;

	cout << numerator << '/' << denominator;

	return 0;
}

#endif // A_24_03_2017
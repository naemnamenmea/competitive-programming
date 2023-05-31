#if !defined(LOCAL_KONTROL) || defined(D_24_03_2017)

#include <iostream>

using namespace std;

template<typename T>
T gcd(T a, T b) {
	return b ? gcd(b, a % b) : a;
}

int main() {

	int a;
	int sum = 0;
	cin >> a;
	for (int radix = 2; radix < a; ++radix) {
		int x = a;

		while (x>0) {
			sum += x % radix;
			x /= radix;
		}
	}

	int numerator = sum;
	int denominator = a - 2;

	int gcd__ = gcd(numerator, denominator);

	cerr << numerator << ' ' << denominator << endl;

	numerator /= gcd__;
	denominator /= gcd__;

	cout << numerator << '/' << denominator;

	return 0;
}

#endif // D_24_03_2017
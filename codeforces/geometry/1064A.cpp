#ifdef codeforces_1064A

#include <iostream> 

using namespace std;

int main() {

	int a, b, c, res;
	cin >> a >> b >> c;

	if (a + b > c && a + c > b && b + c > a) {
		res = 0;
	}
	else {
		if (b < c) {
			swap(b, c);
		}
		if (a < c) {
			swap(a, b);
			swap(b, c);
		}
		else if (a < b) {
			swap(a, b);
		}

		res = a - (b + c) + 1;
	}

	cout << res;

	return 0;
}
#endif // codeforces_1064A

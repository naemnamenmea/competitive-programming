#include <bits/stdc++.h>

using namespace std;

int main()
{
	long double n;
	cin >> n;
	if (!n) {
		cout << 0 << endl;
	}
	else {
		cout << (int)floor(log2(n)+1) << endl;
	}
    return 0;
}
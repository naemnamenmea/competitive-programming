#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{	
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());

	ll s, l1, r1, l2, r2;
	cin >> s >> l1 >> r1 >> l2 >> r2;
	if (l1 + l2 > s || r1 + r2 < s) {
		cout << -1 << endl;
		return 0;
	}
	if (s - l1 <= r2) {
		cout << l1 << " " << s - l1 << endl;
	}
	else {
		cout << s - r2 << " " << r2 << endl;
	}
    return 0;
}
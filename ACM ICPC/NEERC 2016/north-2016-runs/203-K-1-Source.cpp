#include <fstream>
#include <iostream>

using namespace std;


int main() {
	string name = "king";
	ifstream in(name + ".in");
	ofstream out(name + ".out");

	long d, m, y, d1, m1, y1, dm, mm, ym;
	in >> d >> m >> y;
	long n = 0;
	in >> n;
	long result = 0;
	long k = 0;
	bool bo = true;
	for (int i = 0; i < n; i++) {
		in >> d1 >> m1 >> y1;
		/*if ((d - d1) < 0) {
			m1++;
		}
		if ((m - m1) < 0) {
			y1++;
		}
		if ((y - y1) >= 18) {
			result++;
		}*/
		d1 = d - d1;
		m1 = m - m1;
		y1 = y - y1;
		if (d1 < 0) {
			d1 = 31 + d1;
			m1--;
		}
		if (m1 < 0) {
			m1 = 13 + m1;
			y1--;
		}
		if (y1 >= 18) {
			if (bo) {
				bo = false;
				dm = d1;
				mm = m1;
				ym = y1;
			}

			result++;
			if (y1 < ym) {
				ym = y1;
				dm = d1;
				mm = m1;
				k = i;
			}
			else if (y1 == ym && m1 < mm) {
				ym = y1;
				dm = d1;
				mm = m1;
				k = i;
			}
			else if (y1 == ym && m1 == mm && d1 < dm) {
				ym = y1;
				dm = d1;
				mm = m1;
				k = i;
			}
		}
		//cout << d1 << " " << m1 << " " << y1 << endl;
	}
	if (result == 0) {
		out << -1;
		return 0;
	}
	out << k + 1;

	return 0;
}
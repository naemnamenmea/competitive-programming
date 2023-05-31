#include <fstream>
#include <iostream>

using namespace std;


int main() {
	string name = "codecoder";
	ifstream in(name + ".in");
	ofstream out(name + ".out");
	long n;
	in >> n;
	long ** a = new long*[n];
	long * res = new long[n];
	for (int i = 0; i < n; i++) {
		a[i] = new long[2];
		res[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		in >> a[i][0] >> a[i][1];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j][0] < a[i][0] || a[j][1] < a[i][1]) {
				res[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		out << res[i] << endl;
	}

	return 0;
}
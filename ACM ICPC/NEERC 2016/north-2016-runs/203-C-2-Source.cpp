#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool cont(long j, vector<long> l) {
	for (int i = 0; i < l.size(); i++) {
		if (l[i] == j) {
			return true;
		}
	}
	return false;
}

struct S {
	long a;
	vector<long> b;
};

int main() {
	string name = "codecoder";
	ifstream in(name + ".in");
	ofstream out(name + ".out");
	long n;
	in >> n;
	long ** a = new long*[n];
	S * res = new S[n];
	for (long i = 0; i < n; i++) {
		a[i] = new long[2];
		res[i].a = 0;
	}
	for (long i = 0; i < n; i++) {
		in >> a[i][0] >> a[i][1];
	}
	for (long i = 0; i < n; i++) {
		for (long j = 0; j < n; j++) {
			if (a[j][0] < a[i][0] || a[j][1] < a[i][1]) {
				res[i].b.push_back(j);
				res[i].a++;
			}
		}
	}
	for (long i = 0; i < n; i++) {
		for (long j = 0; j < n; j++) {
			if (cont(j, res[i].b)) {
				long len = res[j].b.size();
				for (long k = 0; k < len; k++) {
					if (!cont(res[j].b[k], res[i].b) && (res[j].b[k] != i)) {
						res[i].b.push_back(res[j].b[k]);
					}
				}
			}
		}
	}
	for (long i = 0; i < n; i++) {
		out << res[i].b.size() << endl;
	}

	return 0;
}
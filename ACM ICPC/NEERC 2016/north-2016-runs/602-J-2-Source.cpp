#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>

using namespace std;

void main() {
	ifstream in("java2016.in");
	ofstream out("java2016.out");

	string zero = "z = ? max ? \n";
	vector<string> bin(8);
	bin[0] = "a = (z max z) / z \n"; // 1
	bin[1] = "b = a + a \n"; // 2
	bin[2] = "c = b * b \n"; // 4
	bin[3] = "d = b * c \n"; // 8
	bin[4] = "e = b * d \n"; // 16
	bin[5] = "f = b * e \n"; // 32
	bin[6] = "g = b * f \n"; // 64
	bin[7] = "h = b * g \n"; //128

	int n;
	in >> n;

	if (n == 0) {
		out << "?/?/?";
		return;

	}


	vector<int> v(8);
	int pt = 0;
	while (n != 0) {
		if (n % 2 == 0)
			v[pt] = 0;
		else
			v[pt] = 1;
		n /= 2;
		pt++;
	}
	//reverse(v.begin(), v.end());


	out << zero;
	for (int i = 0; i < 8; i++)
		out << bin[i];
	string a = "";
	for (int i = 0; i < 8; i++) {
		if (v[i] == 1) {
			a.push_back(char(int('a') + i));
			a.push_back('+');

		}
	}
	a = a.substr(0, a.size() - 1);
	out << a;
}
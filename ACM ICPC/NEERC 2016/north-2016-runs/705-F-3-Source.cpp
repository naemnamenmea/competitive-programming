#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ifstream in("folding.in");
	ofstream out("folding.out");
	int a, b, x, y, i = 0 , j = 0;
	in >> a >> b >> x >> y;
	if (a < b) swap(a, b);
	if (x < y) swap(x, y);
	if (a < x || b < y){
		out << -1;
		return 0;
	}
	while(a > x) {
		a = a / 2 + a % 2;
		i++;
	}
	while (b > y){
		b = b / 2 + b % 2;
		j++; 
	}
	out << i + j;
	return 0;
}
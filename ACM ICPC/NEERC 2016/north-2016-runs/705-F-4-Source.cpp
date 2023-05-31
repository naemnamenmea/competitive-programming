#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ifstream in("folding.in");
	ofstream out("folding.out");
	int a, b, x, y, i = 0 , j = 0,i2 = 0,j2 = 0;
	in >> a >> b >> x >> y;
	if (a < b) swap(a, b);
	if (x < y) swap(x, y);
	if (a < x || b < y){
		out << -1;
		return 0;
	}
	int a2 = a;
	while(a > x) {
		a = a / 2 + a % 2;
		i++;
	}
	int b2 = b;
	while (b > y){
		b = b / 2 + b % 2;
		j++; 
	}
	int res = i + j;
	if (b2 >= x){
		swap(a2, b2);
		while (a2 > x) {
			a2 = a2 / 2 + a2 % 2;
			i2++;
		}
		while (b2 > y){
			b2 = b2 / 2 + b2 % 2;
			j2++;
		}
		res = min(res, i2 + j2);
	}
	out << res;
	return 0;
}
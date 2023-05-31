#include <fstream>

using namespace std;


int main(){

	ifstream cin("folding.in");
	ofstream cout("folding.out");
	

	int a, b, c, d;

	cin >> a >> b >> c >> d;
	if (a < b) swap(a,b);
	if (c < d) swap(c,d);

	if ((c > a) || (d > b)){
		cout << -1;
		return 0;
	}
	int k = 0;
	while ((c << k) < a) k++;
	int m = 0;
	while ((d << m) < b) m++;

	cout << k + m;
	return 0;
}
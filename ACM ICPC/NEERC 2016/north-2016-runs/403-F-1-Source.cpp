#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ifstream in("folding.in");
	ofstream out("folding.out");
	vector <long long> a(2, 0);
	vector <long long> b(2, 0);
	int ans = 0;
	in >> a[0] >> a[1];
	in >> b[0] >> b[1];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a[0] < b[0] || a[1] < b[1]){
		out << -1;
		return 0;
    }
	while (a[0] > b[0] ){
		a[0] = ceil(a[0] / 2.);
		ans += 1;
    }
	while (a[1] > b[1]){
		a[1] = ceil(a[1] / 2.);
		ans += 1;
    }
	out << ans;
	
	return 0;
}
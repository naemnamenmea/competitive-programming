#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct rate {
	int data;
	int comp = 0;
	int num;
};
//
int main() {
	vector<rate> citizens;
	rate temp;
	int n;
	ifstream in("coder.in");
	ofstream out("coder.out");
	in >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		in >> a >> b;
		temp.data = a + b;
		temp.num = i;
		citizens.push_back(temp);

	}
	sort(citizens.begin(), citizens.end(), [](rate A, rate B){return A.data > B.data; });
	int last = 0, lastd = 912094812091;
	for (int i = 0; i < citizens.size(); i++){
		if (citizens[i].data != lastd) {
			lastd = citizens[i].data;
			last = i;
		}
		citizens[i].comp = citizens.size() - last-1;
	}
	sort(citizens.begin(), citizens.end(), [](rate A, rate B){return A.num < B.num; });
	for (int i = 0; i < citizens.size(); i++){
		out << citizens[i].comp << endl;
	}
	return 0;
}
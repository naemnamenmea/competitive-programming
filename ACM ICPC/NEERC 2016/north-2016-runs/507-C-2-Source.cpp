#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;
struct st{
	int x, y, z;
};
int main(){
	ifstream in("codecoder.in");
	ofstream out("codecoder.out");
	int n;
	in >> n;
	vector<st> a(n),b(n);
	vector<int> c;
	for (int i = 0; i < n; ++i){
		a.at(i).x = i + 1;
		in>>a.at(i).y;
		in>>a.at(i).z;
	}
	b = a;
	sort(a.begin(), a.end(), [](st& a1, st& b1){return a1.y < b1.y; });
	sort(b.begin(), b.end(), [](st& a1, st& b1){return a1.z < b1.z; });
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (a[j].x != i + 1){
				c.push_back(a[j].x);
			}
			else
				break;
		}
		for (int j = 0; j < n; ++j){
			if (b[j].x != i + 1){
				c.push_back(b[j].x);
			}
			else
				break;
		}
		sort(c.begin(), c.end());
		out<<unique(c.begin(), c.end()) - c.begin()<<endl;
		c.clear();
	}
    in.close();
	out.close();
	return 0;
}


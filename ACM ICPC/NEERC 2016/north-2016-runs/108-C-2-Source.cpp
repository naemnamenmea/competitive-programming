#define _USE_MATH_DEFINES
#include<fstream>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<iterator>
#include<algorithm>
#include<iomanip>
#include<tuple>
#include<functional>
#include<forward_list>
#include<cmath>
using namespace std;
class s{
public:
	int a, b, i;
	s(){
		s(0, 0, 0);
	}
	s(int ll, int rr, int mmin){
		a= ll;
		b = rr;
		i = mmin;
	}
};


bool fs(s &a, s &b){
		return a.a>b.a;
}
bool fs2(s &a, s &b){
	return a.b>b.b;
}
int main(){
	ifstream in("codecoder.in");
	ofstream out("codecoder.out");
	int n,k;
	in >> n;
	vector<int> r(n), ml(1000001), mr(1000001);
	vector<s> v(n);
	for (int i = 0; i < n; i++){
		int a, b;
		in >> a >> b;
		v[i] = s(a, b, i);
	}
	sort(v.begin(), v.end(), fs2);
	for (int i = 0; i < n; i++){
		for (int t = i + 1; t < n; t++){
			if (v[i].b>v[t].b){
				r[v[i].i] = n - t ;
				k = t - 1;
				break;
			}
		}
		for (int t = k; t >= 0; t--){
			if (v[i].a>v[t].a)
				r[v[i].i]++;
		}
	}
	for (int i = 0; i < n; i++)
		out << r[i] << endl;
	return 0;
}
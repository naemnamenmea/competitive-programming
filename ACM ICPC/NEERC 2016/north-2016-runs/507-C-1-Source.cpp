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
	vector<long long> p(100001),ra(100001);
	for (int i = 0; i < n; ++i){
		a.at(i).x = i + 1;
		in>>a.at(i).y;
		in>>a.at(i).z;
		p[i] = 0;
		ra[i] = 0;
	}
	p[n] = 0;
	ra[n] = 0;
	b = a;
	sort(a.begin(), a.end(), [](st& a1, st& b1){return a1.y < b1.y; });
	sort(b.begin(), b.end(), [](st& a1, st& b1){return a1.z < b1.z; });
	long long count(0);
	for (long long i=1; i < n;i++)
		if (a[i].y == a[i - 1].y) p[a[i].x] = count;
		else
		{
			count++;
			p[a[i].x] = count;
		}

	
	count=0;
	for (long long i = 1; i < n; i++)
		if (b[i].z == b[i - 1].z) p[b[i].z] += count;
		else
		{
			count++;
			p[b[i].x] += count;
		}
	
	count = 0;
	for (long long i = 1; i < n; i++)
		if ((a[i].y > a[i - 1].y)&&(a[i].z> a[i-1].z)) ra[a[i].x] = i;
		else
			ra[a[i].x] = ra[a[i-1].x];

	for (long long i = 1; i <= n; i++)
		out << p[i]-ra[i] << endl;
    
    
    	in.close();
	out.close();
	return 0;
}


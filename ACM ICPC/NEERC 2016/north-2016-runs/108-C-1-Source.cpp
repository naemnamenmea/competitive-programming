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




bool fs(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}
int main(){
	ifstream in("codecoder.in");
	ofstream out("codecoder.out");
	int n;
	in >> n;
	vector<int>  r(n), mini(n,-1);
	vector<pair<int, int>> vmin(n), vmax(n);
	for (int i = 0; i < n; i++){
		int a, b;
		in >> a >> b;
		vmin[i].first = min(a, b);
		vmin[i].second=vmax[i].second = i;
		vmax[i].first = max(a, b);
	}
	sort(vmin.begin(), vmin.end(), fs);
	sort(vmax.begin(), vmax.end(), fs);
	int cur = 0,res=0;
	for (int i = 0; i < n; i++){
		int own = 0;
		while (cur < n){
			mini[vmin[cur].second] = cur;
			if (vmax[i].first > vmin[cur].first){
				res++;
			}
				else
					break;
			cur++;
		}
		r[vmax[i].second] = max(0,res-((mini[vmax[i].second]==-1)?0:1));
	}
	for (int i = 0; i < n; i++)
		out << r[i] << endl;
	return 0;
}
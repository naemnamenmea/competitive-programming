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
int amax = 0, bmax = 0, cmax = 0, res = -1,i;
int a, b, c;
void upd(){
	if (c > cmax){
		cmax = c;
		bmax = b;
		amax = a;
		res = i;
	}
	else if (c == cmax)
		if (b > bmax){
		cmax = c;
		bmax = b;
		amax = a;
		res = i;
		}
		else if (b == bmax)
			if (a < amax){
		cmax = c;
		bmax = b;
		amax = a;
		res = i;
			}
}
int main(){
	ifstream in("king.in");
	ofstream out("king.out");
	int k1, k2, k3;
	in >> k1 >> k2 >> k3;
	int n;
	in >> n;
	for (i = 0; i < n; i++){
		in >> a >> b >> c;
		if (k3 - c > 18)
			upd();
		else
			if (k3 - c == 18)
				if (b > k2)
					upd();
				else
					if (b == k2)
						if (a >= k1)
							upd();
	}
	out << res;
}
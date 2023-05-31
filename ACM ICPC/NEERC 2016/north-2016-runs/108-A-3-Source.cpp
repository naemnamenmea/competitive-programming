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





int main(){
	ifstream in("anniversary.in");
	ofstream out("anniversary.out");
	long long w, h, x1, y1, x2, y2;
	in >> w >> h >> x1 >> y1 >> x2 >> y2;
	if (x1 > x2){
		swap(x1, x2);
		swap(y1, y2);
	}
	if (x1 == x2){
		out << 0 << " " << min(y1,y2) << " " << w << " " << max(y1,y2);
	}
	else{
		if (y2 <= y1)
			out << x1 << " " << 0 << " " << x1 + 1 << " " << h;
		else
			out << x1 + 1 << " " << 0 << " " << x1 << " " << h;
	}
}
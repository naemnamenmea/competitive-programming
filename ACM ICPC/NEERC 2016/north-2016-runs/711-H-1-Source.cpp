#include<iostream>
#include<math.h>
#include <vector>
using namespace std;

const double eps = 1e-9;

int gcd(int a, int b){
	return(b == 0) ? a : gcd(b, a%b);
}

struct tri{
	int a, b, c;
	tri(int a, int b, int c):a(a), b(b), c(c){}
};

vector <tri> ans;

void f(int x, int y, int w, int h){
	if (w == x || h == y)
		return;
	if ((w - x) % 2 == 0 && w-x == 1 + h - y){
		ans.push_back(tri(x, y, (w-x)/2));
		ans.push_back(tri(x + (w - x) / 2, y, (w-x) / 2));
		f(x, y + (w - x) / 2, w, h);
	}
	else if ((h-y) % 2 == 0 && w - x +1 == h - y){
		ans.push_back(tri(x, y, (h - y) / 2));
		ans.push_back(tri(x, y + (h-y)/2, (h-y)/2));
		f(x + (h - y) / 2, y, w, h);
	}
	else if (w - x >= h - y){
		ans.push_back(tri(x, y, h - y));
		f(x + h - y, y, w, h);
	}
	else{
		ans.push_back(tri(x, y, w - x));
		f(x, y + w - x, w, h);
	}
}

int main()
{
	freopen("hard.in", "r", stdin);
	freopen("hard.out", "w", stdout);

	int t; cin >> t;
	while (t--){
		int w, h;
		cin >> w >> h;
		int gc = gcd(w, h);
		w /= gc; h /= gc;
		
		f(0, 0, w, h);
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].a*gc << ' ' << ans[i].b*gc << ' ' << ans[i].c*gc << endl;
		ans.clear();
	}
	return 0;
}
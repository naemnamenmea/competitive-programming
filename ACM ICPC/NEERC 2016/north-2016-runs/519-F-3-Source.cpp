#include<fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream cin("folding.in");
	ofstream cout("folding.out");
	long long w, h, ww, hh;
	cin >> w >> h >> ww >> hh;
	if (ww < hh) swap(ww, hh);
	if (w < h) swap(w, h);
	if (ww > w || hh > h) cout << -1 << endl;
	
	else
	{
		int e1 = w - ww, e2 = w - hh, e3 = h - ww, e4 = h - hh;
		
		if (e2 >= 0 && e2 >= e1 && e2 >= e3 && e2 >= e4) swap(ww, hh);
		else
			if (e3 >= 0 && e3 >= e1 && e3 >= e2 && e3 >= e4) swap(ww, hh);
		int kol = 0;
		while (ww < w) {
			++kol;
			w = (w+1) / 2;
		}
		while (hh < h) {
			++kol;
			h = (h+1) / 2;
		}

		cout << kol << endl;
	}
	  //system("pause");
	return 0;
}
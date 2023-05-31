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
		int w1 = w;
		int h1 = h;

		int kol = 0;
		while (ww < w) {
			++kol;
			w = (w+1) / 2;
		}
		while (hh < h) {
			++kol;
			h = (h+1) / 2;
		}
		swap(ww, hh);
		if (ww <= w1 && hh <= h1) {
			int kol1 = 0;
			while (ww < w1) {
				++kol1;
				w1 = (w1 + 1) / 2;
			}
			while (hh < h1) {
				++kol1;
				h1 = (h1 + 1) / 2;
			}
			if ( kol1 < kol) kol = kol1;
		}
		cout << kol << endl;
	}
	 //system("pause");
	return 0;
}
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
		int kol = 0;
		while (ww < w) {
			++kol;
			ww = ww * 2;
		}
		while (hh < h) {
			++kol;
			hh = hh * 2;
		}

		cout << kol << endl;
	}
//	system("pause");
	return 0;
}
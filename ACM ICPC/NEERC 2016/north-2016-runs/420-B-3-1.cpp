#include <bits/stdc++.h>


using namespace std;

void fail() {
	cout << "Impossible" << endl;
}


const int MAXN = (int) 1e5 + 10;
char ans[MAXN];
int n;

void make_ans(int pos, int g, int b, int bl) {
   	for (int i = 0; i < g + 1; ++i) {
   		ans[pos] = 'G';
   		pos += 2;
   		pos %= n;
   	}


   	for (int i = 0; i < b + 1; ++i) {
   		ans[pos] = 'B';
   		pos += 2;
   		pos %= n;
   	}

   	int rest = g + b + bl - g - b - 2;

   	for (int i = 0; i < rest / 2; ++i) {
   		ans[pos] = 'G';
   		pos += 2;
   		pos %= n;
   		ans[pos] = 'B';
   		pos += 2;
   		pos %= n;
   	}
}

void print() {
	for (int i = 0; i < n; ++i) {
		cout << ans[i];
	}
	cout << endl;
}


int main() {
	freopen("boysgirls.in", "r", stdin);
	freopen("boysgirls.out", "w", stdout);

	int x, y;
	cin >> n >> x >> y;

	int gg = n - x;
	int bb = n - y;
	int bg = x + y - n;

	if (bg < 0 || bg % 2 == 1) {
		fail();
		return 0;
	}

	if (bg == 0) {
		if (bb == gg) {
        	for (int i = 0; i < n / 2; ++i) cout << "BG";
        	cout << endl;
        	return 0;
        }
        if (bb == n) {
        	for (int i = 0; i < n; ++i) cout << "B";
        	cout << endl;
        	return 0;
        }
        if (gg == n) {
        	for (int i = 0; i < n; ++i) {
        		cout << "G";
        	}
        	cout << endl;
        	return 0;
        }
        fail();
        return 0;
	}

	if (n % 2 == 1) {
		make_ans(0, gg, bb, bg);
		print();
		return 0;
	}

	if (bg == 2) {
		if (gg >= n / 2) {
			for (int i = 0; i < n / 2; ++i) {
				ans[2 * i] = 'G';
			}

			make_ans(1, gg - n / 2, bb, bg);
			print();
			return 0;
		}                                 
		if (bb >= n / 2) {
		 	for (int i = 0; i < n / 2; ++i) {
				ans[2 * i] = 'B';
			}

			make_ans(1, gg, bb - n / 2, bg);
			print();
			return 0; 	
		}
		fail();
		return 0;
	}

	int bg1 = 2;
	int bg2 = 2;
	if (bg % 4 == 0) {
		bg1 = bg / 2;
		bg2 = bg / 2;
	}
	else {
		bg1 = bg / 2 + 1;
		bg2 = bg / 2 - 1;

		if (bg1 > n / 2) {
			fail();
			return 0;
		}
    }

    int g1 = 0, b1 = 0;
    while (gg > 0 && g1 + bg1 + b1 < n / 2) {
    	--gg;
    	++g1;
    }
    while (bb > 0 && g1 + bg1 + b1 < n / 2) {
    	--bb;
    	++b1;
    }

    make_ans(0, g1, b1, bg1);
    make_ans(1, gg - g1, bb - b1, bg2);
    print();
	return 0;
}
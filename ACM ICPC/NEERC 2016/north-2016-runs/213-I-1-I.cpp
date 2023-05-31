#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


const int N = 2*10e5 + 5;
long long ans[N];
int x[N];
int y[N];

int fair_count(int k, int n) {
//	cerr << k << endl;
	int i = (k + 1)%n;
	int count_nn = 0;
	int ans = 0;

	while (i != k) {
		if (((x[i] - x[((i - 1) + n)%n]) %2) != 0 && ((y[i] - y[((i - 1) + n)%n]) %2) != 0) {
			count_nn++;
			count_nn %= 2;
		}
		bool half_d = false;
		if (((x[i] - x[k]) %2) != 0 && ((y[i] - y[k]) %2) != 0) {
			half_d = true;			
		}
		if (half_d && (count_nn == 1) || (!half_d) && (count_nn == 0)) {
			ans++;
		} 
//		cerr << i << " " << count_nn << " " << x[i] - x[((i - 1) + n)%n]  << " " << y[i] - y[((i - 1) + n)%n] << endl;
		i++;
		i %= n;
	}
//	cerr << endl;
	return ans;
}

pair<int, int> a[2][2];
pair<int, int> a_new[2][2];

int main() {
	freopen("integral.in", "r", stdin);
	freopen("integral.out", "w", stdout);

	int n;
	int abs_count_nn = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		if (i != 0) {
			if ((x[i] - x[i - 1]) %2 != 0 && (y[i] - y[i - 1]) %2 != 0) {
				abs_count_nn++;
			}
		}
	} 	
	if ((x[n - 1] - x[0]) % 2 != 0 && (y[n - 1] - y[0]) %2 != 0) {
		abs_count_nn++;
	} 
	
	if (abs_count_nn % 2 != 0) {
		printf("0");
		return 0;
	}
	
	ans[0] = fair_count(0, n);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = make_pair(-1, 0);
		}
	}
	a[0][0] = make_pair(0, 0);
	for (int i = 1; i < n; i++) {
		int dx = x[i] - x[i - 1];
		int dy = y[i] - y[i - 1];
		dx %= 2;
		dy %= 2;
		if (dx == -1) dx = 1;
		if (dy == -1) dy = 1;
//		cerr << i << " " << i - 1 << " " << dx << " " << dy << endl;

		if (dx == 1 && dy == 1) {
//			cerr << i << " " << "here!" << endl;
			for (int k = 0; k < 2; k++) {
				for (int j = 0; j < 2; j++) {
					a[k][j].second++;
				}
			}
		}
				
		if (a[dx][dy].first == -1) {
//			cerr << "fair_count " << i << endl;
			ans[i] = fair_count(i, n);
		} else {
			pair<int, int> t = a[dx][dy];
//			cerr << t.second << endl;
			if ((t.second) %2 == 0)
				ans[i] = ans[t.first];
        	else {
        		ans[i] = n - 1 - ans[t.first];
        	}
//        	cerr << i << " " << ans[i] << " " << t.first << " " << ans[t.first] << endl;    
        }
		for (int i = 0; i < 2; i++) {
	    	for (int j = 0; j < 2; j++) {
	    		a_new[i][j] = a[i ^ dx][j ^ dy];
	    	}
		}
		a_new[dx][dy] = make_pair(i - 1, 0);
		if (dx == 1 && dy == 1 ) {
			a_new[dx][dy].second = 1;
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				a[i][j] = a_new[i][j];
			}
		}
	}

	long long ans_glob = 0;

	for (int i = 0; i < n; i++) {
		ans_glob += ans[i] - 2;
//		cout << ans[i] - 2 << " ";
	}
//	cout << endl;
	cout << ans_glob/2 << endl;

	return 0;
}
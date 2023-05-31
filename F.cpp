//#define F

#ifdef F

#include <bits/stdc++.h>

using namespace std;

int main() {
	int grid[100][100];
	int AM[70][70];
	int n;
	cin >> n;
	++n;
	int size = (n+1)*(n+1);


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char input;
			cin >> input;
			grid[i][j] = (input == '.') ? -1 : (input - '0');
		}
	}

	for (int i = 1; i <= size; ++i) {
		for (int j = 1; j <= size; ++j) {
			AM[i][j] = 0;
		}
	}

	bool finish = true;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (grid[i][j] < 1) continue;
			int cnt = 0;
			int ni, nj;
			int v1 = (i - 1)*n + j;
			int v2;

			if (i > 1 && j > 1) {
				ni = i - 1;
				nj = j - 1;
				v2 = (ni - 1)*n + nj;
				if (grid[ni][nj] != 0 && AM[i*n + j - 1][(i - 1)*n + j] == 0) {
					++cnt;
				}
			}
			if (i > 1 && j < n) {
				ni = i - 1;
				nj = j + 1;
				v2 = (ni - 1)*n + nj;
				if (grid[ni][nj] != 0 && AM[(i - 1)*n + j][i*n + j + 1] == 0) {
					++cnt;
				}
			}
			if (i < n && j > 1) {
				ni = i + 1;
				nj = j - 1;
				v2 = (ni - 1)*n + nj;
				if (grid[ni][nj] != 0
					&& AM[i*n + j - 1][(i + 1)*n + j] == 0
					/*&& AM[][] == 0*/) {
					++cnt;
				}
			}
			if (i < n && j < n) {
				ni = i + 1;
				nj = j + 1;
				v2 = (ni - 1)*n + nj;
				if (grid[ni][nj] != 0 && AM[(i + 1)*n + j][i*n + j + 1] == 0) {
					++cnt;
				}
			}

			if (cnt > 1) {
				continue;
			}

			finish = false;

			AM[v1][v2] = 1;
			AM[v2][v1] = 1;

			--grid[i][j];
			if (grid[ni][nj] > 0)
				--grid[ni][nj];

			i = 0;
			break;
		}
		if (finish) break;
		finish = true;
	}

	for (int i = 1; i <= size; ++i) {
		for (int j = 1; j <= size; ++j) {
			cout << AM[i][j];
		}
		cout << endl;
	}


	//еще один такой же обход

	return 0;
}

#endif // F

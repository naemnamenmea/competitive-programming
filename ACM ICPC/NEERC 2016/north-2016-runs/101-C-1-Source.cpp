#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

//#define LOCAL_BUILD 
#define zadacha "codecoder"

#define p_b push_back
#define m_p make_pair

using namespace std;

int n;

vector<int> v1, v2;  //v1[i] = на i-ом месте находится v1[i]
vector<int> ri1, ri2;
vector<int> ans;
vector<int> used;

void preload() {
	vector<pair<int, int> > r1, r2;
	for (int i = 0; i < n; ++i) {
		int i1, i2;
		cin >> i1 >> i2;
		r1.p_b(m_p(i1, i));
		r2.p_b(m_p(i2, i));
	}

	sort(r1.begin(), r1.end());
	sort(r2.begin(), r2.end());

	ri1.resize(n);
	ri2.resize(n);

	for (int i = 0; i < n; ++i) {
		v1.p_b(r1[i].second);
		v2.p_b(r2[i].second);
		ri1[r1[i].second] = i;
		ri2[r2[i].second] = i;
	}
}

void hardwork() {
	ans.resize(n);
	used.resize(n);

	queue<int> q;



	for (int i1 = n, i2 = n; i1 > 0 && i2 > 0; /*--i1, --i2*/) {
		--i1;
		q.push(v1[i1]);
		//int i1, i2;
		//i1 = n - 1;
		//i2 = n;
		used[v1[i1]] = 1;
		ans[v1[i1]] = i1;
		while (!q.empty()) {
			int cur = q.front();
#ifdef LOCAL_BUILD
			cout << "q: " << cur << ": ";
#endif
			q.pop();
			for (int j1 = i1 - 1; j1 >= ri1[cur]; --j1) { //check inf cycle
				int cur1 = v1[j1];
#ifdef LOCAL_BUILD
				cout << cur1 << " ";
#endif
				if (used[cur1] == 0) {
					used[cur1] = 1;
					q.push(cur1);
					ans[cur1] = ans[cur];
				}
			}
#ifdef LOCAL_BUILD
			cout << endl;
#endif

			for (int j2 = i2 - 1; j2 >= ri2[cur]; --j2) { //check inf cycle
				int cur1 = v2[j2];
				if (used[cur1] == 0) {
					used[cur1] = 1;
					q.push(cur1);
					ans[cur1] = ans[cur];
				}
			}

			i1 = min(i1, ri1[cur]);
			i2 = min(i2, ri2[cur]);

		}

	}




}




int main() {
	ios_base::sync_with_stdio(0);

#ifdef LOCAL_BUILD
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(zadacha".in", "r", stdin);
	freopen(zadacha".out", "w", stdout);
#endif

	cin >> n;
	preload();
	hardwork();
	
	for (int i = 0; i < n; ++i)
		cout << ans[i] << endl;

	return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5;

int a[N], b[N], c[N], suff[N], ans[N];
bool done[N];

int main() {
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n;
	cin >> n;
	vector< pair<int, int> > v1, v2;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		v1.push_back(make_pair(a[i], i));
		v2.push_back(make_pair(b[i], i));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int bestA = -1, bestAidx = -1;
    for (int i = 0; i < n; i++) {
    	int idx = v2[i].second;
    	if (a[idx] > bestA) {
    		bestA = a[idx];
    		bestAidx = idx;
    	}
    	c[idx] = bestAidx;
    }
    bestA = -1, bestAidx = -1;
    for (int i = 0; i < n; i++) {
    	int idx = v1[i].second;
    	if (a[c[idx]] > bestA) {
    		bestA = a[c[idx]];
    		bestAidx = c[idx];
        }
        suff[i] = bestAidx;
    }
    for (int i = n - 1; i >= 0; i--) {
    	int idx = v1[i].second;
    	ans[idx] = i;
    	if (done[suff[i]])
    		ans[idx] = ans[suff[i]];
    	done[idx] = 1;
    }
    for (int i = 0; i < n; i++)
    	cout << ans[i] << endl;
    return 0;
}
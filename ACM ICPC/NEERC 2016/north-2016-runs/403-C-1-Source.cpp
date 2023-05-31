#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("codecoder.in");
ofstream out("codecoder.out");
vector< pair<int, int> > v1, v2;
int lower(int k, int val);
int binSearch(int l, int r, int val);
int leftt = 0;

int main()
{
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	int n;
	in >> n;
	if (n == 1) {
		out << 0; return 0;
	}
	v1.resize(n); v2.resize(n);
	vector<int> ans(n, 0);
	int a, b;
	for (int i = 0; i < n; i++) {
		in >> a >> b;
		v1[i].first = min(a, b);
		v2[i].first = max(a, b);
		v1[i].second = v2[i].second = i;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end()); // самый большой рейтинг
	int rightt = n - 1, val;
	for (int i = 0; i < n; i++) {
		val = v1[i].first+1;
		a = binSearch(leftt, rightt, val);
		if (a != -1) {
			for (int j = a; j < n; j++)
				if (v1[i].second != v2[j].second)
					ans[v2[j].second]++;
		}
	}
	for (int i = 0; i < n; i++) {
		out << ans[i] << endl;
	}
	return 0;
}

int binSearch(int l, int r, int val) {
	int a = l, b = r, i = r;
	if (v2[r].first < val) return -1;
    while (a != i) {
	    if (v2[i].first >= val)
			b = i;
		else
			a = i;
		i = (a + b) / 2;
    }
	if (v2[i].first < val) {
		leftt = i + 1;
        return i + 1;
	}
	else {
		leftt = i;
		return i;
	}
}
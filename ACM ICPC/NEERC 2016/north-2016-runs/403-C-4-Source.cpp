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
	vector< pair<int, int> > people(n);
	vector<int> ans(n,0);
	int a, b;
	for (int i = 0; i < n; i++) {
		in >> a >> b;
		people[i].first = a;
		people[i].second = b;
		v1[i].first = min(a, b);
		v2[i].first = max(a, b);
		v1[i].second = v2[i].second = i;
	}
	sort(v1.rbegin(), v1.rend());
	sort(v2.rbegin(), v2.rend()); // самый большой рейтинг
	int rightt = n - 1, val, binAns;
	for (int i = 0; i < n; i++) {
		binAns = binSearch(0, n - 1, v2[i].first - 1);
		if (binAns == -1) ans[v2[i].second] = 0;
		else if (people[v2[i].second].first == people[v2[i].second].second)
			    ans[v2[i].second] = n - binAns;
		    else ans[v2[i].second] = n - binAns - 1;
	}
	for (int i = 0; i < n; i++)
		out << ans[i] << endl;
	return 0;
}

int binSearch(int l, int r, int val) {
	int a = l, b = r, i = r;
    while (a != i) {
	    if (v1[i].first <= val)
			b = i;
		else
			a = i;
		i = (a + b) / 2;
    }
	if (v1[i].first > val) {
        return i + 1;
	}
	else {
		return i;
	}
}
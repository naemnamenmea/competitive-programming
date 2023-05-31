#include<iostream>
#include <algorithm>;
#include <vector>
using namespace std;
int x, y, it, ansA[1000001], ansB[1000001], ans[1000006], val, num, cntA[1000005], cntB[1000005];
vector<pair<int, int> > a;
vector<pair<int, int> > b;
vector<pair<pair<int, int>, int > > s;
int main()
{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		a.push_back(make_pair(x, i));
		b.push_back(make_pair(y, i));
		s.push_back(make_pair(make_pair(x, y), i));
		cntA[x]++;
		cntB[y]++;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(s.begin(), s.end());
	for (int i = 0; i < n; i++){
		num = a[i].second;
		val = a[i].first;
		it = lower_bound(a.begin(), a.end(), make_pair(val, 0))-a.begin();
		ansA[num] = max(it - cntA[val] + 1,0);
		ans[num] += ansA[num];
		num = b[i].second;
		val = b[i].first;
		it = lower_bound(b.begin(), b.end(), make_pair(val, 0)) - b.begin();
		ansB[num] =max( it - cntB[val] + 1,0);
		ans[num] += ansB[num];
	}
	int l, r, num1, x1, y1, m;
	for (int i = 0; i < n; i++){
		x = s[i].first.first;
		y = s[i].first.second;
		num = s[i].second;
		l = 0;
		r = n - 1;
		while (l < r){
			m = (l + r + 1) / 2;
			x1 = s[m].first.first;
			y1 = s[m].first.second;
			num1 = s[m].second;
			if (x > x1 && y>y1) l = m; else r = m - 1;
		}
		//cout <<num<<" " << r <<" "<<ans[num]<< endl;
		if (s[r].first.first<x && s[r].first.second<y) ans[num]=ans[num]-r-1;
	}
	for (int i = 0; i < n; i++){
		cout << ans[i] << endl;
	}
	return 0;
	//system("PAUSE");
}

#include <iostream>
#include <vector>
using namespace std;

struct tri{
	int ans;
	bool vert;
	int del;
	tri(){ ans = -1; }
	tri(int a, bool b, int c){ ans = a; vert = b; del = c; }
};
vector <vector <tri> > d;
void count(){
	int mxw = 62, mxh = 62;
	d.resize(mxw + 1, vector <tri>(mxh + 1));
	for (int i = 1; i <= mxw; i++)
		for (int j = 1; j <= mxh; j++)
			if (i == j){
		d[i][j].ans = 1;
			}
			else{
				for (int k = 1; k < j; k++)
					if (d[i][j].ans == -1 || d[i][j].ans > d[i][k].ans + d[i][j - k].ans){
					d[i][j].ans = d[i][k].ans + d[i][j - k].ans;
					d[i][j].vert = false;
					d[i][j].del = k;
					}
				for (int k = 1; k < i; k++)
					if (d[i][j].ans == -1 || d[i][j].ans > d[k][j].ans + d[i - k][j].ans){
					d[i][j].ans = d[k][j].ans + d[i - k][j].ans;
					d[i][j].vert = true;
					d[i][j].del = k;
					}
			}
}
struct tr{
	int x, y, l;
	tr(int x, int y, int l) :x(x), y(y), l(l){}
};
vector <tr> ans;

void f(int x, int y, int w, int h){
	if (w == x || h == y)
		return;
	if (w - x == h - y){
		ans.push_back(tr(x, y, w - x));
		return;
	}
	tri t = d[w - x][h - y];
	if (t.vert){
		f(x, y, x + t.del, h);
		f(x + t.del, y, w, h);
	}
	else{
		f(x, y, w, y + t.del);
		f(x, y + t.del, w, h);
	}
}

int main(){
	freopen("hard.in", "r", stdin);
	freopen("hard.out", "w", stdout);
	count();
	int t; cin >> t;
	while (t--){
		int w, h;
		cin >> w >> h;
		f(0, 0, w, h);
		while (ans.size() != d[w][h].ans);
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].x << ' ' << ans[i].y << ' ' << ans[i].l << endl;
		ans.clear();
	}
	return 0;
}
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <map>
#include <set>

using namespace std;

struct coder{
	int a, b, num;
};

struct coderInd {
	int i, j;
};

bool comp1(coder a, coder b) {
	if (a.a < b.a)
		return true;
	else if (a.a == b.a) {
		if (a.b < b.b)
			return true;
		return false;
	}
	return false;
}

bool comp2(coder a, coder b) {
	if (a.b < b.b)
		return true;
	else if (a.b == b.b) {
		if (a.a < b.a)
			return true;
		return false;
	}
	return false;
}

void main() {
	ifstream cin("codecoder.in");
	ofstream cout("codecoder.out");
	int n;
	cin >> n;
	vector<coder> coders1(n), 
        coders2(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		coders1[i].a = a;
		coders1[i].b = b;
		coders1[i].num = i;
		coders2[i] = coders1[i];
	}
	vector<coderInd> inds(n);

	sort(coders1.begin(), coders1.end(), comp1);
	sort(coders2.begin(), coders2.end(), comp2);

	for (int i = 0; i < n; i++)
		inds[coders1[i].num].i = i;
	for (int i = 0; i < n; i++)
		inds[coders2[i].num].j = i;

	int mx1 = 0;
	int mx2 = -1;

	vector<int> ans(n, 0);
	set<int> observed;
	set<int> to1, to2, obing;
	to1.insert(coders1[0].num);
	while (mx1 < n - 1 && mx2 < n - 1) {
		while (to1.size() != 0 || to2.size() != 0) {
			if (to1.size() != 0) {
				int v = *to1.begin();
				if (mx1 < inds[v].i)
				    mx1 = inds[v].i;
				to1.erase(to1.begin());
				obing.insert(v);
				if (inds[v].j > mx2) {
					for (int i = mx2 + 1; i <= inds[v].j; i++) {
						if (observed.find(coders2[i].num) == observed.end() &&
							obing.find(coders2[i].num) == obing.end()) {
							to2.insert(coders2[i].num);
						}
					}
					mx2 = inds[v].j;
				}
			}
			if (to2.size() != 0) {
				int v = *to2.begin();
				if (mx2 < inds[v].j)
					mx2 = inds[v].j;
				to2.erase(to2.begin());
				obing.insert(v);
				if (inds[v].i > mx1) {
					for (int i = mx1 + 1; i <= inds[v].i; i++) {
						if (observed.find(coders1[i].num) == observed.end() &&
							obing.find(coders1[i].num) == obing.end()) {
							to1.insert(coders1[i].num);
						}
					}
					mx1 = inds[v].i;
				}
			}
			int answ = obing.size() + observed.size() - 1;
			for (set<int>::iterator it = obing.begin(); it != obing.end(); it++) {
				ans[*it] = answ;
				observed.insert(*it);
			}
			obing.clear();
			if (mx1 != n - 1)
			    to1.insert(coders1[mx1 + 1].num);
		}
	}
	for (int i = 0; i < n; i++) {
		if (observed.find(i) == observed.end())
			ans[i] = n - 1;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;



}
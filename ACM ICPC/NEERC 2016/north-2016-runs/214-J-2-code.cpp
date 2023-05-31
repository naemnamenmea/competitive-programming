#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back


int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	freopen("java2016.in", "rt", stdin);
	freopen("java2016.out", "wt", stdout);

	int val = 0;
	cin >> val;
	char stop = 'a' + 20;
	printf("a = ? max ?\n");
	for (char c = 'b'; c <= stop; c++) {
		printf("%c = %c max %c\n", c, c - 1, c - 1);
	}
	char c1 = stop + 1;
	printf("%c = %c / %c\n", c1, stop, stop);
	char c2 = c1 + 1;
	printf("%c = %c + %c\n", c2, c1, c1);
	string res;
	res += c1;
	if (val == 0) {
		cout << "q - q" << endl;
		return 0;
	}
	vector<int> wtf;
	while (val > 0) {
		wtf.pb(val & 1);
		val /= 2;
	}
	for (int i = sz(wtf) - 2; i >= 0; i--) {
		res = "(" + res + " * " + c2 + ")";
		if (wtf[i]) res = "(" + res + " + " + c1 + ")";
	}
	cout << res << endl;

	int omg = 0;
	for (int i = 0; i < sz(res); i++) {
		if (res[i] != ' ') omg++;

	}
	//cout << omg << endl;




	return 0;
}
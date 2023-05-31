#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<map>
#include<string>
#include<queue>
#define ll long long int
using namespace std;


void sol(){
	int n;
	cin >> n;
	if( n == 0) {
		cout << "?/?/?";
		return ;
	}
	vector< pair<pair<int, char>, string> > g;
	g.push_back(make_pair(make_pair(1, 'a'), "a = ((? max ?) max (? max ?)) / ( ? max ?)"));
	g.push_back(make_pair(make_pair(2, 'b'), "b = a + a"));
	g.push_back(make_pair(make_pair(4, 'c'), "c = b + b"));
	g.push_back(make_pair(make_pair(8, 'd'), "d = c + c"));
	g.push_back(make_pair(make_pair(16, 'e'), "e = d + d"));
	g.push_back(make_pair(make_pair(32, 'f'), "f = e + e"));
	g.push_back(make_pair(make_pair(64, 'g'), "g = f + f"));
	g.push_back(make_pair(make_pair(128, 'h'), "h = g + g"));
	vector < char > rz;
	cout << g[0].second << "\n";
	for(int i = 0; i <= 8; i++) {
		if( (1 << i) & n ) {
			rz.push_back(g[i].first.second);
			if( i != 0) {
				cout << g[i].second << "\n";
			}
		}
	}
	int sz = rz.size();
	for(int i = 0; i < sz; i++) {
		if( i + 1 == sz) {
			cout << rz[i];
		} else {
			cout << rz[i] << "+";
		}
	}
}


int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("java2016.in", "r", stdin);
	freopen("java2016.out", "w", stdout);
#endif
	sol();
}
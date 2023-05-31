#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int a = 0;
	int b = 0;
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	cin >> a >> b;
	pair<int, int> f, s;
	cin >> f.first >> f.second;
	cin >> s.first >> s.second;
	if (f.first == s.first)
	{
		cout << "0" << " " << f.second << " " << a << " " << s.second;
	}
	else{
		if (f.second == s.second) {
			cout << f.first << " " << "0" << " " << s.first << " " << b;
		}
		else {
			cout << "0" << " " << f.second << " " << a << " " << s.second;
		}
	}
	return 0;
}
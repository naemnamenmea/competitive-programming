#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
#ifdef _DEBUG

#else
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
#endif
	vector <int> m = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 1; i < 12; i++)
		m[i] += m[i - 1];
	int a, b, c;
	cin >> a >> b >> c;
	int s;
	if (b != 1)
		s = a + m[b - 2] + c * 365;
	else
		s = a + c * 365;
	int gr = 18 * 365;
	int n;
	cin >> n;
	int gr1 = 1000*365;
	int x = -2;
	for (int i = 0; i < n; i++){
		int a1, b1, c1;
		cin >> a1 >> b1 >> c1;
		int s1;
		if (b != 1)
			s1 = a1 + m[b1 - 1] + c1 * 365;
		else
			s1 = a1 + c1 * 365;
		if (s - s1 >= gr)
			if (s - s1 < gr1){
			gr1 = s - s1;
			x = i;
			}
	}
	cout << x+1;
	return 0;
}
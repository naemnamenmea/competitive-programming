#include<iostream>
#include<math.h>
#include <vector>
using namespace std;


int main()
{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	int k = -1;
	int a, b, c, g,g2=-1,g1;
	cin >> a >> b >> c;
	g = (c - 18) * 10000 + b * 100 + a;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b >> c;
		g1 = c * 10000 + b * 100 + a;
		if (g >= g1 && (g2==-1 || g2<g1)){
			g2 = g1;
			k = i;
		}
	}
	if (k != -1)
		cout << k+1;
	else
		cout << -1;
	return 0;
}
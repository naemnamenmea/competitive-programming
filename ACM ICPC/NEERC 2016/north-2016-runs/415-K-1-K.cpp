#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>

using namespace std;
typedef long long ll;
int main(){
		freopen("king.in", "r", stdin);
		freopen("king.out", "w", stdout);
		int d, m, y;
		cin >> d >> m >> y;
		int n;
		cin >> n;
		int ind = -1;
		int ad = -1, ay = -1, am = -1;
		for (int i = 0; i < n; i++)
		{
			int cd, cm, cy;
			cin >> cd >> cm >> cy;
			if ((y - cy > 18) || (y - cy == 18 && (cm < m || (cm == m && cd <= d))))
			{
				if (cy > ay || (cy == ay && (cm > am || (cm == am && cd >= ad)) ))
				{
					ad = cd;
					ay = cy;
					am = cm;
					ind = i + 1;
				}
			}

		}
		cout << ind;

	return 0;
}


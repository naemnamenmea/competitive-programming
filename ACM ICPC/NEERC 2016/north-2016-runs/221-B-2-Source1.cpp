#pragma comment(linker, "/STACK:100000000")

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define mp make_pair

typedef pair<int, int> pi;

int main(){
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("boysgirls.in", "r", stdin);
	freopen("boysgirls.out", "w", stdout);
#endif
	int n, x, y;
	cin >> n >> x >> y;
	if ((x + y - n) % 2 != 0){
		cout << "Impossible";
		return 0;
	}
	int s = (x + y - n) / 2;
	int k = (x + n - y) / 2;
	int l = (y + n - x) / 2;
	if (x == 0){
		if (y != n){
			cout << "Impossible";
			return 0;
		}
		for (int i = 0; i < n; i++)
			cout << "G";
		return 0;
	}
	if (y == 0){
		if (x != n){
			cout << "Impossible";
			return 0;
		}
		for (int i = 0; i < n; i++)
			cout << "B";
		return 0;
	}
	if (s <= 0){
		cout << "Impossible";
		return 0;
	}
	for (int a = 0; a <= s; a++){
		int b = s - a;
		if (min(k - a, l - b) >= max(a, b)){
			int p = min(k - a, l - b);
			int s1 = p - a, s2 = p - b;
			for (int i = 0; i < p; i++){
				if (s1 > 0){
					cout << "B";
					s1--;
				}
				else
					if (i < p - 1){
					cout << "BB";
					}
					else
						for (int j = 0; j < k - p +1; j++)
							cout << "B";
				if (s2 > 0){
					cout << "G";
					s2--;
				}
				else
					if (i < p - 1)
						cout << "GG";
					else
						for (int j = 0; j < l - p + 1; j++)
							cout << "G";
			}
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}
#pragma comment(linker, "/STACK:100000000")

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define mp make_pair
#define fi(a, b) for (int i = a; i <= b; ++i)
#define fj(a, b) for (int j = a; j <= b; ++j)
#define sqr(x) (x) * (x - 1) / 2

typedef pair<long long, long long> pi;

int main(){
#ifdef _DEBUG
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	freopen("java2016.in", "r", stdin);
	freopen("java2016.out", "w", stdout);
#endif
	int n;
	cin >> n;
	cout << "z = ? max ?\na = z / z\n";
		char x = 'a';
		for (int i = 1; i <= 7; i++){
			x++;
			cout << x << " = " << char(x - 1) << "+" << char(x - 1) << endl;
		}
		vector <int> a;
		while (n > 0){
			a.push_back(n % 2);
			n /= 2;
		}
		cout << "i = a / b\n";
		int sh = 0;
		for (int i = 0; i < a.size(); i++){
			if (a[i] == 1){
				sh++;
				cout << char('i'+sh) << " = " << char('i'+sh-1) <<" + " << char(i + 'a') << endl;
			}
		}
		cout << char('i'+sh);
	
	return 0;
}
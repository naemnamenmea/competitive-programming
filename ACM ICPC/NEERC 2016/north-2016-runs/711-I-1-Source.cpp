#include<iostream>
#include<math.h>
#include <vector>

using namespace std;

long long X[200001], Y[200001];

long long f(long long x1, long long y1, long long x2, long long y2){
	return abs(x1*y2 - x2*y1);
}

int main()
{
	freopen("integral.in", "r", stdin);
	freopen("integral.out", "w", stdout);
	int n, k = 0, sum=0;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> X[i] >> Y[i];
		if (i>1)
			sum ^= f(X[i] - X[0], Y[i] - Y[0], X[i - 1] - X[0], Y[i - 1] - Y[0]) & 1;
	}
	if (sum==1){
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++){
		sum = 0;
		for (int j = i+2; j < n+i-1; j++){
			if (i != (j%n) && i != (j%n) - 1 && i != (j%n) + 1){
				sum ^= f(X[j%n] - X[i], Y[j%n] - Y[i], X[((j%n) - 1 + n) % n] - X[i], Y[((j%n) - 1 + n) % n] - Y[i]) & 1;
				if (sum == 0)
					ans++;
			}
		}
	}
	cout << (ans >> 1);
	return 0;
}
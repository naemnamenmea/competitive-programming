#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#include <cassert>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 2e5;

int a1[N], a2[N];
int s[N];

int sq(int c1, int v1, int c2, int v2, int c3, int v3) {
	c1 %= 2;
	c2 %= 2;
	c3 %= 2;
	
	v1 %= 2;
	v2 %= 2;
	v3 %= 2;
	
	int ans = (c2 - c1) * (v3 - v1)
	        - (c3 - c1) * (v2 - v1);
	return ((ans % 2) + 2) % 2;
}


int main() {
#ifdef KOBRA
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("integral.in", "r", stdin);
	freopen("integral.out", "w", stdout);
#endif // KOBRA
	int q, w, e, r, t, c, v;
	scanf("%d", &q);
	for (w = 0; w < q; w++) {
		scanf("%d %d", &a1[w], &a2[w]);
	}
	
	ll ans = 0;
	
	for (int c1 = 0; c1 < 2; c1++) {
		for (int c2 = 0; c2 < 2; c2++) {
			for (w = 0; w < q; w++) {
				e = (w + 1) % q;
				
				s[w] = sq(c1, c2, a1[w], a2[w], a1[e], a2[e]);
			}
			
			int interest = 0;
			int sum = 0;
			
//			for (w = 0; w < q; w++) {
//				cout << s[w] << " ";
//			}
//			cout << "\n";
			
			
			for (int w = 0; w < q; w++) {
				if (sum == 0) {
					interest++;
				}
				sum = sum ^ s[w];
			}
			
//			cout << "interest " << interest << "\n";
			
			if (sum == 1) {
				cout << 0;
				return 0;
			}
			
			sum = 0;
			
			for (w = 0; w < q; w++) {
				if (( (a1[w] - c1) % 2 == 0) && ( (a2[w] - c2) % 2 == 0)) {
//					cout << w << " " << sum << "  !!!\n";
//					
//					
					if (sum == 0) {
						ans += interest;
					} else {
						ans += q - interest;
					}
					ans -= 3;
				}
				
				sum = sum ^ s[w];
			}
			
			
//			cout << "\n";
		}
	}
	
//	cout << ans << "\n";
	
	assert(ans % 2 == 0);
	
	cout << ans / 2;
	
    return 0;
}

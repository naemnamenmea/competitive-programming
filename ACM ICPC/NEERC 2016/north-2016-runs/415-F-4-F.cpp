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
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	int W, H, w, h;
	cin >> W >> H >> w >> h;
	int ans1{}, ans2{};
	int ma, mi, MA, MI;
	ma = max(h, w);
	mi = min(h, w);
	MA = max(H, W);
	MI = min(H, W);
	if (ma > MA || mi > MI){
		cout << -1;
		return 0;
	}
	while (MA > ma){
		ans1++;
		MA += (MA % 2 == 1);
		MA >>= 1;
	}
	while (MI > mi){
		ans1++;
		MI += (MI % 2 == 1);
		MI >>= 1;
	}
	ma = max(h, w);
	mi = min(h, w);
	MA = max(H, W);
	MI = min(H, W);
	if (MI>=ma){
		while (MA > mi){
			ans2++;
			MA += (MA % 2 == 1);
			MA >>= 1;
		}
		while (MI > ma){
			ans2++;
			MI += (MI % 2 == 1);
			MI >>= 1;
		}
	}
	else{
		cout << ans1;
		return 0;
	}
	cout << min(ans1, ans2) << endl;
	return 0;
}


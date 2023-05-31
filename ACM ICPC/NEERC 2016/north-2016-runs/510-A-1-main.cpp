#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back

#ifdef local
//	#define files
	#define task "file"
#else
	#define files
	#define task "anniversary"
#endif

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

#ifdef files
	freopen(task".in", "r", stdin);	
	freopen(task".out", "w", stdout);	
#endif
        int w, h, ax, ay, bx, by;
	cin >> w >> h >> ax >> ay >> bx >> by;
	if (ax != bx)
	{
	 	cout << ax << " 0 " << bx << " " << h << "\n";
	}
	else
		cout << "0 " << ay  << " " << w << " " << by << "\n";
	

	return 0;
}
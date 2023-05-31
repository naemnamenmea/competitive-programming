#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back

#ifdef local
	#define files
	#define task "file"
#else
	#define files
	#define task "folding"
#endif


map<pair<int, int>, int> dp;
int wt, ht;

int inf = 10000000;
int foo(int n, int want)
{
    if(n < want)
    	return inf;
    int t = 0;
    while( n != 1 && (n + 1) / 2 >= want)
    {
    	t++;
    	n = (n + 1) / 2; 
    }
    if(n > want) t++;
    return t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

#ifdef files
	freopen(task".in", "r", stdin);	
	freopen(task".out", "w", stdout);	
#endif

	int w, h;
	cin >> w >> h;
	int t = w;
	w = max(w, h);
	h = min(t, h);
	
	cin >> wt >> ht;
	t = wt;
	wt = max(wt, ht);
	ht = min(t, ht);
	int res = min(foo(w, wt) + foo(h, ht), foo(w, ht) + foo(h, wt) );
	if( res >= inf)
		res = -1;
	cout << res;


	return 0;
}
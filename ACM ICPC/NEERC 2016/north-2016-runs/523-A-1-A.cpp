#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);++i)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long LL;
typedef pair<int,int> pii;

int main(){
	assert(freopen("anniversary.in","r",stdin));
	assert(freopen("anniversary.out","w",stdout));
	
	int w, h, ax, ay, bx, by;
	scanf("%d%d%d%d%d%d", &w, &h, &ax, &ay, &bx, &by);	
	if (ax != bx) {
		printf("%d %d %d %d\n", ax, 0, bx, h);
	}
	else {
		printf("%d %d %d %d\n", 0, ay, w, by);	
	}
	return 0;
}
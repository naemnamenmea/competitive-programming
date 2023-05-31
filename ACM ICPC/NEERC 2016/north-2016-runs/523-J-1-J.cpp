#define FNAME "java2016"

#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);++i)
#define forit(i,V) for(__typeof(V.begin()) i=V.begin();i!=V.end();++i)
#define fornr(i,N) for(int i=int(N)-1;i>=0;--i)
#define forab(i,a,b) for(int i=(a);i<int(b);++i)
#define all(V) (V).begin(),(V).end()
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define sz(V) (int)((V).size())

typedef long long LL;
typedef pair<int,int> pii;
typedef long double LD;
typedef vector<int> vi;

int main(){
	assert(freopen(FNAME".in","r",stdin));
	assert(freopen(FNAME".out","w",stdout));
	
	int c;
	scanf("%d", &c);	
	if (c == 0) {
		puts("?/?/?");
		return 0;
	}
	
	puts("a=?max?");
	int C = 17;
	forn (i, C) {
		printf("%c=%c max %c\n", 'a' + i + 1, 'a' + i, 'a' + i); 
	}
	char one = 'a' + C + 1;
	printf("%c=%c/%c\n", one, 'a' + C, 'a' + C); // 1
	printf("%c=%c+%c\n", one + 1, one, one); // 2 
	forab (i, one + 2, one + 8) {
		printf("%c=%c*%c\n", i, one + 1, i - 1); 
	}
	bool was = 0;
	forn (i, 8)
		if ((c >> i) & 1) {
			if (was)
				printf("+");
			printf("%c", one + i);
			was = 1;
		}
	puts("");
				
	return 0;
}
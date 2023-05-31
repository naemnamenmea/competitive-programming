#define FNAME "folding"

#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);++i)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long LL;
typedef pair<int,int> pii;

const int INF=1e6;

int Get(int a,int b){
	if(a<b)
		return INF;
	int ans=0;
	while(a>2*b)
		a=(a+1)/2, ++ans;
	if(a>b)
		++ans;
	return ans;
}

int main(){
	assert(freopen(FNAME".in","r",stdin));
	assert(freopen(FNAME".out","w",stdout));
	
	int w,h,W,H;
	scanf("%d%d%d%d",&W,&H,&w,&h);
	int k=min(Get(W,w)+Get(H,h),Get(W,h)+Get(H,w));
	printf("%d\n",k>=INF?-1:k);
	
	return 0;
}
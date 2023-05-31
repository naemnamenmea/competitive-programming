#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<map>
#include<string>
#include<queue>
#define ll long long int
using namespace std;


int n,pr[100007],ans[100007];
vector<int>p[100007];
vector<int>one(3);

void sol(){
	int i,a,b,l,r,m;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		one[0]=a;
		one[1]=b;
		one[2]=i;
		p[i]=one;

	}
	sort(p,p+n);
	reverse(p,p+n);
	pr[0]=p[0][1];
	for(i=1;i<n;i++){
		pr[i]=min(pr[i-1],p[i][1]);
	}
	for(i=0;i<n;i++){
		l=0;
		r=i;
		while(r-l>1){
			m=(l+r)/2;
			if(pr[m]<p[i][1]){
				r=m;
			}else{
				l=m;
			}
		}
		if(pr[l]<p[i][1]){
			r=l;
		}
		ans[p[i][2]]=n-r-1;
	}
	for(i=0;i<n;i++){
		printf("%d\n",ans[i]);
	}
}


int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
#endif
	sol();
}
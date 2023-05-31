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

int lench(int x1,int y1,int x2,int y2) {
	int chetnost;
	if(abs(x1-x2)%2==0&&abs(y1-y2)%2==0) chetnost=1;
	else chetnost=0;
	return chetnost;
}

void sol(){
	int n,i,j;
	scanf("%d",&n);
	vector<int> x(n+1),y(n+1),ans(n+1),e(n+1),sum(n+1);
	for(i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]);
	x[n]=x[0];
	y[n]=y[0];

	for(i=0;i<n;i++) {
		if(abs(x[i]-x[i+1])%2==0&&abs(y[i]-y[i+1])%2==0) e[i]=1;
		else e[i]=0;
	}
	sum[0]=e[0];
	for(i=1;i<n;i++) sum[i]=(sum[i-1]+e[i])%2;
	ans[0]=0;
	for(i=2;i<n-1;i++) {
		int chetnost;
		if(abs(x[i]-x[0])%2==0&&abs(y[i]-y[0])%2==0) chetnost=1;
		else chetnost=0;
		if((i+1+sum[i-1])%2==chetnost&&(1000000+sum[n-1]-sum[i-1]+n-(i-1))%2==chetnost) ans[0]++;
	}

	for(i=1;i<n;i++) {
		int prev=ans[i-1];
		int chetnost=lench(x[i-1],y[i-1],x[i+1],y[i+1]);
		int eback=lench(x[i-1],y[i-1],x[i],y[i]),efor=lench(x[i+1],y[i+1],x[i],y[i]);
		if((eback+efor+3)%2==chetnost&&(1000000+sum[n-1]-eback-efor+n-1)%2==chetnost) prev--;
		if(eback==0) ans[i]=prev;
		else ans[i]=n-4-prev;
		if(i==1) {
			int ch=lench(x[1],y[1],x[n-1],y[n-1]);
			int ebackback=lench(x[0],y[0],x[n-1],y[n-1]);
			if((eback+ebackback+3)%2==ch&&(1000000+sum[n-1]-eback-ebackback+n-1)%2==chetnost) ans[i]++;
		}
		else {
			int ch=lench(x[i-2],y[i-2],x[i],y[i]);
			int eback=lench(x[i-1],y[i-1],x[i],y[i]),ebackback=lench(x[i-2],y[i-2],x[i],y[i]);
			if((eback+ebackback+3)%2==ch&&(1000000+sum[n-1]-eback-ebackback+n-1)%2==ch) ans[i]++;
		}
	}
	ll S=0;
	for(i=0;i<n;i++) S+=(ll)ans[i];
	printf("%I64d",S/2);

}


int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("integral.in", "r", stdin);
	freopen("integral.out", "w", stdout);
#endif
	sol();
}
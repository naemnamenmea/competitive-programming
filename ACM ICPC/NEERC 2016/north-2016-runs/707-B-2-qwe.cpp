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


int n,G,B,m[100007];

int check(){
	int i,a=0,b=0;
	m[n]=m[0];
	m[n+1]=m[1];
	for(i=1;i<=n;i++){
		if(m[i-1]==0&&m[i+1]==0){
			a++;
		}else if(m[i-1]==1&&m[i+1]==1){
			b++;
		}else{
			a++;
			b++;
		}
	}
	if(a==B&&b==G){
		return 1;
	}else{
		return 0;
	}
}

void sol(){
	int i,j,cf,b,g;
	scanf("%d%d%d",&n,&B,&G);
	cf=B+G-n;
	b=B;
	g=G;
	for(i=0;i<n;i++){
		if(cf>0){
			cf--;
			b--;
			g--;
			m[i]=1;
			m[i+1]=0;
			i++;
		}else{
			if(b>g){
				b--;
				m[i]=0;
			}else{
				g--;
				m[i]=1;
			}
		}
	}
	if(check()==1){
		for(i=0;i<n;i++){
			if(m[i]==0)printf("B");
			else printf("G");
		}
	}else{
		printf("Impossible");
	}


}


int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("boysgirls.in", "r", stdin);
	freopen("boysgirls.out", "w", stdout);
#endif
	sol();
}
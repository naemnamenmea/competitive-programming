#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<map>
#include<string>
#define ll long long int
using namespace std;


void sol(){
	int w,h,a1,a2,b1,b2;
	scanf("%d%d%d%d%d%d",&w,&h,&a1,&a2,&b1,&b2);
	if(abs(a1-b1)>1) {
		printf("%d %d %d %d",(a1+b1)/2,0,(a1+b1)/2,h);
		return;
	}
	if(abs(a2-b2)>1) {
		printf("%d %d %d %d",0,(a2+b2)/2,w,(a2+b2)/2);
		return;
	}
	if(a2==b2) {
		printf("%d %d %d %d",a1,0,b1,h);
	}
	else {
		printf("%d %d %d %d",0,a2,w,b2);
	}

}


int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
#endif
	sol();
}
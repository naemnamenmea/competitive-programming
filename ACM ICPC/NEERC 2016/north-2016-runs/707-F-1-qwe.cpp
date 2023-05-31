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


map<pair<int,int>,int>mp;
queue<pair<int,int>>q;

void add(int x,int y,int h){
	int a,b;
	a=x;
	b=y;
	if(a<b)swap(a,b);
	if(mp[make_pair(a,b)]==0){
		q.push(make_pair(a,b));
		mp[make_pair(a,b)]=h;
	}
}

void sol(){
	int W,H,w,h,a,b;
	scanf("%d%d%d%d",&W,&H,&w,&h);
	if(w<h)swap(w,h);
	if(W<H)swap(W,H);
	q.push(make_pair(W,H));
	mp[make_pair(W,H)]=1;
	while(q.size()>0){
		a=q.front().first;
		b=q.front().second;
		q.pop();
		if(a==w&&b==h){
			printf("%d",mp[make_pair(a,b)]-1);
			return;
		}else if(a>=w&&b>=h){
			add(max(h,(a+1)/2),b,mp[make_pair(a,b)]+1);
			add(a,max(h,(b+1)/2),mp[make_pair(a,b)]+1);
			add(max(w,(a+1)/2),b,mp[make_pair(a,b)]+1);
			add(a,max(w,(b+1)/2),mp[make_pair(a,b)]+1);
		}	
	}
	printf("-1");
}


int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
#endif
	sol();
}
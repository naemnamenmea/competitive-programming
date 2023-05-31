#include<stdio.h>
#include<iostream>
using namespace std;
int min(int a,int b)
{
	return (a<b?a:b);
	}
int main()
{
	int W,H,w,h;
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	
	scanf("%i%i%i%i",&W,&H,&w,&h);
	if(W<H)
	{
		int t = W;
		W = H;
		H = t;
   	}
   	if(w<h)
	{
		int t = w;
		w = h;
		h = t;
   	}
   	int res=0;
   	int can=1;
   	if(w>W || h>H)
   	{
   		printf("-1\n");
   		return 0;
   	}	
   	while(true)
   	{
   		if(w == W)
   			break;
   		W-=min(W/2,W-w);
    	res++;
	}
   	while(true)
   	{
   		
   		if(h==H)
   			break;
    	H-=min(H/2,H-h);
    	res++;
	}
   	printf("%i\n",res);
   							
	
	return 0;
}
   						


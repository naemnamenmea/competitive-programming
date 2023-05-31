#include<stdio.h>
#include<iostream>
using namespace std;
#define INF 1000000
int min(int a,int b)
{
	return (a<b?a:b);
}
int f(int H,int W,int w,int h)
{
  	if(w>W || h>H)
		return INF;
	
	int c = 0;

	if(W!=w)
	{
		W -= min(W/2,W-w);
		c++;
	}
	if(H!=h)
	{
		H -= min(H/2,H-h);
		c++;
	}	
	
	if((w == W && h == H ) || (w == H && h == W))
		return c;
	else
		return  c + min(f(W,H,w,h),f(W,H,h,w));
}
int main()
{
	int W,H,w,h;
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	scanf("%i%i%i%i",&W,&H,&w,&h);
    
    int res = min(f(W,H,w,h), f(W,H,h,w));     	
   	printf("%i\n",(res>=INF?-1:res));
   							
	
	return 0;
}
   						


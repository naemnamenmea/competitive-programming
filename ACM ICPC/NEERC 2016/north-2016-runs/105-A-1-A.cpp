#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	freopen("anniversary.in","r",stdin);
	freopen("anniversary.out","w",stdout);
	
	int w, h;
	int cx1,cy1,cx2,cy2;
	cin >> w >> h >> cx1 >> cy1 >> cx2 >> cy2;

	if(cx1 == cx2){
		cout << 0 << " " << cy1 << " " << w << " " << cy2;
		return 0;
	}

	cout << cx1 << " " << 0 << " " << cx2 << " " << h;

	return 0;
}
   						


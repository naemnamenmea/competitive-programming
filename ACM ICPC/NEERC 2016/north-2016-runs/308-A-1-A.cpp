#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main(){
	assert(freopen("anniversary.in", "r", stdin));
	assert(freopen("anniversary.out", "w+", stdout));
	int w, h;
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> w >> h;
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;

	if (ax == bx){
		std::cout << 0 << " " << ay << " " << w  << " " << by;
	}
	else{
		std::cout << ax << " " << 0 << " " << bx << " " << h;
	}


	return 0;
}
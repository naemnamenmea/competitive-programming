#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>


typedef long long ll;
using namespace std;

#define mp(x, y)  std::make_pair(x, y)
#define MAX(x, y) (((x) > (y)) ? (x) : (y))



int main(){
	assert(freopen("java2016.in", "r", stdin));
	assert(freopen("java2016.out", "w+", stdout));
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int num;
	scanf("%d", &num);

	if (num == 0){
		printf("? /?/ ?");
		return 0;
	}
	
	char cur = 'a';

	printf("a=? max ?\n");
	for (int i = 0; i < 17; ++i){
		char next = cur + 1;
		printf("%c=%c max %c\n", next,cur,cur);
		cur = next;
	}
	char variable = cur;
	char digit[10];
	cur++;
	digit[0] = cur;

	printf("%c=(%c max %c) / %c\n", digit[0], variable, variable, variable);
	int power[10];
	power[0] = 1;
	for (int i = 1; i < 9; ++i){
		power[i] = power[i - 1] * 2;
	}


	for (int i = 1; i < 8; ++i){
		char next = cur + 1;
		printf("%c=%c + %c", next, cur, cur);
		//printf(";%d;%d", i, power[i]);
		printf("\n");
		digit[i] = next;
		cur = next;
	}

	

	bool was = false;
	int i = 7;
	while (num > 0){
		if (num >= power[i]){
			num -= power[i];
			if (was){
				printf("+");
			}
			printf("%c", digit[i]);
			was = true;
		}
		--i;
	}

	return 0;
}
	
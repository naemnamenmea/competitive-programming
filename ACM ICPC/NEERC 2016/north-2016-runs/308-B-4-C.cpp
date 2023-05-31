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

void printBoys(const int n){
	for (int i = 0; i < n; ++i){
		printf("B");
	}
}

void printGirls(const int n){
	for (int i = 0; i < n; ++i){
		printf("G");
	}
}

int main(){
	assert(freopen("boysgirls.in", "r", stdin));
	assert(freopen("boysgirls.out", "w+", stdout));
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int n, x, y;
	cin >> n >> x >> y;


	
	//if (x + y <= n + 4){
		if (x + y == n){
			if ((x > 0) && (y ==0)){
				printBoys(x);
				return 0;
			}
			else if ((y > 0) && (x == 0)){
				printGirls(y);
				return 0;
			}
			else{
				printf("Impossible");
				return 0;
			}
		}
		else if (x + y == n + 1){
			printf("Impossible");
			return 0;
		}
		else if (x + y == n + 2){
			if ((x > 2) && (y > 2)){
				for (int i = 0; i < min(x, y)-1; i++){
					printf("BG");
				}
				if (x > y){
					for (int i = 0; i < x-y; i++){
						printf("B");
					}
				}
				else{
					for (int i = 0; i < y-x; i++){
						printf("G");
					}
				}
				// printf("Impossible");
				return 0;
			}
			else if ((x <= 1) || (y <= 1)){
				printf("Impossible");
				return 0;
			}
			else if ((x == 2) || (y == 2)){
				if (x == 2){
					printBoys(1);
					printGirls(n - 1);
				}
				else{
					printBoys(n - 1);
					printGirls( 1);
				}
				return 0;
			}
		}
		else if (x + y == n + 3){
			printf("Impossible");
			return 0;
		}
		else{
			int k = n + 2 - x;
			int m = 2 + k - y;
			if (m % 4 == 0){
				for (int i= 0; i < m / 4; ++i){
					printf("BBGG");
				}
			}
			else if (m % 4 == 2){
				printf("B");
				for (int i = 0; i < m / 4; ++i){
					printf("BBGG");
				}
				printf("G");
			}
			else{
				//assert(2 == 3);
				printf("Impossible");
				return 0;
			}
			for (int i = 0; i < k; ++i){
				printf("G");
			}
			for (int i = 0; i < n-k-m; ++i){
				printf("B");
			}
			return 0;
		}
		
	//}
	printf("Impossible");
	return 0;
	return 0;
}
	
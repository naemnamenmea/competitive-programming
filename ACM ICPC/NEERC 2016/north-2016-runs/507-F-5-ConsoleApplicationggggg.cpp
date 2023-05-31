#include <fstream>
#include <algorithm>
using namespace std;

long long  del(long long a, long long b){
	long long  k = 0;
	while (a>b){
		if (a%2==0) a /= 2;
		else {
			a /= 2;
			a++;
		}
		k += 1;
	}
	return k;
}
int main(){
	ifstream in("folding.in");
	ofstream out("folding.out");
	long long a1, b1, a2, b2;
	in >> a1 >> b1;
	in >> a2 >> b2;
	//t << a1 << b1 << a2 << b2;
	long long sum1 = 0, sum2 = 0;
	long long minim1, minim2;
	int flag = 0;
	int k1 = 0;
	int k2 = 0;
	if ((a1 >= a2) && (b1 >= b2)){
		sum1 = del(a1, a2) + del(b1, b2);
		sum2 = del(b1, a2) + del(a1, b2);
		minim1 = min(sum1, sum2);
		flag++;
		k1 = 1;
	}
		if ((a1 >= b2) && (b1 >= a2)){
			sum1 = del(a1, a2) + del(b1, b2);
			sum2 = del(b1, a2) + del(a1, b2);
			minim2 = min(sum1, sum2);
			flag++;
			k2 = 1;
		}
		else{
			out << -1;
			return 0;
		}
		if (flag == 2){
			out << min(minim1, minim2); return 0;
		}
		if (k1 == 1){
			out << minim1; return 0;
		}
		if (k2 == 1){
			out << minim2; return 0;
		}
	return 0;
}
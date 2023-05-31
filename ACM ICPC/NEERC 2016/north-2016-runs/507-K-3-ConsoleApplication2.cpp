#include <fstream>
//#include <vector>
//#include <utility>
//#include <string>
//#include <iterator>
//#include <set>
//#include <algorithm>
using namespace std;

struct name{
	int d;
	int m;
	int g;
};
int main(){
	ifstream in("king.in");
	ofstream out("king.out");
	int n;
	int D, M, G;
	in >> D >> M >> G;
	//out << D << " " << M << " " << G << endl;
	in >> n;
	//out << n << endl;
	name *m = new name [n];
	int sum = 0;
	for (int i = 0; i < n; i++){
		in >> m[i].d >> m[i].m >> m[i].g;
		if (G - m[i].g > 18){
			sum += 1;
		}
		else{
			if (G - m[i].g == 18){
				if (m[i].m < M) sum += 1;
				if (m[i].m == M){
					if (m[i].d <= D) sum += 1;
				}
			}
		}
	}
	if (sum == 0) out << -1;
	else
		if (sum == n) out << sum;
		else
			if (sum < n) out << sum;
	in.close();
	out.close();
	return 0;
}

/*
int flag = 1;
int flag2 = 1;
for (int i = 0; i < n; i++){
in >> m[i].d >> m[i].m >> m[i].g;
//out << m[i].d << " " << m[i].m << " " << m[i].g << endl;
if (G - m[i].g>18){
sum += 1; flag2 = 0;
}
else{
if (G - m[i].g == 18){
if (m[i].m == M){
if (m[i].d > D){
if (flag){
sum += 1; flag = 0;
}
}
else{
sum += 1; flag2 = 0;
}
}
else{
if (m[i].m < M){
sum += 1; flag2 = 0;
}
else{
if (m[i].m > M){
if (flag){
sum += 1; flag = 0;
}
}
}
}
}
else{
if (flag){
sum += 1; flag = 0;
}
}
}
}
if (flag2) out << -1;
else out << sum;*/


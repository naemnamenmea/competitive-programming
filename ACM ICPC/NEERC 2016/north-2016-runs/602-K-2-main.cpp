#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>

using namespace std;

struct kid{
	int d;
	int m;
	int y;
};

void main(){
	ifstream in("king.in");
	ofstream out("king.out");
	int d, m, y, n,old;
	vector<kid> kids;
	kid tmp;
	in >> d >> m >> y >> n;
	for (int i = 0; i < n; i++){
		in >> tmp.d >> tmp.m >> tmp.y;
		kids.push_back(tmp);
	}
	int dt, mt, yt, num=0;
	for (int i = 0; i < n; i++){
		old = y - kids[i].y - 1;
		if ((kids[i].m < m)||(kids[i].m == m && kids[i].d <= d))
			old++;
		if (old >= 18){
			if (num == 0){
				dt = kids[i].d;
				mt = kids[i].m;
				yt = kids[i].y;
				num = i + 1;
			}
			else{
				if (yt < kids[i].y){
					dt = kids[i].d;
					mt = kids[i].m;
					yt = kids[i].y;
					num = i + 1;
				}
				else if (yt == kids[i].y){
					if (mt < kids[i].m){
						dt = kids[i].d;
						mt = kids[i].m;
						yt = kids[i].y;
						num = i + 1;
					}
					else if (mt == kids[i].m){
						if (dt < kids[i].d){
							dt = kids[i].d;
							mt = kids[i].m;
							yt = kids[i].y;
							num = i + 1;
						}
					}
				}
			}
		}
	}
	if (num > 0)
		out << num;
	else out << -1;
}
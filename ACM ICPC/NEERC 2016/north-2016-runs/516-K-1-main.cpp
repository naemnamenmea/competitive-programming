#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

struct mymm{
	int d, m,e;
};

		
	ifstream in("king.in");
	ofstream out("king.out");

	int main(){
		mymm corol;
		in >> corol.d >> corol.m >> corol.e;
		int k = -2,n;
		in >> n;
		vector<mymm> mass(n);
		vector<mymm> voz(n);
		vector<bool> y(n, 0);
		for (int i = 0; i < n; i++)
		{
			in >> mass[i].d >> mass[i].m >> mass[i].e;
		}
		for (int i = 0; i < n; i++)
		{
			voz[i].d = corol.d - mass[i].d;
			voz[i].m = corol.m - mass[i].m;
			voz[i].e = corol.e - mass[i].e;
		}
		for (int i = 0; i < n; i++)
		{
			if (voz[i].e > 18 || (voz[i].e == 18 && (voz[i].m>0 || ((voz[i].m==0 &&voz[i].d>=0))))) {
				k = i; y[i] = 1;
			}
		}
		if (k != -2)
		{
			for (int i = 0; i < n; i++)
			{
				if (y[i] == 1 && (voz[i].e < voz[k].e || (voz[i].e <= voz[k].e&&voz[i].m < voz[k].m) || (voz[i].e <= voz[k].e&&voz[i].m <= voz[k].m&&voz[i].d < voz[k].m)))
				{
					k = i;
				}
			}
		}
		out << k+1;
		


		return 0;
	}



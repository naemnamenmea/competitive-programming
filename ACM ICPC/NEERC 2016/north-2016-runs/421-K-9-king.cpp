#include <iostream>
#include <fstream>

using namespace std;

int main(){

	fstream fin("king.in");
	int kingd[3];
	int sonsb[100][3];
	int sonNum;

	fin >> kingd[0] >> kingd[1] >> kingd[2];
	fin >> sonNum;

	for (int i = 0; i < sonNum; i++){
	
		fin >> sonsb[i][0] >> sonsb[i][1] >> sonsb[i][2];
	
	}
	fin.close();
	int y[100], m[100], d[100];
	int days[100];
	//d = kingd[0];
	for (int i = 0; i < sonNum ; i++){
		d[i] = kingd[0] - sonsb[i][0];
		if (d[i] < 0) 31 - sonsb[i][0];
		if (kingd[1]>sonsb[i][1]){ y[i] = kingd[2] - sonsb[i][2]; m[i] = kingd[1]-sonsb[i][1] ;}
		if (kingd[1]<sonsb[i][1]){ y[i] = kingd[2] - sonsb[i][2] - 1; m[i] = kingd[1]; }

		if (kingd[1] == sonsb[i][1]){ if (kingd[0] > sonsb[i][0]){ y[i] = kingd[2] - sonsb[i][2]; m[i] = kingd[1]; } else{ y[i] = kingd[2] - sonsb[i][2] - 1; m[i] = kingd[1]; } }
		if (kingd[1] == sonsb[i][1] && kingd[0] == sonsb[i][0]) y[i]++;
		days[i] = (y[i])*(12 * 31 -  3) + (m[i] * 31) + d[i];
		if (sonsb[i][1] <= 2){ days[i]-=3; }
		if (sonsb[i][1] == kingd[1] && sonsb[i][0] == kingd[0]){ m[i] = sonsb[i][1] - kingd[1]; }

	}
	int k = -1;
	int min[2];
	for (int i = 0; i < sonNum; i++){

		if (y[i] >= 18){ 
        
			min[0] = days[i];
			k = i;
        goto mark1; 
        }
	}
		mark1:
	for (int i = 1; i < sonNum ; i++){
		if ((min[0] > days[i]) && (y[i] >= 18)){ min[0] = days[i]; k = i; }
		else{ if (sonNum == 1 && y[0] >= 18)k = 0; }
	}



	

	ofstream fout("king.out");


 (k==-1)? fout << -1 : fout << ++k; 

	fout.close();

	return 0;
}

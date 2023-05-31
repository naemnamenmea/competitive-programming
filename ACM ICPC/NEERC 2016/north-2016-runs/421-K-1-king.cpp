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

	for (int i = 0; i < sonNum+1; i++){
	
		fin >> sonsb[i][0] >> sonsb[i][1] >> sonsb[i][2];
	
	}
	fin.close();
	int y[100], m[100], d;
	int days[100];
	d = kingd[0];
	for (int i = 0; i < sonNum + 1; i++){
		
		if (kingd[1]>sonsb[i][1]){ y[i] = kingd[2] - sonsb[i][2]; m[i] = kingd[1] - sonsb[i][1];}
		else{ y[i] = kingd[2] - sonsb[i][2] - 1; m[i] = kingd[1]; }

		if (kingd[1] == sonsb[i][1]){ if (kingd[0] > sonsb[i][0]){ y[i] = kingd[2] - sonsb[i][2]; m[i] = kingd[1] - sonsb[i][1]; } else{ y[i] = kingd[2] - sonsb[i][2] - 1; m[i] = kingd[1]; } }

		days[i] = (y[i] - 1)*(12 * 31 - 12 * 3) + (m[i] * 31) + d;
		if (kingd[1] > 2){ days[i]-=3; }

	}
	int k = -1;
	int min[2];
		min[0]= days[1];
		min[1] = 1;
	for (int i = 1; i < sonNum + 1; i++){
		if (min[0] > days[i] && y[i]>=18){ min[0] = days[i]; k = i; }
	}



	/*int res=-1;
	int min=1000 ;
	for (int i = 0; i < sonNum; i++){
	
		(kingd[1]>sonsb[i][1]) ? res=kingd[2] - sonsb[i][2] :res= kingd[2] - sonsb[i][2] + 1;
		if (kingd[1] == sonsb[i][1]) { ((kingd[0] == sonsb[i][0]) ? (kingd[2] - sonsb[i][2]) : res = kingd[2] - sonsb[i][2] + 1); };
		
		if (res < min && res >= 18){
			min = i;
		}
		else{ res = -1; }
		
		if (res != -1){
			res = i;
			goto mark1;
		}
	}*/

	ofstream fout("king.out");


 (k==-1)? fout << -1 : fout << ++k; 

	fout.close();

	return 0;
}

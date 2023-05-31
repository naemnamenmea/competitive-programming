// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include <fstream>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("king.in");
	out.open("king.out");
	int mm, dd, gg, n,k=0;
	int mas[100][3];
	in >> dd >> mm >> gg;
	in >> n;
	for (int i = 0; i < n; i++){
		in >> mas[i][2] >> mas[i][1] >> mas[i][0];
	}
	int min1 = dd;
	int min2 = mm;
	int min3 = gg;
	for (int i = 0; i < n; i++){
		if ((mas[i][0] < gg - 18) || ((mas[i][0] == gg-18) && (mas[i][1] <= mm)) || ((mas[i][0] == gg-18) && (mas[i][1] == mm) && (mas[i][2] <= dd))){
			if ((min1>mas[i][2]) || ((min1 == mas[i][2]) && (min2 > mas[i][1])) || ((min1 == mas[i][2]) && (min2 == mas[i][1]) && (min3 >= mas[i][0]))){
				min1 = mas[i][2];
				min2 = mas[i][1];
				min3 = mas[i][0];
				k = i+1;
			}
		}
	}
	if (k == 0) out << -1; else out << k;
	in.close();
	out.close();
	return 0;
}


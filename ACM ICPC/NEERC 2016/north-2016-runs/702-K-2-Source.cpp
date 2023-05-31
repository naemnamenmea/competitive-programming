# include <fstream>
# include <cmath>
# include <iostream>

using namespace std;

int main()
{
	ifstream fin("king.in");
	ofstream fout("king.out");

	int enu[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day, mon, year;

	fin >> day >> mon >> year;
	int n;
	fin >> n;

	int pday, pmon, pyear;
	int sum = 0;
	long pDAY;
	long DAY=year*365+day+enu[mon-1];
	for (int i = 0; i < n; i++)
	{
		fin >> pday >> pmon >> pyear;
		
		pDAY = pyear * 365 + pday + enu[mon - 1]-1;

	//pyear=year - pyear;
	//pmon =mon - pmon;
	//pday = day - pday;


		if ((DAY - pDAY)>=(18 * 365)) sum++;
		

	/*if (pyear > 18) sum++;
	else if (pyear==18) 

		if (pmon>0) sum++;
		else if (mon == 0)
			
			if (pday>= 0) sum++; */
	}

	if (sum == 0) sum = -1;
	fout << sum;


	fin.close();
	fout.close();
	//system("pause");
	return 0;
}
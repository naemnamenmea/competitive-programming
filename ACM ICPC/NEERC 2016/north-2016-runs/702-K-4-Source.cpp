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

	int san[2][100] = {};

	fin >> day >> mon >> year;

	int n;
	fin >> n;

	int pday, pmon, pyear, num = -1;

	long DAY=year*365+day+enu[mon-1];

	for (int i = 0; i < n; i++)
	{
		fin >> pday >> pmon >> pyear;
		
		san[0][i] = pyear * 365 + pday + enu[mon - 1];	
	}
    
	for (int i = 0; i < n; i++)
		if ((DAY - san[0][i]) >= (18 * 365))
			san[1][i] = 1;
		else san[1][i] = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if ((san[1][i] == 1) && (san[1][j] == 1))
				{
					if (san[0][j] <= san[0][i]) num = j + 1;
					else num = i + 1;
				}
			}
		}

	fout << num;

	fin.close();
	fout.close();

	return 0;
}
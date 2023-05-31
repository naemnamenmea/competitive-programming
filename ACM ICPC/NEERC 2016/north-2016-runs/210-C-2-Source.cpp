#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
using namespace std;




int main()
{

	ifstream in("codecoder.in");
	ofstream out("codecoder.out");

	long long n;
	long long temp;
	in >> n;
	long long *cc = new long long[n];
	long long *tf = new long long[n];
	bool **iThink = new bool*[n];
	bool **iThink2 = new bool*[n];
	long long *res = new long long[n];


	for (int i = 0; i < n; i++)
		iThink[i] = new bool[n];

	for (int i = 0; i < n; i++)
		iThink2[i] = new bool[n];


	for (long long i = 0; i < n; i++)
	{
		in >> cc[i] >> tf[i];
		res[i] = 0;
		for (long long j = 0; j < n; j++)
		{
			iThink[i][j] = 0;
			iThink2[i][j] = 0;
		}
	}

	for (long long ctz = 0; ctz < n; ctz++)
	{
		for (long long i = 0; i<n; i++)
		{
			if (ctz == i)
				continue;

			if (cc[ctz]>cc[i] || tf[ctz] > tf[i])
				iThink2[ctz][i] = iThink[ctz][i] = true;
			else iThink2[ctz][i] = iThink[ctz][i] = false;
		}
	}

	for (long long ctz = 0; ctz < n; ctz++)
	{
		for (long long i = 0; i < n; i++)
		{
			if (ctz == i)
				continue;

			if (iThink[ctz][i] == true)
			{
				for (int j = 0; j < n; j++)
				{
					if (ctz != j)
					{
						if (iThink[i][j] == true)
							iThink2[ctz][j] = true;

					}


				}

			}
		}
	}

		for (long long i = 0; i < n; i++)
			for (long long j = 0; j < n; j++)
				res[i] += iThink2[i][j];

		for (long long i = 0; i < n - 1; i++)
			out << res[i] << " ";
		out << res[n - 1];
		return 0;
	}













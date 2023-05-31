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
	in >> n;
	long long *cc = new long long[n];
	long long *tf = new long long[n];
	long long *res = new long long[n];

	for (long long i = 0; i < n; i++)
	{
		in >> cc[i] >> tf[i];
		res[i] = 0;
	}
	for (long long ctz = 0; ctz<n; ctz++)
	{
		for (long long i = 0; i<n; i++)
		{
			if (ctz == i)
				continue;

			if (cc[ctz]>cc[i] || tf[ctz] > tf[i])
				res[ctz]++;
		}
	}

	for (long long i = 0; i < n - 1; i++)
		out << res[i] << " ";

	out << res[n - 1];
	return 0;
}


#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{

	FILE *f;
	
	f = fopen("king.in", "r");

	int N, sum, d, m, g, kd, km, kg;

	sum = 0;

	fscanf(f, "%d %d %d", &kd, &km, &kg);
	
	fscanf(f, "%d", &N);

	for (int i = 0; i < N; i++)
	{
		fscanf(f, "%d %d %d", &d, &m, &g);
		if (kg - g > 18)
			sum++;
		else if (kg - g == 18)
		{
			if (km - m > 0)
				sum++;
			else if (km - m == 0)
				if (kd - d >= 0)
					sum++;
		}
	}

	ofstream out("king.out");

	if (sum > 0)
		out << sum;
	else
		out << -1;

	fclose(f);
	out.close();

	return 0;
}
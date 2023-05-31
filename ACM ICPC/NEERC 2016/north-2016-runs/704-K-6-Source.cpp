#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{

	FILE *f;
	
	f = fopen("king.in", "r");

	long int kd, km, kg, d, m, g, ky, y, N;

	fscanf(f, "%d %d %d", &kd, &km, &kg);
	
	fscanf(f, "%d", &N);

	ky = kd + km * 31 + kg * 365;

	fscanf(f, "%d %d %d", &d, &m, &g);
	long int min = 0;
	int j = -1;
	for (int i = 1; i <= N; i++)
	{
		fscanf(f, "%d %d %d", &d, &m, &g);
		y = d + m * 31 + g * 365;

		if (ky - y >= 18*365)
			if (min < y)
			{
				min = y;
				j = i;
			}
	}

	ofstream out("king.out");

	out << j+1;

	fclose(f);
	out.close();
	return 0;
}
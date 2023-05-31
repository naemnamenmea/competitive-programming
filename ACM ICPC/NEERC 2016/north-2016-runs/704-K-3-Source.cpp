#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{

	FILE *f;
	
	f = fopen("king.in", "r");

	int kd, km, kg, d, m, g, wind, winm, wing, wini, N, trig;

	fscanf(f, "%d %d %d", &kd, &km, &kg);
	
	fscanf(f, "%d", &N);

	ofstream out("king.out");

	wini = -1;

	trig = 0;
	for (int i = 0; i < N; i++)
	{
		fscanf(f, "%d %d %d", &d, &m, &g);
		if (kg - g >= 18)
		{
			if (km - m >= 0)
			{
				if (kd - d >= 0)
				{
					if (trig == 0)
					{
						wind = d;
						winm = m;
						wing = g;
						wini = i;
						trig = 1;
					}
					else
					{
						if (wing >= g)
						{
							if (winm >= m)
							{
								if (wind >= d)
								{
									wing = g;
									winm = m;
									wind = d;
									wini = i;
								}
							}
							else
							{
								wing = g;
								winm = m;
								wind = d;
								wini = i;
							}
						}
						else
						{
							wing = g;
							winm = m;
							wind = d;
							wini = i;
						}
					}
				}
			}
		}
	}

	if (wini == -1)
		out << -1;
	else
		out << wini + 1;
	fclose(f);
	out.close();
	return 0;
}
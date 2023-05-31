#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream out;
	ifstream in;
	unsigned countD;
	out.open("codecoder.out");
	in.open("codecoder.in");
	in >> countD;
	int *mas = new int[countD];
	int *mas1 = new int[countD];
	for (auto i(0); i < countD; i++)
	{
		in >> mas[i] >> mas1[i];
	}
	int y(0), y1(0),y2(0);
	for (auto i(0); i < countD; i++)
	{
		for (auto j(0); j < countD; j++)
		{
			if (mas[i] >= mas1[i])
			{
				y2 = mas[i];
				for (auto j(0); j < countD; j++)
					if (y2 > mas[j])
						y++;
				break;
			}
			else
			{
				y2 = mas1[i];
				for (auto j(0); j < countD; j++)
					if (y2 > mas1[j])
						y1++;
				break;
			}

		}
		if (y >= y1)
			out << y << endl;
		else
			out << y1 << endl;
		y1 = 0;
		y = 0;
	}
	/*for (auto i(0); i < countD; i++)
	{
		for (auto j(0); j<countD; j++)
			if (mas[i] > mas[j])
				y++;
		for (auto j(0); j<countD; j++)
			if (mas1[i] > mas1[j])
				y1++;
		if (y >= y1)
			out << y << endl;
		else
			out << y1 << endl;
		y1 = 0 ;
		y = 0;
	}*/
	return 0;
}
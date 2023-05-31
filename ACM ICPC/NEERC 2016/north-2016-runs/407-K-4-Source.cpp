#include <iostream>
#include <fstream>

using namespace std;

struct date
{
	unsigned short day, month, year;
	bool operator>(const date &t)
	{
		if (year <= t.year-19)
			return true;
		else if (year == t.year - 18)
		{
			if (month < t.month)
				return true;
			else if ((day <= t.day) && (month == t.month))
				return true;
			else
				return false;
		}
		else
			return false;
		
	};
};
int main()
{
	ofstream out;
	ifstream in;
	out.open("king.out");
	in.open("king.in");
	date one;
	unsigned short countD,count(0);
	in >> one.day >> one.month >> one.year;
	in >> countD;
	date *mas = new date[countD];
	for (int i(0); i < countD; i++)
	{
		in >> mas[i].day >> mas[i].month >> mas[i].year;
		if (mas[i] > one)
			count++;
	};
	if (!count)
		out << -1;
	else
		out << count;
	out.close();
	in.close();
	return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct date
{
	unsigned short day, month, year, k;
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
	}
};

bool f(const date &t, const date &t1)
{
		if (t.year > t1.year)
			return true;
		else if (t.year == t1.year)
		{
			if (t.month > t1.month)
				return true;
			else if ((t.day >= t1.day) && (t.month == t1.month))
				return true;
			else
				return false;
		}
		else
			return false;
}

int main()
{
	ofstream out;
	ifstream in;
	vector<date> vec;
	out.open("king.out");
	in.open("king.in");
	date one;
	unsigned short countD,count(0);
	in >> one.day >> one.month >> one.year;
	in >> countD;
	date *mas = new date[countD];
	date *mas1 = new date[countD];
	for (int i(0); i < countD; i++)
	{
		in >> mas[i].day >> mas[i].month >> mas[i].year;
		mas[i].k = i + 1;
		if (mas[i] > one)
		{
			mas1[count] = mas[i];
			count++;
		}
	};
	date min;
	min.day = 0;
	min.month = 0;
	min.year = 0;
	for (auto i(0); i< count; i++)
	 {
		//cout << mas1[i].day << " "<< mas1[i].month << " "<< mas1[i].year << " " << mas1[i].k << endl;
		if (f (mas1[i], min))
			min = mas1[i];
	 }
	if (count)
		out << min.k;
	else
		out << -1;

	out.close();
	in.close();
	//system("pause");
	return 0;
}
#include <fstream>
#include <utility>
//#include <iostream>
using namespace std;
namespace
{
	const char * InFileName("king.in");
	const char * OutFileName("king.out");
}

struct date
{
	unsigned short d, m, y;
};
bool check(date ch, date k, short a = 18)
{
	if (k.y - ch.y > a)
		return true;
	else if (k.y - ch.y == a)
	{
		if (ch.m < k.m) return 1;
		else if (ch.m == k.m) return ch.d <= k.d;
		else return 0;
	}
	else return 0;
}
int main()
{
	ifstream Fin(InFileName);
	ofstream Fout(OutFileName);
	date king;
	int n;
	Fin >> king.d >> king.m >> king.y;
	Fin >> n;
	int m(-1);
	date min;
	min.d = 0;
	min.m = 0;
	min.y = 0;
	for (int i(0); i < n; i++)
	{
		date tmp;
		Fin >> tmp.d >> tmp.m >> tmp.y;
		if (check(tmp, king) && check(min,tmp,0))
		{
			min = tmp;
			m = i+1;
		}
	}
	Fout << m;
	Fin.close();
	Fout.close();
	return 0;
}
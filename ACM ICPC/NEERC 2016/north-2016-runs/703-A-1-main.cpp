#include <fstream>
#include <utility>
//#include <iostream>
using namespace std;
namespace
{
	const char * InFileName("anniversary.in");
	const char * OutFileName("anniversary.out");
}

int main()
{
	int w, h;
	pair< int, int > c1,c2,res1,res2;
	ifstream Fin(InFileName);
	ofstream Fout(OutFileName);
	Fin >> w >> h>>c1.first >> c1.second >> c2.first >> c2.second;
	if (abs(c1.first - c2.first) > 1)
	{
		res1.first = res2.first = __min(c1.first, c2.first) + 1;
		res1.second = 0;
		res2.second = h;
	}
	else if (abs(c2.second - c1.second) > 1)
	{
		res1.second= res2.second= __min(c1.second, c2.second) + 1;
		res1.first = 0;
		res2.first = w;
	}
	else if (abs(c1.first - c2.first) ==1)
	{
		res1.first = c1.first;
		res2.first = c2.first;
		res1.second = 0;
		res2.second = h;
	}
	else if (c1.first == c2.first)
	{
		res1.second = c1.second;
		res2.second = c2.second;
		res1.first = 0;
		res2.first = w;
	}
	Fout << res1.first << ' ' << res1.second << ' ' << res2.first << ' ' << res2.second;
	Fin.close();
	Fout.close();
	return 0;
}
#include <fstream>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
namespace
{
	const char * InFileName("folding.in");
	const char * OutFileName("folding.out");
}
bool valid(pair<float, float> a, pair<float, float> b)
{
	return a.first >= b.first && a.second >= b.second;
}
int main()
{
	ifstream Fin(InFileName);
	ofstream Fout(OutFileName);
	pair <float,float> a, b;
	Fin >> a.first >> a.second >> b.first >>b.second;
	int res(0);
	if (!valid(a, b))
	{
		swap(a.first, a.second);
		if (!valid(a, b)) res = -1;
		else res = ceil(log2(a.first / b.first)) + ceil(log2(a.second / b.second));
	}
	else
	{
		res = ceil(log2(a.first / b.first)) + ceil(log2(a.second / b.second));
		swap(a.first, a.second);
		if (valid(a, b)) res = __min(res, ceil(log2(a.first / b.first)) + ceil(log2(a.second / b.second)));
	}
	Fout << res;
	return 0;
}
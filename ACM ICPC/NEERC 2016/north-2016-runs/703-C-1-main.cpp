#include <fstream>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
namespace
{
	const char * InFileName("codecoder.in");
	const char * OutFileName("codecoder.out");
}
bool f1(pair<int, int>a, pair<int, int> b)
{
	return a.first < b.first;
}
bool f2(pair<int, int>a, pair<int, int> b)
{
	return a.second < b.second;
}

int main()
{
	ifstream Fin(InFileName);
	ofstream Fout(OutFileName);
	int n(0);
	Fin >> n;
	pair <int, int> *chels = new pair<int, int>[n];
	pair <int, int> *chels2 = new pair<int, int>[n];
	int *res = new  int[n];
	for (int i(0); i < n; i++)
	{
		Fin >> chels[i].first >> chels[i].second;
		chels2[i] = chels[i];
		res[i] = 0;
	}
	sort(chels2, chels2 + n, f1);
	for (int i(0); i < n; i++)
	{
		pair <int, int>* tmp = find(chels2, chels2 + n, chels[i]);
		for (int j(0); j < tmp - chels2; j++)
		{
			if (chels2[j].second >= chels[i].second) res[i]++;
		}
	}
	sort(chels2, chels2 + n, f2);
	for (int i(0); i < n; i++)
	{
		pair <int, int>* tmp = find(chels2, chels2 + n, chels[i]);
		res[i] += tmp - chels2;
	}
	for (int i(0); i < n; i++)
		Fout << res[i]<< endl;
	Fin.close();
	Fout.close();
	delete[] chels, chels2, res;
	return 0;
}
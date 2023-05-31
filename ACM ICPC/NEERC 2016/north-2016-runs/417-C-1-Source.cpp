#include <iostream>
#include <iomanip> 
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cit
{
	int value;
	int poz;
};


bool cmp(cit a, cit b)
{
	if (a.value > b.value) return false;
	else return true;
}

int main()
{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);

	int n, a, b;
	cit lol;
	cin >> n;

	vector <cit> CC;
	vector <cit> TF;
	vector <cit>::iterator p;

	int* win = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		lol.poz = i;
		lol.value = a;
		CC.push_back(lol);
		lol.value = b;
		TF.push_back(lol);
		//CC[i].poz = i;
		//CC[i].value = a;
		//TF[i].poz = i;
		//TF[i].value = b;
		win[i] = 0;
	}
	sort(CC.begin(), CC.end(), cmp);
	sort(TF.begin(), TF.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		win[CC[i].poz] = i;
		if (win[TF[i].poz] < i) win[TF[i].poz] = i;
	}

	if (n > 1)
	{
		for (int i = 0; i < n-1; i++)
		{
			cout << win[i] << endl;
		}
		cout << win[n-1];
	}
	else cout << win[0];

	/*
	for (int i = 0; i < n; i++)
	{
		cout << CC[i].value << "|" << CC[i].poz <<"  ";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << TF[i].value << "|" << TF[i].poz << "  ";
	}
    */




	return 0;
}
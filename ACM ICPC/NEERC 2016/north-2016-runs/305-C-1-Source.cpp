#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a > b) ? b : a;
}

int main()
{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);

	int n;
	int
		a[100000][3],
		b[100000][3];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i][1] >> a[i][2];
		//second
		a[i][0] = 0;
		b[i][1] = a[i][1];
		b[i][2] = a[i][2];
	}

	int max_cc = 0;
	int max_tf = 0;

	int n_2 = n;

	for (int i = 0; i < n_2; i++)
	{
		if (b[i][1] >= max_cc) max_cc = b[i][1];
		if (b[i][2] >= max_tf) max_tf = b[i][1];
	}

	for (int i = 0; i < n_2; i++)
	{
		if (b[i][1] >= max_cc || b[i][2] >= max_tf)
		{
			max_cc = min(b[i][1], max_cc);
			max_tf = min(b[i][2], max_tf);
		}
	}

	for (int i = 0; i < n_2; i++)
	{
		if (b[i][1] >= max_cc) a[i][0] = n_2;
		if (b[i][2] >= max_tf) a[i][0] = n_2;
	}

	int last_n = n_2;

b_s:

	last_n = n_2;

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i][0] == 0)
		{
			b[j][0] = i;
			b[j][1] = a[i][1];
			b[j][2] = a[i][2];
			j += 1;
		}
	}

	n_2 = j;

	max_cc = 0;
	max_tf = 0;

	for (int i = 0; i < n_2; i++)
	{
		if (b[i][1] >= max_cc || b[i][2] >= max_tf)
		{
			max_cc = min(b[i][1], max_cc);
			max_tf = min(b[i][2], max_tf);
		}
	}

	for (int i = 0; i < n_2; i++)
	{
		if (b[i][1] >= max_cc) a[b[i][0]][0] = n_2;
		if (b[i][2] >= max_tf) a[b[i][0]][0] = n_2;
	}

	if (last_n != j)
		goto b_s;





	fclose(stdin);
	fclose(stdout);
	return 0;
}
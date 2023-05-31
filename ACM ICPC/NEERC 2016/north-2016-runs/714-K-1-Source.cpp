#include <iostream>
#include <fstream>

using namespace std;

int if_18(int d, int m, int y, int df, int mf, int yf)
{
	if (yf - y > 18)
		return 1;
	else 
		if (yf - y == 18)
		{
		if (mf - m > 0)
			return 1;
		else
			if (mf - m == 0)
				if (df - d > 0)
					return 1;
		}
	else return 0;
}

int youngest(int allow[], int d[], int m[], int y[], int n)
{
	int p = allow[0];
	
	for (int i = 0; i < n; i++)
	{
		if (y[allow[i]] > y[p])
			p = allow[i];
		else
			if (y[allow[i]] == y[p])
				if (m[allow[i]] > m[p])
					p = allow[i];
				else
					if (m[allow[i]] == m[p])
						if (d[allow[i]] > d[p])
							p = allow[i];
	}
	return p;
}

int main()
{
	int d, m, y, n, ds[100], ms[100], ys[100], i, allowed[100], c=0;

	ifstream in ("king.in");
	ofstream out("king.out");
	in >> d >> m >> y >> n;
	//out << d;
	for (i = 0; i < n; i++)
	{
		in >> ds[i] >> ms[i] >> ys[i];
		//out << ds[i] << ms[i] << ys[i] << endl;
	}
	for (i = 0; i < n; i++)
		if (if_18(ds[i], ms[i], ys[i], d, m, y) == 1)
		{
			allowed[c] = i;
			c++;
		}
	if (c == 0)
		out << -1;
	else
	{
		int r = youngest(allowed, ds, ms, ys, c) + 1;
		out << r;
	}
	return 0;
}
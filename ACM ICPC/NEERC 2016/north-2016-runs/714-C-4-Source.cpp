#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	long long int n, *a, *b, *r, p;

	ifstream in("codecoder.in");
	ofstream out("codecoder.out");

	in >> n;
	a = new long long int[n];
	b = new long long int[n];
	r = new long long int[n];
	for (long long int i = 0; i < n; i++)
	{
		in >> a[i] >> b[i];
		r[i] = 0;
	}

	for (long long int i = 0; i < n; i++)
	{
		if (a[i]>b[i])
			p = a[i];
		else
			p = b[i];
        for (long long int j = 0; j < n; j++)
			if (j != i)
			{
			if (p > a[j])
				r[i]++;
			else
				if (p > b[j])
					r[i]++;
			}
		out << r[i] << endl;
    }
	return 0;
}
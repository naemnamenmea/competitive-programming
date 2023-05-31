#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	long long int n, *a, *b, *r;

	ifstream in("codecoder.in");
	ofstream out("codecoder.out");

	in >> n;
	a = new long long int[n];
	b = new long long int[n];
	r = new long long int[n];
	for (long int i = 0; i < n; i++)
	{
		in >> a[i] >> b[i];
		r[i] = 0;
	}

	for (long int i = 0; i < n; i++)
	{
		for (long int j = 0; j < n; j++)
			if (j != i)
			{
			if (a[i] >= a[j])
				r[i]++;
			else
				if (b[i] >= b[j])
					r[i]++;
			}
		out << r[i] << endl;
    }
	return 0;
}
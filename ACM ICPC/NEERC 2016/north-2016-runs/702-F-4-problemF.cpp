# include <fstream>
# include <iostream>

using namespace std;

int main()
{
	ifstream fin("folding.in");
	ofstream fout("folding.out");

	long long a, b, c, d;

	fin >> a >> b >> c >> d;

	long long countA = 0;


	long long e = 0;

	if (a < b)
	{
		e = a; a = b; b = e;
	}

	if (c < d)
	{
		e = c; c = d; d = e;
	}


	if ((c == 1) || (d == 1) || (a == 1) || (b == 1)) {

		if ((c == 1) && (d == 1)) { c = 1; d = 1; }
		else
		{
			fout << -1;

			return 0;
		}
	}

	if (a>3)
		if (a % 2 == 1) a--;
	if (b > 3)
		if (b % 2 == 1) b--;
	if (c > 3)
		if (c % 2 == 1) c--;
	if (d > 3)
		if (d % 2 == 1) d--;


	if ((a == 2) && (b == 2) && (c == 1) && (d == 1))
     {fout<< 1; return 0; }

		while (!(((a == c)) && ((b == d))))
		{
			if ((a > c) || (a > d))
			{

				a = a - 2;
				countA++;
			}

			if ((b > c) || (b > d))
			{

				b = b - 2;
				countA++;

			}
		}


		fout << countA;

	fin.close();
	fout.close();
	//system("pause");
	return 0;
}
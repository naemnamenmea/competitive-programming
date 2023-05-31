# include <fstream>
# include <iostream>

using namespace std;

int main()
{
	ifstream fin("folding.in");
	ofstream fout("folding.out");

		unsigned int a, b, c, d;
	
		fin >> a >> b >> c >> d;
	
		long long countA=0;
		long long countC=0;

		int e=0;

		if (a < b)
          {
			e = a; a = b; b = e;
		    }

		if (c < d)
		{
			e = c; c = d; d = e;
		}

        
		if ((c == 1) || (d == 1)) {
			fout << -1; return 0;
		}

		if (a % 2 == 1) a--;
		if (b % 2 == 1) b--;


		while (!(((a == c) || (a == b)) && ((b == c) || (b == d))))
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
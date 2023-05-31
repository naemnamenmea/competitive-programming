#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	long int n, nb, ng;

	ifstream in("boysgirls.in");
	ofstream out("boysgirls.out");

	in >> n >> nb >> ng;

	if (nb == 0 && ng == n)
		for (long int i = 0; i<n; i++)
			out << "G";
	else
		if (ng == 0 && nb == n)
			for (long int i=0; i<n; i++)
				out << "B";
		else
			if (nb - 1 + ng - 1 != n)
				if (n > 2)
					out << "Impossible";
				else
					out << "BG";
			else
			{
				for (long int i = 1; i < nb; i++)
					out << "B";
				for (long int i = 1; i < ng; i++)
					out << "G";
			}
	return 0;
}
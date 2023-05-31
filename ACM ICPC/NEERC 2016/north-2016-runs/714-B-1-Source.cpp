#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n, nb, ng;

	ifstream in("boysgirls.in");
	ofstream out("boysgirls.out");

	in >> n >> nb >> ng;

	if (nb - 1 + ng - 1 != n)
		out << "Impossible";
	else
	{
		for (int i = 1; i < nb; i++)
			out << "B";
		for (int i = 1; i < ng; i++)
			out << "G";
	}
	return 0;
}
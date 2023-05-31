// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include <fstream>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("boysgirls.in");
	out.open("boysgirls.out");
	int n,x,y;
	in >> n >> x >> y;
	if ((n % 2 == 1) || ((x % 2 == 0) || (y % 2 == 0))) out << "Impossible";
	else for (int i = 0; i < n; i++){ if (x > 1) { out << "B"; x--; }; if (y > 1) out << "G"; y--; }
	in.close();
	out.close();
	return 0;
}


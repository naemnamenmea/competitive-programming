// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("boysgirls.in");
	out.open("boysgirls.out");
	int n,x,y;
	in >> n >> x >> y;
	string solution;
	if (n == y) for (int i = 0; i < y;i++) out << "G";
	else

	if (n == x) for (int i = 0; i < x; i++) out << "B";
	else

	if ((n == 2) && (x == 1) && (y == 1)) out << "BG";
	else

		for (int i = 0; i < n; i++){ if (x > 1) { solution += 'B'; x--; }; if (y > 1) solution += 'G'; y--; }

	if ((solution.length() > (n + 2))||(solution.length()<n)) out << "Impossible";
	else out << solution;

	in.close();
	out.close();
	return 0;
}


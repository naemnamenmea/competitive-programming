// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include <fstream>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("folding.in");
	out.open("folding.out");
	int a, b, a1, b1;
	in >> a >> b >> a1 >> b1;
	int s1=0, s2=0;
	if (a1<a) while (a>a1){
		a = a / 2;
		s1++;
	}
	if (b1<b) while (b>b1){
		b = b / 2;
		s2++;
	}
	if ((a1 > a) || (b1 > b)) {
		out << -1;
		return(0);
	}
	out << s1+ s2;
	in.close();
	out.close();
	return 0;
}


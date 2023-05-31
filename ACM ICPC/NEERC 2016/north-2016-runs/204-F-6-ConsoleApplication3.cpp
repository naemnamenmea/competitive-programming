// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("folding.in");
	out.open("folding.out");
	int a, b, a1, b1;
	in >> a >> b >> a1 >> b1;
	if (((a1 > a) && (a1 > b)) || ((b1 > a) && (b1 > b))) {
		out << -1;
		return(0);
	}
	if (a > b){
		int c = a;
		a = b;
		b = c;
	}
	if (a1 > b1){
		int c = a1;
		a1 = b1;
		b1 = c;
	}
	int s1 = 0, s2 = 0;
    
	while (a>a1){
		a=int(round(a/2.0));
		s1++;
	}
	while (b>b1){
		b = int(round(b/2.0));
		s2++;
	}

	out << s1 + s2;
	in.close();
	out.close();
	return 0;
}
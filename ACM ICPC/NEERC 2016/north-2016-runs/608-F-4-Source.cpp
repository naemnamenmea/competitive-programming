#include <fstream>
using namespace std;

int max(int& a,int& b)
{
	return a > b ? a : b;
}

int min(int& a, int& b)
{
	return a > b ? b : a;
}

int main()
{
	fstream in, out;
	in.open("folding.in",ios::in);
	out.open("folding.out",ios::out);
	int W, H;
	int w, h;
	in >> W >> H>>w>>h;
	int a = max(W,H);
	int b = min(W, H);
	int wa = max(w, h);
	int wb = min(w,h);

	if (a<wa||b<wb)
	{
		out << -1;
	}
	else
	{
		int f = 0;
		while (wa * 2 <= a)
		{
			f++;
			wa = wa * 2;
		}
		if (wa != a){ f++; }
		while (wb * 2 <= b)
		{
			f++;
			wb = wb * 2;
		}
		if (wb != b){ f++; }
		out << f;
		/*int index = 0;
		while ((a / 2 + a % 2) > wa)
		{
			index++;
			a = a / 2 + a % 2;
		}
		if (a != wa){ index++; }
		while ((b / 2 + b % 2) > wb)
		{
			index++;
			b = b / 2 + b % 2;
		}
		if (b!=wb){ index++; }
	
	 out << index;*/
	}
	in.close();
	out.close();
}
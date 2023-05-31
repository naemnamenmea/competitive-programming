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
	fstream cin, cout;
	cin.open("floding.in",ios::in);
	cout.open("floding.out",ios::out);
	int W, H;
	int w, h;
	cin >> W >> H>>w>>h;
	int a = max(W,H);
	int b = min(W, H);
	int wa = max(w, h);
	int wb = min(w,h);
	if (a<wa||b<wb)
	{
		cout << -1;
	}
	else
	{
		int index = 0;
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
	
	 cout << index;
	}
	cin.close();
	cout.close();
}
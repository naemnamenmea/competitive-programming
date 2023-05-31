#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int r = 0;
	float w, h, w1, h1, t;

	ifstream in("folding.in");
	ofstream out("folding.out");

	in >> w >> h >> w1 >> h1;

	if (h1 > w1)
	{
		t = w1;
		w1 = h1;
		h1 = t;
	}
	if (h > w)
	{
		t = w;
		w = h;
		h = t;
	}
	if (w1 > w || h1 > h)
		out << -1;
	else
	{
		while (w / 2 >= w1)
		{
			if (h > w)
			{
				t = w;
				w = h;
				h = t;
			}
			if (w / 2 >= w1)
			{
				w = w / 2;
				r++;
			}
		}
		while (h / 2 >= h1)
		{
			h = h / 2;
			r++;
		}
		if (h > h1)
			r++;
		if (w > w1)
			r++;
		out << r;
	}
	return 0;
}
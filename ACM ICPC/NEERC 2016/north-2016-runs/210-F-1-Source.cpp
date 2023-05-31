#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
using namespace std;




int main()
{
	
	ifstream in("folding.in");
	ofstream out("folding.out");
	
	bool turned=false;
	double W, H;
	double Wmain;
	double Hmain;
	double w, h;
	long long FoldCount = 0;
	long long FoldCount2 = LLONG_MAX;
	double temp;
	in >> W >> H >> w >> h;
	Wmain = W;
	Hmain = H;
	
	if (!(W >= w && H >= h))
	{
		temp = W;
		W = H;
		H = temp;
		turned = true;
		if (!(W >= w && H >= h))
		{
			out << "-1";
			return 0;
		}
	}
	
	// Первая итерация
	while (W > w)
	{
		if (W / 2.0 >= w)
		{
			W = ceil(W/2.0);
			FoldCount++;
		}
		else if (W / 2.0 < w)
		{
			FoldCount++;
			break;
		}

	}

	while (H > h)
	{
		if (H / 2.0 >= h)
		{
			H = ceil(H / 2.0);
			FoldCount++;
		}
		else if (H / 2.0 < h)
		{
			FoldCount++;
			break;
		}
	}

	if (!turned)
	{
		FoldCount2 = 0;
		W = Wmain;
		H = Hmain;

		temp = W;
		W = H;
		H = temp;
		while (W > w)
		{
			if (W / 2.0 >= w)
			{
				W = ceil(W / 2.0);
				FoldCount2++;
			}
			else if (W / 2.0 < w)
			{
				FoldCount2++;
				break;
			}

		}

		while (H > h)
		{
			if (H / 2.0 >= h)
			{
				H = ceil(H / 2.0);
				FoldCount2++;
			}
			else if (H / 2.0 < h)
			{
				FoldCount2++;
				break;
			}
		}

	}


	double temptemp = (FoldCount <= FoldCount2) ? FoldCount : FoldCount2;
	out << temptemp;
	return 0;
}


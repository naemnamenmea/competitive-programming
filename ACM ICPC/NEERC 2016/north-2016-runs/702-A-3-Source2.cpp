# include <fstream>
# include <iostream>

using namespace std;

int main()
{
	ifstream fin("anniversary.in");
	ofstream fout("anniversary.out");

	long long w, h, ax, ay, bx, by;
	fin >> w >> h >> ax >> ay >> bx >> by;

	long long axst = ax, ayst = ay, bxst = bx, byst = by, axfin = ax, ayfin = ay, bxfin = bx, byfin = by;

	/*
	while (axst < w && ayst < h)
	{
		axst++;
		ayst++;
	}

	while (bxst < w && byst < h)
	{
		bxst++;
		byst++;
	}

	while (ax > 0 && ay > 0)
	{
		ax--;
		ay--;
	}

	while (bx > 0 && by > 0)
	{
		bx--;
		by--;
	}
    */

	if ((w - ax) < (h - ay))
	{
		axst = w;
		ayst = ay + (w - ax);
	}
	else if ((w - ax) == (h - ay))
	{
		axst = w;
		ayst = h;
	}
	else
	{
		axst = ax + (h - ay);
		ayst = h;
	}

	if ((w - bx) < (h - by))
	{
		bxst = w;
		byst = by + (w - bx);
	}
	else if ((w - bx) == (h - by))
	    {
		    bxst = w;
		    byst = h;
	    }
    	else
	        {
		        bxst = bx + (h - by);
		        byst = h;
	        }

	if (ax < ay)
	{
		axfin = 0;
		ayfin = ay - ax;
	}
	else if (ax == ay)
	{
		axfin = 0;
		ayfin = 0;
	}
	else
	{
		axfin = ax - ay;
		ayfin = 0;
	}

	if (bx < by)
	{
		bxfin = 0;
		byfin = by - bx;
	}
	else if (bx == by)
	{
		bxfin = 0;
		byfin = 0;
	}
	else
	{
		bxfin = bx - by;
		byfin = 0;
	}
    /////////////////////////////////////////
		if (axfin <= bxfin)
		{
			if (ayfin <= byfin) fout << axfin << " " << ayfin << " ";
			else fout << bxfin << " " << byfin << " ";
		}
		else	if (bxfin <= axfin)
		{
			if (byfin <= ayfin) fout << bxfin << " " << byfin << " ";
			else fout << axfin << " " << ayfin << " ";
		}

		if (axst >= bxst)
		{
			if (ayst >= byst) fout << axst << " " << ayst;
			else fout << bxst << " " << byst;
		}
		else	if (bxst >= axst)
		{
			if (byst >= ayst) fout << bxst << " " << byst;
			else fout << axst << " " << ayst;
		}
    

	fin.close();
	fout.close();
	return 0;
}
# include <fstream>
# include <iostream>

using namespace std;

int main()
{
	ifstream fin("anniversary.in");
	ofstream fout("anniversary.out");

	int w, h, ax, ay, bx, by;
	fin >> w >> h >> ax >> ay >> bx >> by;

	int axst=ax, ayst=ay, bxst=bx, byst=by, axfin=ax, ayfin=ay, bxfin=bx, byfin=by;


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

	while (axfin > 0 && ayfin > 0)
	{
		axfin--;
		ayfin--;
	}

	while (bxfin > 0 && byfin > 0)
	{
		bxfin--;
		byfin--;
	}

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
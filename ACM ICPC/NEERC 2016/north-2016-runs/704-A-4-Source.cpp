#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	FILE *in;

	double k1, k2, k3, a, b, q, h, w, y, x, xa, xb, ya, yb, xc, yc;

	in = fopen("anniversary.in", "r");
	
	fscanf(in, "%lf %lf %lf %lf %lf %lf", &w, &h, &xa, &ya, &xb, &yb);
	
	ofstream out("anniversary.out");
	//first
	k1 = ya / xa; k2 = yb / xb;
	if (k1 < k2)
	{
		xc = xa;
		yc = ya;
		xa = xb;
		ya = yb;
		xb = xc;
		yb = yc;
		k3 = k1;
		k1 = k2;
		k2 = k3;
	}

	q = h / w;

	if ((k1 > q) && (k2 > q))
	{
		y = h;
		a = y / k1;
		b = y / k2;
		xc = (int)a + 1;
		if (xc < b)
		{
			yc = h;
			out << 0 << " " << 0 << " " << xc << " " << yc;
			fclose(in);
			out.close();
			return 0;
		}
	}
	if ((k1 < q) && (k2 < q))
	{
		x = w;
		a = x * k1;
		b = x * k2;
		yc = (int)a + 1;
		if (yc < b)
		{
			xc = w;
			out << 0 << " " << 0 << " " << xc << " " << yc;
			fclose(in);
			out.close();
			return 0;
		}
	}
	if ((k1 > q) && (k2 < q))
	{
		xc = w;
		yc = h;
		out << 0 << " " << 0 << " " << xc << " " << yc;
		fclose(in);
		out.close();
		return 0;
	}
	///sec
	k1 = (ya - h) / xa; k2 = (yb - h) / xb;
	if (k1 > k2)
	{
		xc = xa;
		yc = ya;
		xa = xb;
		ya = yb;
		xb = xc;
		yb = yc;
		k3 = k1;
		k1 = k2;
		k2 = k3;
	}

	q = -h / w;

	if ((k1 < q) && (k2 < q))
	{
		y = 0;
		a = (y - h) / k1;
		b = (y - h) / k2;
		xc = (int)a + 1;
		if (xc < b)
		{
			yc = 0;
			out << 0 << " " << h << " " << xc << " " << yc;
			fclose(in);
			out.close();
			return 0;
		}
	}
	if ((k1 > q) && (k2 > q))
	{
		x = w;
		a = x * k1 + h;
		b = x * k2 + h;
		yc = (int)a + 1;
		if (yc < b)
		{
			xc = w;
			out << 0 << " " << h << " " << xc << " " << yc;
			fclose(in);
			out.close();
			return 0;
		}
	}
	if ((k1 < q) && (k2 > q))
	{
		xc = w;
		yc = 0;
		out << 0 << " " << h << " " << xc << " " << yc;
		fclose(in);
		out.close();
		return 0;
	}


	//third
	k1 = ya / (xa - w); k2 = yb / (xb - w);
	if (k1 < k2)
	{
		xc = xa;
		yc = ya;
		xa = xb;
		ya = yb;
		xb = xc;
		yb = yc;
		k3 = k1;
		k1 = k2;
		k2 = k3;
	}

	q = -h / w;

	if ((k1 < q) && (k2 < q))
	{
		y = h;
		a = w - y / k1;
		b = w - y / k2;
		xc = (int)a + 1;
		if (xc < b)
		{
			yc = h;
			out << w << " " << 0 << " " << xc << " " << yc;
			fclose(in);
			out.close();
			return 0;
		}
	}
	if ((k1 > q) && (k2 > q))
	{
		x = 0;
		a = -w  * k1;
		b = -w * k2;
		yc = (int)a + 1;
		if (yc < b)
		{
			xc = 0;
			out << w << " " << 0 << " " << xc << " " << yc;
			fclose(in);
			out.close();
			return 0;
		}
	}
	if ((k1 > q) && (k2 < q))
	{
		xc = 0;
		yc = h;
		out << w << " " << 0 << " " << xc << " " << yc;
		fclose(in);
		out.close();
		return 0;
	}
	///fourth
	k1 = (ya - h) / (xa - w); k2 = (yb - h) / (xb - w);
	if (k1 > k2)
	{
		xc = xa;
		yc = ya;
		xa = xb;
		ya = yb;
		xb = xc;
		yb = yc;
		k3 = k1;
		k1 = k2;
		k2 = k3;
	}

	q = h / w;

	if ((k1 > q) && (k2 > q))
	{
		y = 0;
		a = w + (y - h) / k1;
		b = w + (y - h) / k2;
		xc = (int)a + 1;
		if (xc < b)
		{
			yc = 0;
			out << w << " " << h << " " << xc << " " << yc;
			fclose(in);
			out.close();
			return 0;
		}
	}
	if ((k1 < q) && (k2 < q))
	{
		x = 0;
		a = -w * k1 + h;
		b = -w * k2 + h;
		yc = (int)a + 1;
		if (yc < b)
		{
			xc = 0;
			out << w << " " << h << " " << xc << " " << yc;
			fclose(in);
			out.close();
			return 0;
		}
	}
	if ((k1 < q) && (k2 > q))
	{
		xc = 0;
		yc = 0;
		out << w << " " << h << " " << xc << " " << yc;
		fclose(in);
		out.close();
		return 0;
	}
	return 0;
}
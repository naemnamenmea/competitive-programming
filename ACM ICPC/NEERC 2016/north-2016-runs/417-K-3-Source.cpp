#include <iostream>
#include <iomanip> 
#include <math.h>
#include <string>
#include <vector>

using namespace std;
int d_k, m_k, y_k;
struct k
{
	double m, d, y,a;
	bool ad;
};

int main()
{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);

	cin >> d_k >> m_k >> y_k;
	int n,count=0;
	cin >> n;
	double min = +INFINITY;
    int imin = 0;

	k ar[101];
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i].d >> ar[i].m >> ar[i].y;
		ar[i].a = (y_k - ar[i].y) + (m_k - ar[i].m) / 12 + (d_k - ar[i].d) / 365;
	}
	for (int i = 0; i < n; i++)
	{
		if (ar[i].a >= (double) 18 )
		{
			if (ar[i].a < min)
			{
				min = ar[i].a;
				imin = i;
			}
		}
		else count++;
	}
	if (count == n)
		cout << "-1";
	else cout << imin + 1;
 




		/*if (y_k - ar[i].y > 18)
			ar[i].ad = true;
		else
		{
			if (y_k - ar[i].y == 18)
			{
				if (m_k - ar[i].m > 0)
					ar[i].ad = true;
				else
					if (d_k - ar[i].d >= 0)
						ar[i].ad = true;
					else
						ar[i].ad = false;
			}
			else
			{
				ar[i].ad = false;
				count++;
			}
		}
	}
	if (count == n)
	{
		cout << "-1";
		return 0;
	}
	else{

		int min = -1, min_m = -1, imin = 0, min_d = -1;
		for (int i = 0; i < n; i++)
		{
			if (ar[i].ad == true)
			{
				if (ar[i].y >= min)
				{
					if (ar[i].y == min)
					{
						if (ar[i].m >= min_m)
						{
							if (ar[i].m == min_m)
							{
								if (ar[i].d > min_d)
								{
									min_m = ar[i].m;
									min = ar[i].y;
									min_d = ar[i].d;
									imin = i;
								}
							}

						}

					}
					else
					{
						min_m = ar[i].m;
						min = ar[i].y;
						min_d = ar[i].d;
						imin = i;
					}

				}
				else
				{
					min_m = ar[i].m;
					min = ar[i].y;
					min_d = ar[i].d;
					imin = i;
				}
			}
		}
      
	
		cout << imin + 1;

	}*/
	return 0;
}



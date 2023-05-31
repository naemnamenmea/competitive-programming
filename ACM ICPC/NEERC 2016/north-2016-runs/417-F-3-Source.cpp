/*#include <iostream>
#include <iomanip> 
#include <math.h>
#include <string>
#include <vector>

using namespace std;
int d_k, m_k, y_k;
struct k
{
	int m, d, y;
	bool ad;
};

int main()
{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);

	cin >> d_k >> m_k >> y_k;
	int n,count=0;
	cin >> n;
	k ar[100];
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i].d >> ar[i].m >> ar[i].y;
		if (y_k - ar[i].y > 18)
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

	}
	return 0;
}


*/

#include <iostream>
#include <iomanip> 
#include <math.h>
#include <string>
#include <vector>

using namespace std;
long couts=0;

long min(long a, long b)
{
	if (a < b) return a;
	else return b;
}


int flod(long a, long b)
{
	int i = 0;
	while (a > b) 
	{
		a = a % 2 + a / 2;
		i++;
	}
	return i;

}



int main()
{
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);

	long a1, a2, b1, b2;

	cin >> a1 >> b1 >> a2 >> b2;

	if (b1 > a1) swap(a1, b1);
	if (b2 > a2) swap(a2, b2);

	if (a1 >= a2 && b1 >= b2)
	{
		if (b1 > a2) cout << min((flod(a1, a2) + flod(b1, b2)), (flod(a1, b2) + flod(b1, a2)));
		else
		{
			cout << flod(a1, a2) + flod(b1, b2);
		}
	}
	else cout << "-1";

	return 0;
}
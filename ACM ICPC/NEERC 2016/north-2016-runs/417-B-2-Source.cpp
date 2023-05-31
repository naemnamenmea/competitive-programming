#include <iostream>
#include <iomanip> 
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int min(int a, int b)
{
	if (a > b) return b;
	else return a;
}


int main()
{
	freopen("boysgirls.in", "r", stdin);
	freopen("boysgirls.out", "w", stdout);

	int boy, girl, size;
	cin >> size >> boy >> girl;

	if (boy == 0 && boy-1 == size)
	{
		for (int i = 0; i < size; i++) cout << "G";
	}
	else 
		if (girl == 0 && girl - 1 == size)
		{
		    for (int i = 0; i < size; i++) cout << "B";
		}
		else 
		{
		    if (boy > girl)
		    {
			    if ((max(boy, girl) - min(boy, girl) + min(boy, girl) * 2) == size)
			    {
				    for (int i = 0; i < min(boy, girl); i++)
				    {
					    cout << "BG";
				    }
				    for (int i = 0; i < max(boy, girl) - min(boy, girl); i++)
				    {
					    cout << "B";
				    }
			    }
				else cout << "Impossible";
		    }
		    else
			    if ((max(boy, girl) - min(boy, girl) + (min(boy, girl) - 1) * 2) == size)
			    {
			        for (int i = 0; i < min(boy, girl) - 1; i++)
			        {
				        cout << "BG";
			        }
			        for (int i = 0; i < max(boy, girl) - min(boy, girl); i++)
			        {
				        cout << "G";
			        }
			    }
			    else cout << "Impossible";
	}
	

	return 0;
}
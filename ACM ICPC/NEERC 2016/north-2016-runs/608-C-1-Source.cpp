#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> game(n);
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n;i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n;i++)
	{
		for (int j = i-1; j >= 0;j--)
		{
			if (a[i]>a[j])
			{
				if (game[i].size()==0)
				{
					game[i].push_back(j);
				}
				else
				{
					bool m=true;
					for (int k = 0; k < game[i].size(); k++)
					{
						if (game[i][k] == j){ m = false; break; }
					}
					if (m)
					{
						game[i].push_back(j);
					}
				}
			}
			else
			{
				if (game[j].size() == 0)
				{
					game[j].push_back(i);
				}
				else
				{
					bool m = true;
					for (int k = 0; k < game[j].size(); k++)
					{
						if (game[j][k] == i){ m = false; break; }
					}
					if (m)
					{
						game[j].push_back(i);
					}
				}
			}
			if (b[i]>b[j])
			{
				if (game[i].size() == 0)
				{
					game[i].push_back(j);
				}
				else
				{
					bool m = true;
					for (int k = 0; k < game[i].size(); k++)
					{
						if (game[i][k] == j){ m = false; break; }
					}
					if (m)
					{
						game[i].push_back(j);
					}
				}
			}
			else
			{
				if (game[j].size() == 0)
				{
					game[j].push_back(i);
				}
				else
				{
					bool m = true;
					for (int k = 0; k < game[j].size(); k++)
					{
						if (game[j][k] == i){ m = false; break; }
					}
					if (m)
					{
						game[j].push_back(i);
					}
				}
			}
		}
	}
	for (int i = 0; i < n;i++)
	{
		cout << game[i].size()<<endl;
	}
}
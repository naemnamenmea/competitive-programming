#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n, x, y;
	freopen("boysgirls.in", "r", stdin);
	freopen("boysgirls.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> x >> y;
	int b, g, o;
	o = x + y - n;
	b = x - o;
	g = y - o;
	if (o < 0 || b < 0 || g < 0)
	{
		cout << "Impossible";
		return 0;
	}
	if (o % 2 != 0)
	{
		cout << "Impossible";
		return 0;
	}
	if (o == 0 && b > 0 && g > 0 && (n % 2 != 0 || (n % 2 == 0 && b != g)))
	{
		cout << "Impossible";
		return 0;
	}
	if (o == 2 && n % 2 == 0 && b < n / 2 && g < n / 2)
	{
		cout << "Impossible";
		return 0;
	}
	if (o == n && n % 4 == 2)
	{
		cout << "Impossible";
		return 0;
	}
	string s;
	if (n % 2 != 0)
	{
		if (o == 0)
		{
			if (b == 0)
			{
				for (int i = 0; i < n; i++)
					s.push_back('G');
				cout << s;
				return 0;
			}
			else
			{
				for (int i = 0; i < n; i++)
					s.push_back('B');
				cout << s;
				return 0;
			}
		}
		else
		{
			s = "BG";
			for (int i = 0; i < g; i++)
				s.push_back('G');
			for (int i = 1; i < o / 2; i++)
			{
				s += "BG";
			}
			for (int i = 0; i < b; i++)
				s.push_back('B');
			string arr;
			arr.resize(n);
			for (int i = 0; i < n; i++)
			{
				arr[(i * 2) % n] = s[i];
			}
			cout << arr;
			return 0;
		}
	}
	else
	{
		if (o == 0)
		{
			if (b == g)
			{
				s = "BG";
				for (int i = 1; i < n / 2; i++)
				{
					s += "BG";
				}
				cout << s;
				return 0;
			}
			else
			{
				if (b == 0)
				{
					for (int i = 0; i < n; i++)
						s.push_back('G');
					cout << s;
					return 0;
				}
				else
				{
					for (int i = 0; i < n; i++)
						s.push_back('B');
					cout << s;
					return 0;
				}
			}
		}
		else
		{
			if (o == 2)
			{
				if (g >= n / 2)
				{
					g -= n / 2;
					n = n / 2;
					s = "BG";
					for (int i = 0; i < g; i++)
						s.push_back('G');
					for (int i = 1; i < o / 2; i++)
					{
						s += "BG";
					}
					for (int i = 0; i < b; i++)
						s.push_back('B');
					string arr;
					arr.resize(n * 2);
					for (int i = 0; i < n; i++)
					{
						arr[i * 2] = s[i];
						arr[i * 2 + 1] = 'G';
					}
					cout << arr;
					return 0;
				}
				else
				{
					if (b >= n / 2)
					{
						b -= n / 2;
						n = n / 2;
						s = "BG";
						for (int i = 0; i < g; i++)
							s.push_back('G');
						for (int i = 1; i < o / 2; i++)
						{
							s += "BG";
						}
						for (int i = 0; i < b; i++)
							s.push_back('B');
						string arr;
						arr.resize(n * 2);
						for (int i = 0; i < n; i++)
						{
							arr[i * 2] = s[i];
							arr[i * 2 + 1] = 'B';
						}
						cout << arr;
						return 0;
					}
				}
			}
			else
			{
				int o1, b1, g1;
				n /= 2;
				o1 = min((n / 2) * 2, o - 2);
				b1 = min(b, n - o1);
				g1 = min(g, n - o1 - b1);
				s = "BG";
				for (int i = 0; i < g1; i++)
					s.push_back('G');
				for (int i = 1; i < o1 / 2; i++)
				{
					s += "BG";
				}
				for (int i = 0; i < b1; i++)
					s.push_back('B');
				string arr;
				arr.resize(n * 2);
				for (int i = 0; i < n; i++)
				{
					arr[i * 2] = s[i];
				}
				s = "";
				o = o - o1;
				b = b - b1;
				g = g - g1;
				s = "BG";
				for (int i = 0; i < g; i++)
					s.push_back('G');
				for (int i = 1; i < o / 2; i++)
				{
					s += "BG";
				}
				for (int i = 0; i < b; i++)
					s.push_back('B');
				for (int i = 0; i < n; i++)
				{
					arr[i * 2 + 1] = s[i];
				}
				cout << arr;
				return 0;
			}
		}
	}

	return 0;
}
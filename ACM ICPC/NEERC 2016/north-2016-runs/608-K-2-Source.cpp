
#include <fstream>
using namespace std;

int main()
{
	fstream in, out;
	in.open("king.in", ios::in);
	out.open("king.out", ios::out);
	int d, m, y;
	int day[101], month[101], year[101];
	int n, ans = -1;
	in >> d >> m >> y;
	day[100] = 0;
	month[100] = 0;
	year[100] = 0;
	in >> n;
	if (y - 18 < 0)
		out << -1;
	else
	{
		for (int i = 0; i < n; i++)
		{
			in >> day[i] >> month[i] >> year[i];
			if (year[i] < y - 18 || (year[i] == y - 18 && month[i] < m) || (year[i] == y - 18 && month[i] == m && day[i] <= d))
				// Если наследнику есть восемнадцать
				// Сравниваем его с самым младшим наследником
				if (year[i] > year[100] || (year[i] == year[100] && month[i] > month[100]) || (year[i] == year[100] && month[i] == month[100] && day[i] > day[100]))
				{
				ans = i + 1;
				year[100] = year[i];
				month[100] = month[i];
				day[100] = day[i];
				}
		}
		out << ans;
		in.close();
		out.close();
	}
		return 0;
	}

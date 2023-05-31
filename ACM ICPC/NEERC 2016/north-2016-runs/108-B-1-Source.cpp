#define _USE_MATH_DEFINES
#include<fstream>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<iterator>
#include<algorithm>
#include<iomanip>
#include<tuple>
#include<functional>
#include<forward_list>
#include<cmath>
using namespace std;

int main(){
	ifstream in("boysgirls.in");
	ofstream out("boysgirls.out");

	int n, b, g;
	in >> n >> b >> g;
	vector<char> vec;

	if (b == n && g == 0)
	{
		for (int i = 0; i < n; i++)
			out << 'B';
		return 0;
	}

	if (g == n && b == 0)
	{
		for (int i = 0; i < n; i++)
			out << 'G';
		return 0;
	}

	char c;
	int mmin, mmax;

	if (b >= g)
	{
		vec.assign(n, 'B');
		c = 'G';
		mmax = b;
		mmin = g;
	}
	else
	{
		vec.assign(n, 'G');
		c = 'B';
		mmax = g;
		mmin = b;
	}

	int minc = 2;
	int maxc = n;
	vec[0] = c;

	for (int i = 1; i < n - 1; i++)
	{
		if (minc == mmin && maxc == mmax)
			break;

		if (maxc < mmax || minc > mmin)
		{
			out << "Impossible";
			return 0;
		}

		if (maxc > mmax)
		{
			++i;
			vec[i] = c;
			maxc -= 1;
			minc += 1;
			continue;
		}

		if (i == 1 || vec[i - 2] != c)
		{
			vec[i] = c;
			minc += 2;
			continue;
		}
		else
		{
			i += 2;
			vec[i] = c;
			minc += 2;
		}
	}

	if (maxc != mmax || minc != mmin)
	{
		out << "Impossible";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		out << vec[i];
	}

	return 0;
}
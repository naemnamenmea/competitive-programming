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
	ifstream in("folding.in");
	ofstream out("folding.out");

	int w1, h1, w2, h2;
	in >> w1 >> h1 >> w2 >> h2;

	if ((w2 > w1 && w2 > h1) || (h2 > w1 && h2 > h1) || (w2 > w1 && h2 > w1) || (w2 > h1 && h2 > h1))
	{
		out << "-1";
		return 0;
	}

	if (w2 > w1 || h2 > h1)
		swap(w2, h2);
	
	int n1 = 0, n2 = 0;
	
	while (w1 > w2)
	{
		w1 = w1 / 2 + w1 % 2;
		++n1;
	}

	while (h1 > h2)
	{
		h1 = h1 / 2 + h1 % 2;
		++n2;
	}

	int cnt1 = n1 + n2;
	int cnt2 = 1000000001;
	swap(w2, h2);
	
	if (!((w2 > w1 && w2 > h1) || (h2 > w1 && h2 > h1) || (w2 > w1 && h2 > w1) || (w2 > h1 && h2 > h1)))
	{
		n1 = 0; n2 = 0;

		while (w1 > w2)
		{
			w1 = w1 / 2 + w1 % 2;
			++n1;
		}

		while (h1 > h2)
		{
			h1 = h1 / 2 + h1 % 2;
			++n2;
		}

		cnt2 = n1 + n2;
	}
	out << min(cnt1, cnt2);

	return 0;
}
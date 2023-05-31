#include <iostream>
#include <vector>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	int w, h, ax, ay, bx, by;
	cin >> w >> h >> ax >> ay >> bx >> by;
	if (ax == bx)
	{
		cout << "0 " << ay << " " << w << " " << by;
	}
	else
	{
		cout << ax << " 0 " << bx << " " << h;
	}
	return 0;
}
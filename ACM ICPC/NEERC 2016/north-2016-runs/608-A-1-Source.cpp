#include <fstream>
using namespace std;

int main()
{
	fstream cin, cout;
	cin.open("anniversary.in",ios::in);
	cout.open("anniversary.out",ios::out);
	long w, h;
	long a1, a2,b1,b2;
	cin >> w >> h >>a1>>a2>>b1>>b2;
				if (abs(a1-b1)>=1)
				{
					cout << a1 << " " << 0 << " " << b1 << " " <<h;
				}
				else
				{
					cout << 0 << " " << a2 << " " << w << " " << b2;
				}
				cin.close();
				cout.close();
}
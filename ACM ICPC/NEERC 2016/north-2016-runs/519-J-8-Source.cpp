#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
	ifstream cin("java2016.in");
	ofstream cout("java2016.out");
	int n; cin >> n;
	if (n == 0)
	{
		cout << "? / ? / ?" << endl;
		return 0;
	}
	cout << "a = ? max ?" << endl;
	cout << "b = (a max a max a max a max a max a max a max a max a max a) / (a max a max a max a max a max a max a max a max a)" << endl;
	cout << "c = b + b" << endl;
	cout << "d = c + c" << endl;
	cout << "e = d + d" << endl;
	cout << "f = e + e" << endl;
	cout << "g = f + f" << endl;
	cout << "h = g + g" << endl;
	cout << "i = h + h" << endl;//*/

	int i = 0;
	string s = "";
	while (n != 0)
	{
		if (n % 2 == 1) s += "1";
		else s += "0";
		n /= 2;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != '0') cout << char( int('b')+i );
		if ((i != s.length() - 1) && s[i] != '0') cout << " + ";
	}
	cout << endl;

	//system("pause");
	return 0;
}
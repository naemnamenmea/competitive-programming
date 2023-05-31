#include <fstream>
#include <vector>
using namespace std;
int del(int a,int b)
{
	for (int i = 1; i*i < a; i++)
	{
		if (a%i == 0)
		{
			if (b == (a / i + i))
			{
				return i;
			}
		}
	}
	return -1;
}
int main()
{
	fstream cin, cout;
	cin.open("hard.in",ios::in);
	cout.open("hard.out", ios::out);
	int n;
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		vector<pair<int, int>> resalt;
		int la, lb;
		int a, b;
		cin >> a >> b;
		la = a;
		lb = b;
		if (a == b){
			cout << 1 << endl;
			cout << 0 << " " << 0 << " " << a;
		}
		else{
			int d1, d2;
			d1 = -1;
			d2 = -1;
			while (d1==-1&&d2==-1)
			{
				d1 = del(a,b);
				d2 = del(b, a);
				if (d1==-1&&d2==-1)
				{
					resalt.push_back(make_pair(a>b?b:a,1));
					if (a > b){ a = a - b; b = b; }
					else{ b = b - a; a = a; }
				}
			}
				if (d1!=-1 && d1>d2){
					resalt.push_back(make_pair(a / d1, d1));
					resalt.push_back(make_pair(d1, a / d1));
				
				}
				else
				{
					resalt.push_back(make_pair(b / d2, d2));
					resalt.push_back(make_pair(d2,b / d2));
					
				}
				int x = 0;
				int y = 0;
				int ind = 0;
				for (int i = 0; i < resalt.size(); i++)ind = ind + resalt[i].second;
				cout << ind<<endl;
				for (int i = 0; i < resalt.size();i++)
				{
					for (int j = 0; j < resalt[i].second;j++){
						cout << x << " " << y << " " << resalt[i].first<<endl;
						if (la > lb)
						{
							x = x + resalt[i].first;
						}
						else
						{
							y = y + resalt[i].first;
						}
					}
					if(la>lb)la = la - resalt[i].first*resalt[i].second;
					else lb = lb - resalt[i].first*resalt[i].second;
				}
		}
	}
	cin.close();
	cout.close();
}
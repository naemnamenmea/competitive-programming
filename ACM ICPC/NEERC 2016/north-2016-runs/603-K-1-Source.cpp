#include <fstream>
#include <vector>

using namespace std;

struct child{
	int d, m, y, n;
	child(int d, int  m, int  y, int  n) :d(d), m(m), y(y), n(n) {};
	bool great(child ch){
		if (y > ch.y) return true;
		else
			if (y < ch.y) return false;
			else
				if (m > ch.m) return true;
				else
					if (m < ch.m) return false;
					else
						if (d > ch.d) return true;
						else
							if (d < ch.d) return false;
	}
	bool eq(child ch){
		return (y == ch.y) && (m == ch.m) && (d == ch.d);
	}
};

int main(){
	
	ifstream cin("king.in");
	ofstream cout("king.out");
	
	vector<child> v;

	int d, m, y;
	cin >> d >> m >> y;
	int n;
	cin >> n;
	int d1, m1, y1;
	for (int i = 0; i < n; i++){
		cin >> d1 >> m1 >> y1;
		child ch(d1, m1, y1, i + 1);
		v.push_back(ch);
	}

	for (int i = 0; i < v.size(); i++)
		for (int k = i + 1; k < v.size(); k++){
			if (!v[k - 1].great(v[k])){
				child c = v[k - 1];
				v[k - 1] = v[k];
				v[k] = c;
			}
		}

	for (int i = 0; i < v.size(); i++)
		v[i].y += 18;

	bool goo = false;
	child cdd(d, m, y, 0);
	for (int i = 0; i < v.size(); i++){
		if (cdd.great(v[i]) || cdd.eq(v[i]))
		{
			cout << v[i].n << '\n';
			goo = true;
			break;
		}
	}
	if (!goo)
		cout << "-1\n";
	/*
	for (int i = 0; i < v.size(); i++)
		cout << v[i].d << ' ' << v[i].m << ' '<< v[i].y << '\n';*/
	return 0;
}
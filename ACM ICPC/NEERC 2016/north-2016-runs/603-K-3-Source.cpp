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
		return ((y == ch.y) && (m == ch.m) && (d == ch.d));
	}
};

int main(){
	
	ifstream cin("king.in");
	ofstream cout("king.out");
	
	vector<child> v;

	int d, m, y;
	cin >> d >> m >> y;
	child king(d, m, y, 0);
	v.push_back(king);

	int n;
	cin >> n;

	int d1, m1, y1;

	for (int i = 0; i < n; i++){
		cin >> d1 >> m1 >> y1;
		child ch(d1, m1, y1 + 18, i + 1);
		v.push_back(ch);
	}

	for (int i = 0; i < v.size(); i++)
		for (int k = v.size() - 1; k > i; k--){
		if (v[k - 1].great(v[k])){
			child c = v[k - 1];
			v[k - 1] = v[k];
			v[k] = c;
		}
	}

	int t;
	for (int i = 0; i < v.size(); i++){
		if (v[i].n == 0)
			t = i;
	}

	if (t < v.size() - 1){
		if (v[t + 1].eq(v[t]))
		{
			cout << v[t + 1].n;
			return 0;
		}
	}

	if (t == 0)
		cout << -1;
	else
		cout << v[t-1].n;
	
	return 0;
}
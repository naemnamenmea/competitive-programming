#include <fstream>
#include <vector>

using namespace std;

struct Date {
	int d;
	int m;
	int y;
};

int main() {
	ifstream in("king.in");
	ofstream out("king.out");
	Date king, temp;
	vector<Date> sons;
	int child, count = 0, curr;
	in >> king.d >> king.m >> king.y;
	in >> child;
	for (int i = 0; i < child; i++) {
		in >> temp.d >> temp.m >> temp.y;
		sons.push_back(temp);
	}

	for (int i = 0; i < sons.size(); i++) {
		curr = king.y - sons[i].y;
		if (curr > 18) count++;
		else {
			if (curr == 18) {
				curr = king.m - sons[i].m;
				if (curr > 0) count++;
				else {
					if (curr == 0) {
						curr = king.d - sons[i].d;
						if (curr >= 0) count++;
					}
				}
			}
		}
	}

	if (count == 0) out << "-1";
	else out << count;
	return 0;
}
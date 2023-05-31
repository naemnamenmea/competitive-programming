#include <fstream>
#include <vector>

using namespace std;

struct rate {
	int CC;
	int TF;
	int comp = 0;
};
//
int main() {
	vector<rate> citizens;
	rate temp;
	int n;
	ifstream in("coder.in");
	ofstream out("coder.out");
	in >> n;
	for (int i = 0; i < n; i++) {
		in >> temp.CC >> temp.TF;
		citizens.push_back(temp);
	}

	for (int i = 0; i < citizens.size(); i++) {
		for (int j = i+1; j < citizens.size(); j++) {
			if (citizens[i].CC > citizens[j].CC || citizens[i].TF > citizens[j].TF) citizens[i].comp++;
			if (citizens[j].CC > citizens[i].CC || citizens[j].TF > citizens[i].TF) citizens[j].comp++;
		}
	}
	for (int i = 0; i < citizens.size(); i++){
		out << citizens[i].comp << endl;
	}
	return 0;
}
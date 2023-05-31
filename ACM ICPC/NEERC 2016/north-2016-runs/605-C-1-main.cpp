#include <fstream>
#include <algorithm>

using namespace std;
struct ct{
	long long cc;
	long long tf;
	long long kr;

};


int main(){
	int n = 0;
	ifstream in("codecoder.in");
	ofstream out("codecoder.out");


	in >> n;

	ct* r= new ct[n];
	for (int i = 0; i < n; i++){
		in >> r[i].cc >> r[i].tf;
    }
	int q1 = 0;
	int q2 = 0;
	for (int i = 0; i < n; i++){
		q1 = 0; q2 = 0;
        for (int y = 0; y < n; y++){
			if (r[i].cc > r[y].cc)q1++;
			if (r[i].tf > r[y].tf)q2++;
        }
				if (q1>q2) r[i].kr = q1; else r[i].kr = q2;
    }
	for (int i = 0; i < n; i++)
		out << r[i].kr << "\n";


	return 0;
}
#include <fstream>

using namespace std;
struct ct{
	long long cc;
	long long tf;
	long long kr;
	

};


int main(){
	long n = 0;
	ifstream in("codecoder.in");
	ofstream out("codecoder.out");


	in >> n;
	long long oo;
	ct* r = new ct[n];
	for (int i = 0; i < n; i++){
		in >> r[i].cc >> r[i].tf;
		if (r[i].cc < r[i].tf){ oo = r[i].cc; r[i].cc = r[i].tf; r[i].tf = oo; }
		r[i].kr = 0;
		for (int y = 0; y < i; y++)
		{
			if (r[i].cc>r[y].tf ) r[i].kr++;
			if (r[y].cc > r[i].tf) r[y].kr++;
		}

	}

	for (int i = 0; i < n; i++)
	out << r[i].kr << "\n";

    
	


	return 0;
}
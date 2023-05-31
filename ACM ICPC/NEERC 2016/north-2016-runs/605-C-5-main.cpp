#include <fstream>

using namespace std;
struct ct{
	long long cc;
	long long tf;
	long long kr;
	long long krleft;

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
		r[i].krleft = 0;
	}

	for (int i = 0; i < n - 1; i++){
		for (int y = i + 1; y < n; y++){

		if (r[i].cc>r[y].tf) r[i].kr++;
		if (r[y].cc > r[i].tf) r[y].krleft++;

		}
	out << r[i].kr + r[i].krleft << "\n";
}
    
		out << r[n-1].kr+r[n-1].krleft << "\n";


	return 0;
}
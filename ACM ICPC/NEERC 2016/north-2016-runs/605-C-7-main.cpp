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

	unsigned short* min = new unsigned short[1000001];
	for (int i = 0; i < 1000001; i++) min[i] = 0;
	in >> n;
	long long oo;
	
	ct* r = new ct[n];
	for (int i = 0; i < n; i++){
		in >> r[i].cc >> r[i].tf;
		if (r[i].cc < r[i].tf){ oo = r[i].cc; r[i].cc = r[i].tf; r[i].tf = oo; }
		min[r[i].tf]++;
		r[i].kr = 0;
		/*for (int y = 0; y < i; y++)
		{
			if (r[i].cc>r[y].tf ) r[i].kr++;
			if (r[y].cc > r[i].tf) r[y].kr++;
		}*/

	}

	for (int i = 0; i < n; i++){
		for (int b = r[i].cc; b >= 0; b--)
			if(min[b]>0)
			r[i].kr += min[b];

		r[i].kr--;
		out << r[i].kr<<"\n";
	}
    
	


	return 0;
}
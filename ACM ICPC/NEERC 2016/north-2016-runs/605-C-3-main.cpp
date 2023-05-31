#include <fstream>
#include <algorithm>

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

	ct* r= new ct[n];
	for (int i = 0; i < n; i++){
		in >> r[i].cc >> r[i].tf;
    }
	int q1 = 0;
	int q2 = 0;
	long long miny=0;
	for (int i = 0; i < n; i++){
		q1 = 0; q2 = 0;
        for (int y = 0; y < n; y++){
					if (r[y].cc < r[y].tf) miny = r[y].cc; else miny = r[y].tf;
			if (r[i].cc > miny|| r[i].tf>miny)
				if(y!=i)q1++;
			
        }
				r[i].kr = q1;
    }
	for (int i = 0; i < n; i++)
		out << r[i].kr << "\n";


	return 0;
}
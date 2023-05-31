#include <fstream>
#include <algorithm>

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

	ct* r= new ct[n];
	for (int i = 0; i < n; i++){
		in >> r[i].cc >> r[i].tf;
		r[i].kr = 0;
		r[i].krleft = 0;
    }
	int q1 = 0;
	int q2 = 0;
	long long miny=0;
	long long maxy = 0;
	for (int i = 0; i < n; i++){
		q1 = 0; q2 = 0;
        for (int y = i+1; y < n; y++){
					
					if (r[y].cc < r[y].tf){
						maxy = r[y].tf;
						miny = r[y].cc;
					}
					else {
						miny = r[y].tf;
						maxy = r[y].cc;
					}

					if (r[i].cc > miny || r[i].tf > miny)
						if (y != i)r[i].kr++;
					if (r[i].cc < maxy || r[i].tf < maxy)r[y].krleft++;
			
        }
    }
	for (int i = 0; i < n; i++)
		out << r[i].kr+r[i].krleft << "\n";


	return 0;
}
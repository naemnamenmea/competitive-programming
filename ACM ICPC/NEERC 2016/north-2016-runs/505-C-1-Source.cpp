#include <fstream>

using namespace std;

int main() {
	
	ifstream fin;
	fin.open("codecoder.in");
	
	int n;
	fin >> n;
	int a[100001], b[100001];

	for (int i = 1; i <= n; i++) fin >> a[i] >> b[i];
	
	fin.close();


	ofstream fout;
	fout.open("codecoder.out");
	int rez = 0;
	for (int i = 1; i <= n; i++){
		rez = 0;
		for (int j = 1; j <= n; j++){
			if (i != j)
				if ((a[i] > a[j]) || (b[i] > b[j])) rez++;
		}
		fout << rez;
		if (i != n) fout << endl;
	}

	fout.close();

	return 0;
}
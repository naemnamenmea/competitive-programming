#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
	
	ifstream in("codecoder.in");
	ofstream out("codecoder.out");

	struct rait{ long long cc, tf; int i,kol; };
	bool acompare(rait a, rait b){
		return a.cc < b.cc;
	}
	bool bcompare(rait a, rait b){
		return a.i < b.i;
	}
	int main(){
		int num;
		in >> num;
		vector<rait>cit(num);
		for (int i = 0; i < num; i++){
			cit[i].i = i + 1;
			in >> cit[i].cc >> cit[i].tf;
			cit[i].kol = 0;
		}
		//-------------------Solution
		sort(cit.begin(), cit.end(), acompare);
		for (int i = 0; i < num; i++){
			cit[i].kol = i;
			for (int j = i; j < num; j++){
				if (cit[i].tf > cit[j].tf){
					cit[i].kol++;
				}
			}
		}
		//----------------Out
		sort(cit.begin(), cit.end(), bcompare);
		for (int i = 0; i < num; i++){
			out << cit[i].kol << endl;
		}

		return 0;
	}



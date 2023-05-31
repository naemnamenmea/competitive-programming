// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("codecoder.in");
	out.open("codecoder.out");
	int n;
	vector <long int> mas[100000];
	in >> n;
	for (int i = 0; i < n; i++){
		int a;
		in >> a;
        mas[i].push_back(a);
		in >> a;
        mas[i].push_back(a);
		mas[i].push_back(0);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if ((mas[j][0] < mas[i][0])||(mas[j][1] < mas[i][1])) mas[i][2]++;
		}
		out << mas[i][2] << endl;
	}
	in.close();
	out.close();
	return 0;
}


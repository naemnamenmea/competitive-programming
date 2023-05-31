#include <fstream>
#include <iostream>
using namespace std;
struct date{
	int day;
	int month;
	int year;
	int index;
}; 
date * sort(date* d,int n){
	for (int i = 0; i < n; i++){
		for (int k = i + 1; k < n; k++){
			if (d[i].year	< d[k].year){
				date z = d[i];
				d[i] = d[k];
				d[k] = z;
			}
			else if (d[i].year == d[k].year){
				if (d[i].month	< d[k].month){
					date z = d[i];
					d[i] = d[k];
					d[k] = z;
				}
				else if (d[i].month == d[k].month){
					if (d[i].day	< d[k].day){
						date z = d[i];
						d[i] = d[k];
						d[k] = z;
					}
				}
			}
		}
	}
	return d;
}

bool check(date k, date d){


	if (d.year + 18 < k.year) return true;
	if (d.year + 18 == k.year){
		if (d.month < k.month)return true;
		if (d.month == k.month)
			if (d.day <= k.day)return true;
	}
	return false;

}

int main(){
	date * d = new date[100];
	int dk, mk, yk;
	int n;
	ifstream in("king.in");
	ofstream out("king.out");
	date k;
	in >> k.day >> k.month>> k.year;
	in >> n;
	int c=0;
	for (int i = 0; i < n; i++){
		in >> d[i].day >> d[i].month >> d[i].year;
		d[i].index = i + 1;
	}
	d = sort(d, n);
	/*for (int i = 0; i < n; i++){
		out << d[i].day << " " << d[i].month << " " << d[i].year << endl;

	}*/

	for (int i = 0; i < n; i++){
		if (check(k, d[i])){ out << d[i].index; return 0; }
	}
	out << -1;
		return 0;
}

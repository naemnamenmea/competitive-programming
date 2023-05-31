#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define mp(x, y)  std::make_pair(x, y)
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

struct guy{
	long num;
	long fir;
	long sec;
	long pos_fir;
	long pos_sec;
};

struct clique {
	long first_a;
	long second_a;
	long first_b;
	long second_b;
	long size;
};

bool fir_cmp (const guy& first, const guy& second) {
	return (first.fir < second.fir) || ((first.fir == second.fir) &&(first.sec < second.sec));
}

bool sec_cmp(const guy& first, const guy& second) {
	return (first.sec < second.sec) || ((first.sec == second.sec) && (first.fir < second.fir));
}

bool num_cmp(const guy& first, const guy& second) {
	return first.num < second.num;
}


int main(){
	assert(freopen("codecoder.in", "r", stdin));
	assert(freopen("codecoder.out", "w+", stdout));
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	long n;
	cin >> n;
	//cout << n;
	vector <guy> guys(n);
	for (long i = 0; i < n; ++i) {
		long curr_num = i, curr_fir, curr_sec, curr_pfir = 0, curr_psec = 0;
		cin >> curr_fir >> curr_sec;
		guy curr;
		curr.num = curr_num;
		curr.fir = curr_fir;
		curr.sec = curr_sec;
		curr.pos_fir = curr_pfir;
		curr.pos_sec = curr_psec;
		guys[i] = curr;
	}
	vector<long> a(n);
	vector<long> b(n);
	vector<long> atob(n);
	vector<long> btoa(n);
	vector<long> am(n);
	vector<long> bm(n);
	//cout << endl;

	sort(guys.begin(), guys.end(), fir_cmp);
	for (long i = 0; i < n; ++i) {
		guys[i].pos_fir = i;
		a[i] = guys[i].num;
	}
	sort(guys.begin(), guys.end(), sec_cmp);
	for (long j = 0; j < n; ++j) {
		b[j] = guys[j].num;
		guys[j].pos_sec = j;
	}
	//cout << endl;
	sort(guys.begin(), guys.end(), num_cmp);

	for (long i = 0; i < n; ++i) {
		atob[i] = guys[a[i]].pos_sec;
		btoa[i] = guys[b[i]].pos_fir;
	}
	am[0] = atob[0];
	bm[0] = btoa[0];
	for (long i = 1; i < n; ++i) {
		am[i] = MAX(am[i - 1], atob[i]);
		//cout << am[i] << ' ';
		bm[i] = MAX(bm[i - 1], btoa[i]);
	}
	/*
	for (long i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
	for (long i = 0; i < n; ++i) {
		cout << b[i] << ' ';
	}
	cout << endl;
	for (long i = 0; i < n; ++i) {
		cout << am[i] << ' ';
	}
	cout << endl;
	for (long i = 0; i < n; ++i) {
		cout << bm[i] << ' ';
	}
	cout << endl << endl;
	*/
	long min_a = 0;
	long min_b = 0;
	long max_a = 0;
	long max_b = 0;

	vector<clique> cls;
	while (max_a < n && max_b < n) {
		long cmax_b = am[max_a];
		long cmax_a = bm[max_b];
		while (cmax_a > max_a || cmax_b > max_b) {
			max_a = cmax_a;
			max_b = cmax_b;
			cmax_b = am[max_a];
			cmax_a = bm[max_b];
		}
		clique cl;
		cl.first_a = min_a;
		cl.first_b = min_b;
		cl.second_a = max_a;
		cl.second_b = max_b;
		cl.size = 0;
		cls.push_back(cl);
		if (max_a < n) {
			min_a = max_a + 1;
			max_a = min_a;
			min_b = max_b + 1;
			max_b = min_b;
		}
	}
	/*
	cout << endl;
	for (long i = 0; i < cls.size(); ++i) {
		cout << cls[i].first_a << ' ' << cls[i].first_b << ' ' << cls[i].second_a 
			<< ' ' << cls[i].second_b << endl;
	}
	cout << endl;
	*/
	vector<long> sizes(n);
	vector<long> to_clique(n);

	for (long i = 0; i < cls.size(); ++i) {
		cls[i].size = cls[i].second_a - cls[i].first_a + 1;
		for (long j = cls[i].first_a; j < cls[i].second_a + 1; ++j) {
			to_clique[j] = i;
		}
	}
	long sum = 0;
	vector <long> sumsizes(n);
	for (long i = 0; i < cls.size(); ++i) {
		sum += cls[i].size;
		sumsizes[i] = sum;
	}
	for (long i = 0; i < n; ++i) {
		//cout << to_clique[guys[i].pos_fir] << ' ';
		cout << sumsizes[to_clique[guys[i].pos_fir]] - 1 << endl;
	}

	return 0;
}
	
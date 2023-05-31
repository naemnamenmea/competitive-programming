#pragma once

#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;

using Row = vector<int>;
using Matrix = vector<Row>;

ll fact(ll x) {
	if (x < 0) {
		throw runtime_error("Factorial from negative value");
	}
	else if (x == 0) {
		return 1;
	}

	return x * fact(x - 1);
}

ll C(double n, double k) {
	if (k > n) {
		throw runtime_error("C_n^k, where k>n");
	}
	return fact(n) / fact(k) / fact(n - k);
}

void gen_comb(Row& comb, int n) {
	int len = comb.size();
	int i = len - 1;
	for (; i >= 0 && comb[i] == n - len + i + 1; --i);
	if (i < 0) {
		return;
	}
	++comb[i];
	for (++i; i < len; ++i) {
		comb[i] = comb[i - 1] + 1;
	}
}

class Solution {
public:
	static Matrix solution(int n, int m) {
		size_t keys_count = m == 0 ? 0 : C(n, m - 1);

		m = m == 1 ? n : m == n ? 1 : m;

		Row comb(m);
		Matrix res(n);
		iota(begin(comb), end(comb), 1);

		for (int i = 0; i < keys_count; ++i) {
			for (int j = 0; j < m; ++j) {
				res[comb[j] - 1].push_back(i);
			}
			gen_comb(comb, n);
		}

		return res;
	}
};
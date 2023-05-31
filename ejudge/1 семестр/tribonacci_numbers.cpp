#if !defined(LOCAL_LAUNCH) || defined(tribonacci_numbers)

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>

#ifdef LOCAL_LAUNCH
#include <fstream>
#include <experimental/filesystem>

#include "numeric_math.hpp"
#include "pretty_print.h"

namespace fs = std::experimental::filesystem;
#endif

constexpr auto EPS = 1e-9;

typedef unsigned long long ull;

using namespace std;

template<class T>
vector<vector<T>> operator*(
  const vector<vector<T>>& a, const vector<vector<T>>& b
  ) {
  if (a.size() == 0 || a[0].size() != b.size())
    throw runtime_error("matrix cannot be multiplied");

  vector<vector<T>> res(a.size(), vector<T>(b[0].size()));

  for (size_t i = 0; i < a.size(); ++i) {
    for (size_t j = 0; j < b[0].size(); ++j) {
      res[i][j] = 0;
      for (size_t k = 0; k < a[0].size(); ++k) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return res;
}

template<class T>
void operator*=(
  vector<vector<T>>& a, const vector<vector<T>>& b
  ) {
  a = a * b;
}

template<class T>
vector<vector<T>> quick_pow_square_matrix(const vector<vector<T>>& m, unsigned int n) {

  if (m.size() == 0 || m.size() != m[0].size())
    throw runtime_error("non square matrix");

  vector<vector<T>> res(m.size(), vector<T>(m.size()));
  vector<vector<T>> tmp(m);

  for (size_t i = 0; i < res.size(); ++i) {
    res[i][i] = 1;
  }

  while (n) {
    if (n & 1)
      res *= tmp;
    tmp *= tmp;
    n >>= 1;
  }

  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  //ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int n;
  cin >> n;

  if (n < 2) {
    cout << 0;
    return 0;
  }

  vector<vector<ull>> coeff = {
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 1},
  };

  vector<vector<ull>> members = {
    {0},
    {0},
    {1},
  };

  coeff = quick_pow_square_matrix(coeff, n - 2);

  members = coeff * members;

  cout << members[2][0] << endl;

  return 0;
}

#endif // tribonacci_numbers
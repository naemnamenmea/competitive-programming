#if !defined(LOCAL_LAUNCH) //|| defined(A_31_03_2017)

#include <iostream>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>

#ifdef LOCAL_LAUNCH
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
	ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

	

	return 0;
}

#endif // A_31_03_2017
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ifstream in("folding.in");
	ofstream out("folding.out");
	const int x = 0;
	const int y = 1;
	vector<int> input(2);
	vector<int> output(2);
	in >> input[x] >> input[y];
	in >> output[x] >> output[y];
	sort(input.begin(), input.end(), [](int a, int b) { return a > b; });
	sort(output.begin(), output.end(), [](int a, int b) { return a > b; });
	if (input[x] < output[x] || input[y] < output[y]) {
		out << "-1";
		return 0;
	}
	int timesX = (input[x] == output[x]) ? 0 : (int)(log(input[x]) / log(output[x]));
	int timesY = (input[y] == output[y]) ? 0 : (int)(log(input[y]) / log(output[y]));
	out << timesX + timesY;
	return 0;
}
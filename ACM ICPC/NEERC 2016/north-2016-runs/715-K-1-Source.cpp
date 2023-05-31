#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	ifstream fin("king.in");
	ofstream fout("king.out");

	int d, m, y;
	int ds, ms, ys;
	int maxD = 0, maxS = 0, maxY = 0;
	int maxBirth = 0;
	int N;
	int heir = -1;

	fin >> d >> m >> y;
	fin >> N;
	int death = y * 10000 + m * 100 + d, birth;
	for (int i = 1; i <= N; i++)
	{
		fin >> ds >> ms >> ys;
		birth = ys*10000 + ms*100 + ds;
		if ((death - 180000 >= birth) && (birth > maxBirth)) {
			heir = i;
			maxBirth = birth;
		}
	}

	fout << heir;
	return 0;
}
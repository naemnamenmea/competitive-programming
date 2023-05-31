#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	FILE *f;

	f = fopen("codecoder.in", "r");
    
	int N, c, t;
	fscanf(f, "%d", &N);

	int a[100000];
	int b[100000];

	for (int i = 0; i < N; i++)
	{
		fscanf(f, "%d %d", &c, &t);
		a[i] = c;
		b[i] = t;
	}

	ofstream out("codecoder.out");

	int sum;
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = 0; j < N; j++)
			if (a[i] > a[j] || b[i] > b[j])
				sum++;
		out << sum << endl;
	}
    
	fclose(f);
	out.close();
	return 0;
}
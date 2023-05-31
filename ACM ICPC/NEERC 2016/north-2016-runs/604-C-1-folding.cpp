#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define endl "\n"

//#define Debug

struct Type
{
	int posC, posT, pos, pos0;
};

struct Tp
{
	int val, pos;
};

int main()
{
#ifdef Debug
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
#endif

	int n;

	cin >> n;

	vector<Type> scoreC(n);
	vector<Type> scoreT(n);
	for (int i = 0; i < n; i++)
	{
		cin >> scoreC[i].posC >> scoreC[i].posT;
		scoreT[i].posC = scoreC[i].posC;
		scoreT[i].posT = scoreC[i].posT;
		scoreC[i].pos0 = i;
	}

	sort(scoreC.begin(), scoreC.end(), [](Type a, Type b){return a.posC < b.posC; });
	sort(scoreT.begin(), scoreT.end(), [](Type a, Type b){return a.posT < b.posT; });


	for (int i = 0; i < n; i++)
	{
		scoreT[i].pos = i;
		scoreC[i].pos = i;
	}
	vector<Tp> maxC(n);
	vector<Tp> maxT(n);
    
	maxC[0].val = scoreT[0].posC;
	maxT[0].val = scoreC[0].posT;
	maxC[0].pos = 0;
	maxT[0].pos = 0;

	for (int i = 1; i < n; i++)
	{
		if (maxC[i - 1].val > scoreT[i].posC) {
			maxC[i].val = maxC[i - 1].val;
			maxC[i].pos = maxC[i - 1].pos;
		}
		else
		{
			maxC[i].val = scoreT[i].posC;
			maxC[i].pos = i;
		}

		if (maxT[i - 1].val > scoreC[i].posT) {
			maxT[i].val = maxT[i - 1].val;
			maxT[i].pos = maxT[i - 1].pos;
		}
		else
		{
			maxT[i].val = scoreC[i].posT;
			maxT[i].pos = i;
		}
	}

	vector<int> d(n, -1);
	map<int, int> mT;

	for (int i = 0; i < n; i++)
	{
		mT[scoreT[i].posT] = scoreT[i].pos;
	}
	for (int i = 0; i < n; i++)
	{
		int tPr = 0;
		int cPr = 0;

		
		int t = mT[maxT[i].val];
		int c = cPr;

		while (1)
		{
			if (maxC[t].pos <= c)
				break;
			else
			    c = maxC[t].pos;
            
			if (maxT[c].pos <= t)
				break;
			else
			    t = maxT[c].pos;
		}

		int l;

		if (t == max(t, c))
		{
			if (t <= scoreC[i].posT)
				l = max(t, c);
			else
				l = max(t, c) - 1;
		}

		if (c == max(t, c))
		{
			if (c <= scoreC[i].posC)
				l = max(t, c);
			else
				l = max(t, c) - 1;
		}

		d[scoreC[i].pos0] = l;
	}

	for (int i = 0; i < n; i++)
		cout << d[i] << endl;

    return 0;
}
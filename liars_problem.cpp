//#define liars

#ifdef liars

#include <bits/stdc++.h>

using namespace std;

int cp_liars_problem(int n, int l[], int r[]) {
	vector<vector<int>> graph(n, vector<int>(n, -1));

	for (int i = 0; i < n + 1; ++i) {
		for (int j = i + 1; j < n + 1; ++j) {
			int k = 0;
			for (int g = 0; g < n; ++g) {
				if (l[i] == i && r[i] == n - j) {
					++k;
				}
				int w = max(j - i - k, 0);
				graph[i][j] = w;
			}
		}
	}
	//auto partitionList = Graph::shortestPath(graph, 0, n);

	//int maxTruthful = 0;
	//auto it = partitionList.begin();
	//int il = *it++;
	//for (; it != partitionList.end(); ++it) {
	//	int ir = *it;
	//	for (int i= il; i < ir; ++i) {
	//		if (l[i] == il && r[i] == n - ir)
	//			++maxTruthful;
	//	}
	//	il = ir;
	//}

	//cout << maxTruthful << endl;

	return -1;
}

#endif
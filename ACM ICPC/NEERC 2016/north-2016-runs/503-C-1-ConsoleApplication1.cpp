#include <algorithm>
#include <iostream>

using namespace std;

struct man {
	long long CC, TF, group, nom, bi;
};

bool eq(man a, man b) {
	return (a.CC > b.CC && b.TF > a.TF) || (a.TF > b.TF && b.CC > a.CC);
}

bool lrg(man a, man b) {
	return (a.CC > b.CC || a.TF > b.TF) && !eq(a, b);
}

bool sml(man a, man b) {
	return lrg(b, a);
}

bool ns(man a, man b) {
	return a.nom < b.nom;
}

int qs(const void* a, const void* b) {
	return (eq((*(man*)a), *(man*)b) ? 0 : lrg(*(man*)a, *(man*)b) ? 1 : -1);
}
int main()
{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	long long n, gn, sum = 0;
	man a[100000];
	long long kg[100000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].CC >> a[i].TF;
		a[i].nom = i;
	}

	qsort(a, n, sizeof(int), qs);

	gn = 1;
	a[0].group = 1;
	kg[0] = 1;
	for (int i = 1; i < n; i++) {
		if (lrg(a[i], a[i - 1])) {
			gn++;
			a[i].group = gn;
			kg[gn] = 1;
		}
		else {
			a[i].group = n;
			kg[gn]++;
		}
	}

	sum = 1;
	a[0].bi = 1;
	for (int i = 1; i < n; i++) {
		sum += kg[a[i].group];
		a[i].bi = sum;
	}

	sort(a, a + n, ns);

	for (int i = 0; i < n; i++) {
		cout << a[i].bi << endl;
	}

	return 0;
}


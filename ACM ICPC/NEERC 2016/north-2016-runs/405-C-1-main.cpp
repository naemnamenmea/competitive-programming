#include <bits/stdc++.h>

using namespace std;
                   
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int n;
pii mas1[100005], mas2[100005];
int l, r, curl, curr;
int pos1[100005], pos2[100005];
int ans;
char was[100005];
int A[100005];

void add (int v) {
	if (was[v]) return;
	was[v] = 1;
	ans++;
}

void go1 () {
	while (l < curl) {
		add (mas1[l].second);
		curr = max (curr, pos2[mas1[l].second]);
		l++;
	}
}

void go2 () {
	while (r < curr) {
		add (mas2[r].second);
		curl = max (curl, pos1[mas2[r].second]);
		r++;	
	}	
}

int main () {                   
	freopen ("codecoder.in", "r", stdin);
	freopen ("codecoder.out", "w", stdout);

	ios_base::sync_with_stdio (false);

    cin >> n;

    for (int i = 0; i < n; i++) {
    	cin >> mas1[i].first >> mas2[i].first;
    	mas1[i].second = mas2[i].second = i;
    }
                          
    sort (mas1, mas1 + n);
    sort (mas2, mas2 + n);

    for (int i = 0; i < n; i++) {
    	pos1[mas1[i].second] = i;
    	pos2[mas2[i].second] = i;
    } 

    for (int i = 0; i < n; i++) {
    	curl = max (curl, i);
    	curr = max (curr, pos2[mas1[i].second]);
    	while (l < curl || r < curr) {
    		go1 ();
    		go2 ();
    	}
    	A[mas1[i].second] = ans - was[mas1[i].second];
    }

    for (int i = 0; i < n; i++) {
    	cout << A[i] << '\n';
	}

	return 0;
}
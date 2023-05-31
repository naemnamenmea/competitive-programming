#include <bits/stdc++.h>

using namespace std;

#define filename "king"

int y[100];
int m[100];
int d[100];

bool lower(int d1, int m1, int y1, int d2, int m2, int y2){
    return (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 <= d2));
}

int main(){
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);

	int n, dy, dm, dd;

	cin >> dd >> dm >> dy >> n;

	for(int i = 0; i < n; i++){
        cin >> d[i] >> m[i] >> y[i];
	}

	int ans = -2;
    int ansd = -1;
    int ansm = -1;
    int ansy = -1;

	for(int i = 0; i < n; i++){
        if (lower(d[i], m[i], y[i], dd, dm, dy - 18)){
            if (lower(ansd, ansm, ansy, d[i], m[i], y[i])){
                ans = i;
                ansd = d[i];
                ansm = m[i];
                ansy = y[i];
            }
        }
	}

	cout << (ans + 1);
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define filename "integral"

long long x[205000], y[200500];
int d[2][2][2];
long long s[200500];
long long p[200500];

int main(){
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        x[i] = (x[i] % 2 + 2) % 2;
        y[i] = (y[i] % 2 + 2) % 2;
    }
    x[n] = x[0];
    y[n] = y[0];
    for (int i = 1; i <= n; i++)
        s[i] = x[i - 1] * y[i] + y[i - 1] * x[i];
    for (int i = 0; i < n; i++){
        if (i == 0)
            p[0] = s[1];
        else
            p[i] = p[i - 1] + s[i + 1];
        if (p[i] % 2 == 0)
            d[0][(x[i + 1] & 1)][(y[i + 1] & 1)]++;
        else
            d[1][(x[i + 1] & 1)][(y[i + 1] & 1)]++;
        //cout <<"# " << i + 1 << " " << (p[i] % 2  != 0) << " " << (x[i + 1] & 1) << " " << (y[i + 1] & 1) << endl;
    }
    if (p[n - 1] % 2 != 0){
        cout << 0;
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int p1 = 0; p1 < 2; p1++)
            for (int x1 = 0; x1 < 2; x1++)
                for (int y1 = 0; y1 < 2; y1++){
                    if ((p[(i - 1 + n) % n] + p1 + x[i] * y1 + y[i] * x1) % 2 == 0){
                        ans += d[p1][x1][y1];
                        //if (d[p1][x1][y1] != 0)
                        //cout << i << " " <<p1 << " " << x1 << " " << y1 << " " <<d[p1][x1][y1] << endl;
                    }
        }
    //cout << ans << endl;
    cout << (ans - 3 * n) / 2;
	return 0;
}

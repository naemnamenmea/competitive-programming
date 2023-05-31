#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin v.end
#define pb push_back
#define F first
#define S second

const int MAXN = 1e5 + 7;

int dim[13];

int vozr(int d, int m, int y)
{
    int s = 0;
    s += y * 365;
    for (int i = 1; i < m; i++)
    {
        s += dim[i];
    }
    s += d;
    return s;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);
    int d, m, y;
    int king;
    int son[105];
    dim[1] = 31;
    dim[2] = 28;
    dim[3] = 31;
    dim[4] = 30;
    dim[5] = 31;
    dim[6] = 30;
    dim[7] = 31;
    dim[8] = 31;
    dim[9] = 30;
    dim[10] = 31;
    dim[11] = 30;
    dim[12] = 31;
    cin >> d >> m >> y;
    king = vozr(d, m, y);
    int n;
    cin >> n;
    //cout << king << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> d >> m >> y;
        son[i] = vozr(d, m, y);
        //cout << son[i] << " ";
        son[i] = king - son[i];
        //cout << son[i] << endl;
    }
    int mi = 1e9, z = -1;
    for (int i = 1; i <= n; i++)
    {
        if (son[i] >= 18 * 365 && son[i] < mi)
        {
            mi = son[i];
            z = i;
        }
    }
    cout << z;
    return 0;
}


#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("king.in" , "r", stdin);
    freopen("king.out" , "w", stdout);

    int d, m ,y, n, young = -1, youngdate = 0;



    cin >> d >> m >> y;
    cin >> n;
    int date = (y - 18) * 10000 + m * 100 + d;

    for (int i = 1; i < n + 1; i++){
        int d1,y1,m1;
        cin >> d1 >> m1 >> y1;
        int a =  y1 * 10000 + m1 * 100 + d1;

        if (a <= date && a > youngdate) {
            young = i;
            youngdate = a;
        }
    }

    cout << young;
    return 0;
}

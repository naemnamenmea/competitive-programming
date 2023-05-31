#include <iostream>
#include <vector>
#include <complex>

using namespace std;

int main ()
{
    freopen ("anniversary.in", "r", stdin);
    freopen ("anniversary.out", "w", stdout);

    int h, w, x1, y1, x2, y2;

    cin >> w >> h >> x1 >> y1 >> x2 >> y2;

    cout << x1 << ' ' << h << ' ' << x2 << " 0";

    return 0;
}

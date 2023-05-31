#include <iostream>

using namespace std;

int main()
{
    long long c1_x, c2_x, c2_y, c1_y;
    long long w, h;
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);
    cin >> w;
    cin >> h;
    cin >> c1_x;
    cin >> c1_y;
    cin >> c2_x;
    cin >> c2_y;
    long long diff_y, diff_x;
    diff_x = abs(c1_x - c2_x);
    diff_y = abs(c1_y - c2_y);
    long long cut1_x, cut1_y, cut2_x, cut2_y;
    if (diff_x >= 2) {
        if (c2_x > c1_x) {
            cut1_x = c1_x + 1;
            cut2_x = cut1_x;
            cut1_y = 0;
            cut2_y = h;
        } else {
            cut1_x = c2_x + 1;
            cut2_x = cut1_x;
            cut1_y = 0;
            cut2_y = h;
        }
    } else if (diff_y >= 2) {
        if (c2_y > c1_y) {
            cut1_y = c1_y + 1;
            cut2_y = cut1_y;
            cut1_x = 0;
            cut2_x = w;
        } else {
            cut1_y = c2_y + 1;
            cut2_y = cut1_y;
            cut1_x = 0;
            cut2_x = w;
        }
    } else {
        if (c1_x < c2_x) {
            cut1_x = c1_x;
            cut1_y = 0;
            cut2_x = c2_x;
            cut2_y = h;
        } else {
            cut1_x = c2_x;
            cut1_y = 0;
            cut2_x = c1_x;
            cut2_y = h;

        }
    }

    cout << cut1_x << " " << cut1_y << " " << cut2_x << " " << cut2_y << endl;




    return 0;
}

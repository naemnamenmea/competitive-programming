#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

pair<int, int> arrt[100010];
int n;

int tri_area(int x, int y) {
    return x * y / 2;
}

int poly_area(pair<int, int> a[], int b_x, int b_y) {
    int max_x = 0;
    int max_y = 0;
    for (int i = 0; i < n; i++) {
        int check_x = a[i].first;
        int check_y = a[i].second;
        if (check_x > max_x)
            max_x = check_x;
        if (check_y > max_y)
            max_y = check_y;
    }
    long long ar = abs(max_x - b_x) * abs(max_y - b_y);
    for (int i = 0; i < n; i++) {
        if ((a[i].first > b_x) && (a[i].second > b_y)) {
            ar -= (abs(a[i].first - b_x) * (a[i].second - b_y));
        }
        if (i = n - 1) {
            int x = abs(a[i].first - a[0].first);
            int y = abs(a[i].second - a[0].second);
            ar -= tri_area(x, y);
        } else {
            int x = abs(a[i].first - a[i + 1].first);
            int y = abs(a[i].second - a[i + 1].second);
            ar -= tri_area(x, y);
        }
    }
}

int main()
{
    freopen("integral.in", "r", stdin);
    freopen("integral.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        arrt[i].first = a;
        arrt[i].second = b;
    }
    cout << poly_area(arrt, 0, 0);
    return 0;
}

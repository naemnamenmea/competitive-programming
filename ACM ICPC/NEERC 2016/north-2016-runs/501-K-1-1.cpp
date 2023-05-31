#include <bits/stdc++.h>

using namespace std;

#define TASK "king"

int main() {
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int d, m, y;
    cin >> d >> m >> y;
    int n;
    int res = 0;
    cin >> n;
    int id = -1;
    tuple<int, int, int> ans;
    for (int i = 0; i < n; ++i)
    {
        int dd, mm, yy;
        cin >> dd >> mm >> yy;
        int v = y - yy;
        if (make_pair(mm, dd) > make_pair(m, d)) v--;
        if (v >= 18)
        {
            if (id == -1 || ans < make_tuple(yy, mm, dd)) ans = make_tuple(yy, mm, dd), id = i + 1;
        }
    }
    printf("%d\n", id);

    return 0;
}
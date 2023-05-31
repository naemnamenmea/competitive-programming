#include <bits/stdc++.h>

using namespace std;

struct date {
    int d, m, y, ind;
};

bool operator<=(date a, date b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    if (a.d != b.d) return a.d < b.d;
    return true;
}

date read(int i) {
    date a;
    scanf("%d%d%d", &a.d, &a.m, &a.y);
    a.ind = i;
    return a;
}

int main() {
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);

    auto king = read(-1);
    king.y -= 18;

    date ans = {-1, -1, -1, -1};

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        date x = read(i);
        if (x <=king) {
            if (ans.ind < 0 || ans <= x) {
                ans = x;
            }
        }
    }
    cout << ans.ind << endl;
    
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("king.in", "r", stdin); freopen("king.out", "w", stdout);

    int dk, mk, yk;
    cin >> dk >> mk >> yk;

    int n;
    cin >> n;

    int d, m, y;
    int d_ans = -1, m_ans = -1, y_ans = -1;

    int ans = -2;

    for (int i = 0; i < n; i++) {
        bool good = true;
        cin >> d >> m >> y;

        if (y + 18 < yk) {
            if (y > y_ans || (y == y_ans && m > m_ans) || (y == y_ans && m == m_ans && d > d_ans)) {
                ans = i;
                y_ans = y;
                m_ans = m;
                d_ans = d;
            }
            continue;
        }

        if (y + 18 > yk) {
            continue;
        }

        if (m < mk) {
            if (y > y_ans || (y == y_ans && m > m_ans) || (y == y_ans && m == m_ans && d > d_ans)) {
                ans = i;
                y_ans = y;
                m_ans = m;
                d_ans = d;
            }
            continue;
        }

        if (m > mk) {
            continue;
        }

        if (d <= dk) {
            if (y > y_ans || (y == y_ans && m > m_ans) || (y == y_ans && m == m_ans && d > d_ans)) {
                ans = i;
                y_ans = y;
                m_ans = m;
                d_ans = d;
            }
            continue;
        }
    }

    cout << ans + 1;

    return 0;
}

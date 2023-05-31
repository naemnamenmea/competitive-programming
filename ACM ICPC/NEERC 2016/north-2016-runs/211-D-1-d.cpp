#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second

vector<int> v[3];
int q[10][110];
int dp[110][10][10][2];
pair<pair<int, int>, int> p[110][10][10][2];
int
numbers[5][10][2] = {{{1}, {0}, {1}, {1}, {0}, {1}, {1}, {1}, {1}, {1}},
                {{1, 1}, {0, 1}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {1, 1}, {1, 1}},
                {{0}, {0}, {1}, {1}, {1}, {1}, {1}, {0}, {1}, {1}},
                {{1, 1}, {0, 1}, {1, 0}, {0, 1}, {0, 1}, {0, 1}, {1, 1}, {0, 1}, {1, 1}, {1, 1}},
                {{1}, {0}, {1}, {1}, {0}, {1}, {1}, {0}, {1}, {1}}};

bool check(const int (&a)[3], const int (&b)[3], const int (&line_beetwen)[4]) {
//    return true;
    return line_beetwen[0] == (numbers[1][a[0]][1] | numbers[1][b[0]][0])
        && line_beetwen[1] == (numbers[3][a[0]][1] | numbers[3][b[0]][0] |
                    numbers[1][a[1]][1] | numbers[1][b[1]][0])
        && line_beetwen[2] == (numbers[3][a[1]][1] | numbers[3][b[1]][0] |
                    numbers[1][a[2]][1] | numbers[1][b[2]][0])
        && line_beetwen[3] == (numbers[3][a[2]][1] | numbers[3][b[2]][0]);
}

bool check1(const int (&a)[3], int const (&line_beetwen)[4]) {
//    for (int i = 0; i < 4; i++)
//        cout << line_beetwen[i] << ' ';
//    cout << "\n";
//    cout << numbers[1][a[0]][1] << "\n";
//    cout << numbers[3][a[0]][1] << ' ' << numbers[1][a[1]][1] << "\n";
//    cout << numbers[3][a[1]][1] << ' ' << numbers[1][a[2]][1] << "\n";
//    cout << numbers[3][a[1]][1] << "\n";
    return line_beetwen[0] == (numbers[1][a[0]][0])
        && line_beetwen[1] == (numbers[3][a[0]][0] |
                    numbers[1][a[1]][0])
        && line_beetwen[2] == (numbers[3][a[1]][0] |
                    numbers[1][a[2]][0])
        && line_beetwen[3] == (numbers[3][a[2]][0]);
}

bool check(const int (&a)[3], const int (&line_beetwen)[5]) {
    return line_beetwen[0] == (numbers[0][a[0]][0])
        && line_beetwen[1] == (numbers[2][a[0]][0] | numbers[0][a[1]][0])
        && line_beetwen[2] == (numbers[4][a[0]][0] | numbers[2][a[1]][0] | numbers[0][a[2]][0])
        && line_beetwen[3] == (numbers[4][a[1]][0] | numbers[2][a[2]][0])
        && line_beetwen[4] == numbers[4][a[2]][0];
}

int main() {
//    freopen("input.txt", "r", stdin);
    freopen("digital.in", "r", stdin);
    freopen("digital.out", "w", stdout);
    int w;
    cin >> w;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < w + i % 2; j++)
            cin >> q[i][j];
    }
//    for (int i = 0; i < 9; i++) {
//        for (int j = 0; j < w + i % 2; j++)
//            cout << q[i][j] << ' ';
//            cout << "\n";
//    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int sum = (i + j) % 10;
            if (
                check({i, j, sum}, {7, 7, 7}, {q[1][w], q[3][w], q[5][w], q[7][w]})
                &&
                check({i, j, sum}, {q[0][w - 1], q[2][w - 1], q[4][w - 1], q[6][w - 1], q[8][w - 1]})
){
//                cout << i << ' ' << j << "\n";
//
                dp[w - 1][i][j][0] = 1;
                }
        }
    }
//    cout << w << "\n";
    for (int i = w - 2; i >= 0; i--) {
        for (int l = 0; l < 10; l++)
        for (int r = 0; r < 10; r++) {
            for (int ll = 0; ll < 10; ll++)
            for (int rr = 0; rr < 10; rr++) {
                for (int add = 0; add < 2; add++) {
                    int sumllrr = (ll + rr + add) % 10;
                    int lradd = (ll + rr + add) / 10;
                    int sumlr = (l + r + lradd) % 10;
                    if (
                        dp[i + 1][ll][rr][add]
                    &&
                    check({l, r, sumlr}, {ll, rr, sumllrr}, {q[1][i + 1], q[3][i + 1], q[5][i + 1], q[7][i + 1]})
                    && check({l, r, sumlr}, {q[0][i], q[2][i], q[4][i], q[6][i], q[8][i]})) {
//                        cout << l << ' ' << r << ' ' << lradd << "\n";
                        dp[i][l][r][lradd] = 1;
                        p[i][l][r][lradd] = {{ll, rr}, add};
                    }
                }
            }
        }
    }

    for (int l = 0; l < 10; l++)
    for (int r = 0; r < 10; r++) {
        for (int add = 0; add < 2; add++) {
//    int l = 3, r = 3, add = 1;

            if (l + r + add < 10
                &&
                check1({l, r, l + r + add}, {q[1][0], q[3][0], q[5][0], q[7][0]})
                ) {
                for (int cur = 0; cur < w; cur++) {
                    v[0].pb(l);
                    v[1].pb(r);
                    v[2].pb((l + r + add) % 10);
                    int ll = p[cur][l][r][add].fi.fi;
                    int rr = p[cur][l][r][add].fi.se;
                    int llrradd = p[cur][l][r][add].se;
                    l = ll;
                    r = rr;
                    add = llrradd;
                }
                for (auto x : v[0])
                    cout << x;
                cout << "\n";
                for (auto x : v[1])
                    cout << x;
                cout << "\n";
                for (auto x : v[2])
                    cout << x;
                cout << "\n";
                return 0;
                }
            }
    }
    cout << "NO";
    return 0;

}

#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int) (x).size())
#define bend(x) (x).begin(), (x).end()
#define puba push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXL = 505, MAXN = 105;

int field[9][MAXL];
int d[2][MAXN][10][10][10];
tuple<int, int, int, int> from[2][MAXN][10][10][10];
vector<vector<pii>> where = {
{{0, 1}, {1, 0}, {1, 2}, {3, 0}, {3, 2}, {4, 1}},
{{1, 2}, {3, 2}},
{{0, 1}, {1, 2}, {2, 1}, {3, 0}, {4, 1}},
{{0, 1}, {1, 2}, {2, 1}, {3, 2}, {4, 1}},
{{1, 0}, {1, 2}, {2, 1}, {3, 2}},
{{0, 1}, {1, 0}, {2, 1}, {3, 2}, {4, 1}},
{{0, 1}, {1, 0}, {2, 1}, {3, 0}, {3, 2}, {4, 1}},
{{0, 1}, {1, 2}, {3, 2}},
{{0, 1}, {1, 0}, {1, 2}, {2, 1}, {3, 0}, {3, 2}, {4, 1}},
{{0, 1}, {1, 0}, {1, 2}, {2, 1}, {3, 2}, {4, 1}}
};

int can(int d, int pos, int row) {
    int sx = row * 2;
    int sy = pos * 2;
    for (auto p: where[d]) {
        if (!field[sx + p.ff][sy + p.ss]) {
            return 0;
        }
    }
    return 1;
}

int now[9];
int nnow[9];
int masks[MAXL];
int dmask[10][3];

int main() {
    freopen("digital.in", "r", stdin);
    freopen("digital.out", "w", stdout);

    for (int i = 0; i < 10; ++i) {
        for (auto p: where[i]) {
            dmask[i][p.ss] |= (1 << p.ff);
        }
    }
    
    int w;
    scanf("%d", &w);

    for (int i = 0; i < 9; ++i) {
        if (i & 1) {
            for (int j = 0; j < w * 2 + 1; j += 2) {
                scanf("%d", &field[i][j]);
            }
        } else {
            for (int j = 1; j < w * 2 + 1; j += 2) {
                scanf("%d", &field[i][j]);
            }
        }
    }
    
    for (int i = 0; i < w * 2 + 1; ++i) {
        for (int j = 0; j < 9; ++j) {
            masks[i] |= (field[j][i] << j);
        }
    }
    
    /*
    for (int j = 0; j < 9; ++j) {
        for (int i = 0; i < w * 2 + 1; ++i) {
            cerr << field[j][i];
        }
        cerr << endl;
    }*/

    d[0][w][0][0][0] = 1;

    for (int i = w - 1; i >= 0; --i) {
        for (int d1 = 0; d1 < 10; ++d1) {
            for (int d2 = 0; d2 < 10; ++d2) {
                for (int d3 = 0; d3 < 10; ++d3) {
                    if (can(d1, i, 0) && can(d2, i, 1) && can(d3, i, 2)) {
                        
                        if (masks[i * 2 + 1] != (dmask[d1][1] | (dmask[d2][1] << 2) | (dmask[d3][1] << 4))) {
                            continue;
                        }
                        
                        
                        int nmask = (dmask[d1][2] | (dmask[d2][2] << 2) | (dmask[d3][2] << 4));
                        
                        if (i == w - 1) {
                            if (nmask != masks[i * 2 + 2]) {
                                continue;
                            }
                            if (d[0][i + 1][0][0][0] && (d1 + d2) % 10 == d3) {
                                d[(d1 + d2) / 10][i][d1][d2][d3] = 1;
                                from[(d1 + d2) / 10][i][d1][d2][d3] = {0, 0, 0, 0};
                            }
                            continue;
                        }
                        
                        for (int p1 = 0; p1 < 10; ++p1) {
                            for (int p2 = 0; p2 < 10; ++p2) {
                                for (int p3 = 0; p3 < 10; ++p3) {
                                    if (masks[i * 2 + 2] != (nmask | dmask[p1][0] | (dmask[p2][0] << 2) | (dmask[p3][0] << 4))) {
                                        continue;
                                    }
                                
                                    for (int car = 0; car < 2; ++car) {
                                        if (d[car][i + 1][p1][p2][p3] && (car + d1 + d2) % 10 == d3) {
                                            d[(car + d1 + d2) / 10][i][d1][d2][d3] = 1;
                                            from[(car + d1 + d2) / 10][i][d1][d2][d3] = {p1, p2, p3, car};
                                        }
                                    }
                                }
                            }
                        }                                   
                    }
                }
            }
        }
    }

    int car = 0, d1 = -1, d2 = -1, d3 = -1;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (d[0][0][i][j][k]) {
                    if (masks[0] != (dmask[i][0] | (dmask[j][0] << 2) | (dmask[k][0] << 4))) {
                        continue;
                    }
                    
                    d1 = i;
                    d2 = j;
                    d3 = k;
                    break;
                }
            }
        }
    }
    
    if (d1 == -1) {
        cout << "NO\n";
        return 0;
    }
    vector<int> ans[3];

    for (int i = 0; i < w; ++i) {
        ans[0].puba(d1);
        ans[1].puba(d2);
        ans[2].puba(d3);
        auto tmp = from[car][i][d1][d2][d3];
        tie(d1, d2, d3, car) = tmp;
    }

    for (int num: ans[0]) {
        cout << num;
    }
    cout << "\n";
    for (int num: ans[1]) {
        cout << num;
    }
    cout << "\n";
    for (int num: ans[2]) {
        cout << num;
    }
    cout << "\n";


    return 0;
}
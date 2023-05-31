#include <bits/stdc++.h>

using namespace std;

#define TASK "digital"

const int mmask[10] = {125, 80, 55, 87, 90, 79, 111, 81, 127, 95};

int drow[10][3];
int dcol[10][2][2];

void precalc() {
    for (int d = 0; d < 10; d++) {
        for (int i = 0; i < 3; i++) if (mmask[d] & (1 << i)) drow[d][i] = 1;
        for (int i = 0; i < 4; i++) if (mmask[d] & (1 << (i + 3))) dcol[d][i / 2][(i % 2) ^ 1] = 1;
    }
}

const int MAXN = 128;

struct Prev {
    int a, b, c;
    int mask;
    int add;

    Prev() {
        a = b = c = mask = add = -1;
    }

    Prev(int _a, int _b, int _c, int _mask, int _add) {
        a = _a;
        b = _b;
        c = _c;
        mask = _mask;
        add = _add;
    }

    bool operator== (const Prev &p) const {
        return a == p.a && b == p.b && c == p.c && mask == p.mask && add == p.add;
    }
};

int row[5][MAXN], rrow[5];
int col[4][MAXN], ccol[5];
Prev p[MAXN][2][16];

int getMask(int i, int j) {
    int mask = 0;
    for (int x = 0; x < 3; x++) mask |= (row[j + x][i]) << x;
    for (int x = 0; x < 2; x++) mask |= (col[j + x][i]) << (2 * x + 4);
    for (int x = 0; x < 2; x++) mask |= (col[j + x][i + 1]) << (2 * x + 3);
    return mask;
}

bool can(int i, int j, int x) {
    int mask = getMask(i, j);
    return (mask & mmask[x]) == mmask[x];
}

bool covered(int i, int j, int x, int mask) {
    int fmask = getMask(i, j);

    int cmask = mmask[x];
    if (mask & 1) cmask |= 1 << 4;
    if (mask & 2) cmask |= 1 << 6;
    
    cmask = (cmask | (1 << 3)) ^ (1 << 3);
    cmask = (cmask | (1 << 5)) ^ (1 << 5);

    fmask = (fmask | (1 << 3)) ^ (1 << 3);
    fmask = (fmask | (1 << 5)) ^ (1 << 5);
    return cmask == fmask;
    //int both = fmask | cmask;
    //return both == fmask;

    //return cmask == fmask;
}

int get2Bits(int x) {
    int res = 0;
    int mask = mmask[x];
    if (mask & (1 << 3)) res |= 1;
    if (mask & (1 << 5)) res |= 2;
    return res;
}

int getMask(int a, int b, int c) {
    return get2Bits(a) | (get2Bits(b) << 1) | (get2Bits(c) << 2);
}


int main() {
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);

    precalc();
    
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> row[0][i];
        reverse(row[0], row[0] + n);
        for (int it = 0; it < 4; it++) {
            for (int i = 0; i <= n; i++) cin >> col[it][i];
            reverse(col[it], col[it] + (n + 1));
            for (int i = 0; i < n; i++) cin >> row[it + 1][i];
            reverse(row[it + 1], row[it + 1] + n);
        }

        for (int i = 0; i <= n; i++) for (int j = 0; j < 2; j++) for (int mask = 0; mask < 16; mask++) p[i][j][mask] = Prev();

        p[0][0][0] = Prev(0, 0, 0, 0, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int mask = 0; mask < 16; mask++) {
                    if (p[i][j][mask] == Prev()) continue;
                    for (int a = 0; a < 10; a++) {
                        for (int b = 0; b < 10; b++) {
                            for (int c = 0; c < 10; c++) {
                                if ((a + b + j) % 10 != c) continue;
                                
                                bool ok = 1;
                                /*ok &= can(i, 0, a);
                                ok &= can(i, 1, b);
                                ok &= can(i, 2, c);
                                if (!ok) continue;*/

                                /*ok &= covered(i, 0, a, mask & 3);
                                ok &= covered(i, 1, b, (mask >> 1) & 3);
                                ok &= covered(i, 2, c, (mask >> 2) & 3);*/
                                for (int k = 0; k < 5; k++) rrow[k] = 0;
                                for (int k = 0; k < 4; k++) ccol[k] = 0;
                                int aa[3] = {a, b, c};
                                for (int k = 0; k < 3; k++) {
                                    if (mmask[aa[k]] & (1 << 0)) rrow[k + 0] = 1;
                                    if (mmask[aa[k]] & (1 << 1)) rrow[k + 1] = 1;
                                    if (mmask[aa[k]] & (1 << 2)) rrow[k + 2] = 1;
                                    if (mmask[aa[k]] & (1 << 4)) ccol[k + 0] = 1;
                                    if (mmask[aa[k]] & (1 << 6)) ccol[k + 1] = 1;
                                }
                                for (int k = 0; k < 4; k++) if (mask & (1 << k)) ccol[k] = 1;

                                for (int k = 0; k < 5; k++) ok &= rrow[k] == row[k][i];
                                for (int k = 0; k < 4; k++) ok &= ccol[k] == col[k][i];

                                /*if (a == 7 && b == 4 && c == 1) {
                                    for (int k = 0; k < 5; k++) cerr << rrow[k] << row[i][k] << " "; 
                                    cerr << endl;
                                    for (int k = 0; k < 4; k++) cerr << ccol[k] << col[i][k] << " "; 
                                    cerr << endl;
                                } */

                                if (!ok) continue;
                                int nmask = getMask(a, b, c);
                                int nj = (a + b + j) / 10;

                                p[i + 1][nj][nmask] = Prev(a, b, c, mask, j);
                            }
                        }
                    }
                }
            }
        }    

        int ci = n, cj = 0;
        int cmask = 0;
        for (int i = 0; i < 4; i++) cmask |= col[i][n] << i;

        if (p[ci][cj][cmask] == Prev()) {
            cout << "NO" << endl;
            continue;
        }
        string ansa, ansb, ansc;
        while (ci) {
            Prev pp = p[ci][cj][cmask];
            ansa += (char)(pp.a + '0');
            ansb += (char)(pp.b + '0');
            ansc += (char)(pp.c + '0');
            cj = pp.add;
            cmask = pp.mask;
            ci--;
        }
        /*reverse(ansa.begin(), ansa.end());
        reverse(ansb.begin(), ansb.end());
        reverse(ansc.begin(), ansc.end());*/
        cout << ansa << endl << ansb << endl << ansc << endl;
    }

    return 0;
}

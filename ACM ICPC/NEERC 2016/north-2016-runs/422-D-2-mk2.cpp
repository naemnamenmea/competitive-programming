#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 2e5;

int table[9][300];

void scan();
int w;

struct res {
    int a, b, s, prev;
    res() :
            a(-1), b(-1), s(-1), prev(-1) {
    }
    res(int a, int b, int s, int prev) :
            a(a), b(b), s(s), prev(prev) {
    }
};

res rst[200][32];

int digit[][7] = { { 1, 1, 1, 0, 1, 1, 1 }, { 0, 0, 1, 0, 0, 1, 0 }, { 1, 0, 1,
        1, 1, 0, 1 }, { 1, 0, 1, 1, 0, 1, 1 }, { 0, 1, 1, 1, 0, 1, 0 }, { 1, 1,
        0, 1, 0, 1, 1 }, { 1, 1, 0, 1, 1, 1, 1 }, { 1, 0, 1, 0, 0, 1, 0 }, { 1,
        1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 0, 1, 1 } };

int tmp[9][3];

int check(int place, int a, int b, int s, int mask) {
    fill(tmp[0], tmp[9], 0);
    for (int st = 0; st < 4; st++) {
        tmp[st * 2 + 1][0] = mask & 1;
        mask >>= 1;
    }
    int dx[3] = { a, b, s % 10 };
    for (int i = 0; i < 3; i++) {
        tmp[0 + i * 2][1] |= digit[dx[i]][0];
        tmp[1 + i * 2][2] |= digit[dx[i]][1];
        tmp[1 + i * 2][0] |= digit[dx[i]][2];
        tmp[2 + i * 2][1] |= digit[dx[i]][3];
        tmp[3 + i * 2][2] |= digit[dx[i]][4];
        tmp[3 + i * 2][0] |= digit[dx[i]][5];
        tmp[4 + i * 2][1] |= digit[dx[i]][6];
    }
//    cout << a << " " << b << " " << s % 10 << "\n";
//    for (int i = 0; i < 9; i++) {
//        for (int j = 0; j < 3; j++) {
//            if (tmp[i][j] == 0) {
//                cout << " ";
//            } else {
//                if (i % 2 == 1) {
//                    cout << "|";
//                } else {
//                    cout << "-";
//                }
//            }
//        }
//        cout << "\n";
//    }
    bool eq = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
            eq &= (tmp[i][j] == table[i + place * 2][j]);
        }
    }
    if (!eq) {
        return -1;
    }
    int nmask = tmp[1][2] + tmp[3][2] * 2 + tmp[5][2] * 4 + tmp[7][2] * 8
            + (s / 10) * 16;
    return nmask;
}

int main() {
    ios_base::sync_with_stdio(false);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("digital.in", "r", stdin);
    freopen("digital.out", "w", stdout);
#endif
    scan();
    rst[0][0] = res(0, 0, 0, 0);
    for (int iter = 0; iter < w; iter++) {
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                for (int mask = 0; mask < 32; mask++) {
                    if (rst[iter][mask].prev != -1) {
                        int nmask = check(iter, a, b, a + b + (mask / 16),
                                mask);
                        if (nmask != -1 && rst[iter + 1][nmask].prev == -1) {
                            rst[iter + 1][nmask] = res(a, b, a + b, mask);
                        }
                    }
                }
            }
        }
    }

    int cr = 0;
    for (int st = 0; st < 4; st++) {
        cr += table[st * 2 + 1][w * 2] << st;
    }
    if (rst[w][cr].prev == -1) {
        cout << "NO\n";
        return 0;
    }
    string ar, br, sr;
    for (int i = w; i > 0; i--) {
        if (!ar.empty() || rst[i][cr].a != 0) {
            ar.push_back('0' + rst[i][cr].a);
        }
        if (!br.empty() || rst[i][cr].b != 0) {
            br.push_back('0' + rst[i][cr].b);
        }
        if (!sr.empty() || rst[i][cr].s != 0) {
            sr.push_back('0' + rst[i][cr].s);
        }
        cr = rst[i][cr].prev;
    }
    if (ar.empty()) {
        ar = "0";
    }
    if (br.empty()) {
        br = "0";
    }
    if (sr.empty()) {
        sr = "0";
    }
    cout << ar << "\n" << br << "\n" << sr << "\n";
    return 0;
}

void scan() {
    cin >> w;
    for (int st = 0; st < 4; st++) {
        for (int i = 0; i < w; i++) {
            cin >> table[st * 2 + 0][w * 2 - i * 2 - 1];
        }
        for (int i = 0; i <= w; i++) {
            cin >> table[st * 2 + 1][w * 2 - i * 2];
        }
    }
    for (int i = 0; i < w; i++) {
        cin >> table[8][w * 2 - i * 2 - 1];
    }
}
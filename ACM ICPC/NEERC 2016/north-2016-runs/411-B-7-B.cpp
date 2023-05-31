#define FNAME "boysgirls"

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (n); i++)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin() v.end()

using namespace std;

typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;

const LD eps = 1e-6;

char chars[] = "BG";
LD a[7][7];
int var[7];
int n, x, y;

void build() {
    forn(i, 6)
        forn(j, 7)
            a[i][j] = 0;
    forn(i, 6)  
        a[0][i] = 1;
    a[0][6] = n;
    a[1][1] = a[1][2] = a[1][3] = a[1][5] = 1;
    a[1][6] = x;
    a[2][0] = a[2][2] = a[2][4] = a[2][5] = 1;
    a[2][6] = y;
    a[3][0] = 2;
    a[3][2] = 1;
    a[3][3] = -2;
    a[3][5] = -1;
}

void gauss() {
    int pos = 0;
    forn(i, 6) {
        int toSwap = -1;
        while (pos < 6 && toSwap == -1) {
            forab(j, i, 6) {
                if (abs(a[j][pos]) > eps) toSwap = j;            
            }
            if (toSwap != -1)
                break;
            pos++;
        }
        if (pos == 6) break;
        forn(j, 7) swap(a[i][j], a[toSwap][j]);
        forn(j, 6) {
            if (i != j) {
                LD z = a[j][pos] / a[i][pos]; 
                forn(k, 7) {
                    a[j][k] -= z * a[i][k];
                }
            }
        }
    }
    /*
    forn(i, 6) {
        forn(j, 7)
            cerr << a[i][j] << " ";
        cerr << endl;
    }
    cerr << endl;   */
    fornr(i, 6) {
//    cerr << a[i][i] << endl;
        if (abs(a[i][i]) <= eps && abs(a[i][6]) > eps) return;
//        assert(abs(a[i][i]) > eps);
        LD sum = a[i][6];
        forab(j, i + 1, 6) sum -= var[j] * a[i][j];

        LD z;
        if (abs(a[i][i]) <= eps)
            z = 0;
        else z = sum / a[i][i];
        if (abs(round(z) - z) > eps)
            return;
        var[i] = (int) round(z);
        if (var[i] < 0 || var[i] > n) return;
    }    
    if (var[2] % 2 != 0 || var[5] % 2 != 0) return;
    if (var[2] == 0 && var[1] != 0) return;
    if (var[5] == 0 && var[4] != 0) return;
    string res = "";
    int ok = 1;
    int Pos[2] = {-1, -1};
    while(ok) {
        forn(i, 2) {
            if (var[3 * i]) {
                res += chars[i];
                var[3 * i]--;
            } else if (var[3 * i + 2] >= 2) {
//                assert(var[3 * i + 2] >= 2);
                res += chars[i];
                Pos[i] = res.size();
                res += chars[i];
                var[3 * i + 2] -= 2;
            } else {
                ok = 0;
                break;
            }
        }
    }
    assert(var[0] == 0);
    assert(var[2] == 0);
    assert(var[3] == 0);
    assert(var[5] == 0);
    forn(i, 2)
        assert(var[3 * i + 1] == 0 || Pos[i] != -1);
    forn(i, (int) res.size()) {
        printf("%c", res[i]);
        forn(j, 2) {
            if (i == Pos[j]) {
                while (var[3 * j + 1]--) printf("%c", chars[j]);                    
            }
        }
    }
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);

    scanf("%d%d%d", &n, &x, &y);
    if (x == 0) {
        forn(i, n)
            printf("%c", chars[1]);
        puts("");
        return 0;
    }
    if (y == 0) {
        forn(i, n)
            printf("%c", chars[0]);
        puts("");
        return 0;
    }
    build();
    a[4][1] = 1;
    a[5][2] = 1;
    gauss();

    build();
    a[4][4] = 1;
    a[5][5] = 1;
    gauss();
    
    forn(i, 20) {
        forn(z, n + 1) {
            build();
            a[4][0] = 1;
            a[4][6] = i;
            a[5][1] = 1;
            a[5][6] = z;
            gauss();

            build();
            a[4][3] = 1;
            a[4][6] = i;
            a[5][1] = 1;
            a[5][6] = z;
            gauss();
        }
    }
    puts("Impossible");
    return 0;
}
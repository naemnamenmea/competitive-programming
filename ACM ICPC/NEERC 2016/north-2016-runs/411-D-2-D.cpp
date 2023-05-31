#define FNAME "digital"

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

struct par{
    int mask, flag, q, w;
    par() : mask(-1), flag(-1), q(-1), w(-1) {}
    par(int mask, int flag, int q, int w) : mask(mask), flag(flag), q(q), w(w) {}
};


int pntl[10] = {3, 0, 2, 0, 1, 1, 3, 0, 3, 1};
int pntr[10] = {3, 3, 1, 3, 3, 2, 2, 3, 3, 3};
int pntg[10] = {5, 0, 7, 7, 2, 7, 7, 1, 7, 7};
int dp[110][1 << 4][2];
par p[110][1 << 4][2];
int maskg[110];
int maskv[110];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < 9; ++i) {
        if (i & 1) {
            int m = (1 << (i / 2));
            for (int j = 0; j <= n; ++j) {
                int a;
                cin >> a;
                if (a)
                    maskv[n - j] |= m;
            }           
        }
        else {
            int m = (1 << (i/ 2));
            for (int j = 0; j < n; ++j) {
                int a;
                cin >> a;
                if (a)
                    maskg[n - j - 1] |= m;
            }
        }
    }
  /*  for (int i = 0; i < n; ++i)
        cout << maskg[i] << ' ';
    cout << endl;
    for (int i = 0; i <= n; ++i)
        cout << maskv[i] << ' ';
    cout << endl;
    */
    dp[0][0][0] = 1;
    for (int i = 0; i <n; ++i) {
        for (int mask = 0; mask < 16; ++mask) {
            for (int flag = 0; flag < 2; ++flag) {
                if (!dp[i][mask][flag])
                    continue;
                for (int q = 0; q < 10; ++q) {
                    for (int w = 0; w < 10; ++w) {
                        int c = (q + w + flag) % 10;
                        int cur = (q + w + flag) / 10;
                        int vmask = mask | pntr[q] | (pntr[w] << 1) | (pntr[c] << 2);
                        if (vmask != maskv[i])
                            continue;
                        int gmask = pntg[q] | (pntg[w] << 1) | (pntg[c] << 2);
                        if (gmask != maskg[i])
                            continue;
                        int tomask = pntl[q] | (pntl[w] << 1) | (pntl[c] << 2);
                       // cerr << i << ' ' << mask << ' ' << flag << ' ' << q << ' ' << w << ' ' << vmask << ' ' << gmask << endl;
                        if (!dp[i + 1][tomask][cur]) {
                            dp[i + 1][tomask][cur] = 1;
                            p[i + 1][tomask][cur] = par(mask, flag, q, w);
                        }
                    }
                }
            }
        }
    }
    int endmask = maskv[n];
    if (!dp[n][endmask][0]) {
        cout << "NO";
        return 0;
    }
    //string s;
    string q, w , e;
    int curmask = endmask, curflag = 0;
    for (int i = n; i; --i) {
        int a = p[i][curmask][curflag].q, b = p[i][curmask][curflag].w;
        int c = (a + b + p[i][curmask][curflag].flag) % 10;
        q += (char)('0' + a), w += (char)('0' + b), e += (char)('0' + c);
        //q = q * 10 + a, w = w * 10 + b, e = e * 10 + c;  
        par tmp = p[i][curmask][curflag];
        curmask = tmp.mask;
        curflag = tmp.flag;
    } 
    //assert(q + w == e);
    cout << q << endl << w << endl << e;

    return 0;
}
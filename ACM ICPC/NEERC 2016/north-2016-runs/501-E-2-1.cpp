#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cassert>

using namespace std;

#define TASK "easy"
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define pw(x) (1ll << (x))
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 1 << 18;

const int inf = 1.01e9;
const int mod1 = 1e9 + 7;

const int P = 239123;
const int Q = 241231;

typedef long long ll;

int mnx[2 * N];
int mny[2 * N];
int h1[2 * N];
int cnt[2 * N];

int pn[N];
int qn[N];

int gethash(int l, int r)
{
    l += N;
    r += N;
    int res = 0;
    while (l <= r)
    {
        if ((l & 1) == 1) res = (res + h1[l]) % mod1;
        if ((r & 1) == 0) res = (res + h1[r]) % mod1;
        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return res;
}
int getcnt(int l, int r)
{
    l += N;
    r += N;
    int res = 0;
    while (l <= r)
    {
        if ((l & 1) == 1) res = (res + cnt[l]);
        if ((r & 1) == 0) res = (res + cnt[r]);
        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return res;
}


int getmnx(int l, int r)
{
    l += N;
    r += N;
    int res = inf;
    while (l <= r)
    {
        if ((l & 1) == 1) res = min(res, mnx[l]);
        if ((r & 1) == 0) res = min(res, mnx[r]);
        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return res;
}
int getmny(int l, int r)
{
    l += N;
    r += N;
    int res = inf;
    while (l <= r)
    {
        if ((l & 1) == 1) res = min(res, mny[l]);
        if ((r & 1) == 0) res = min(res, mny[r]);
        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return res;
}

void upd(int pos, int x, int y)
{
    pos += N;
    cnt[pos] = 1;
    h1[pos] = pn[x] * (ll)qn[y] % mod1;
    mnx[pos] = x;
    mny[pos] = y;
    while (pos > 1)
    {
        pos >>= 1;
        cnt[pos] = cnt[pos * 2] + cnt[pos * 2 + 1];
        h1[pos] = (h1[pos * 2] + h1[2 * pos + 1]) % mod1;
        mnx[pos] = min(mnx[pos * 2], mnx[pos * 2 + 1]);
        mny[pos] = min(mny[pos * 2], mny[pos * 2 + 1]);
    }
}
void upd2(int pos)
{
    pos += N;
    cnt[pos] = 0;
    h1[pos] = 0;
    mnx[pos] = inf;
    mny[pos] = inf;
    while (pos > 1)
    {
        pos >>= 1;
        cnt[pos] = cnt[pos * 2] + cnt[pos * 2 + 1];
        h1[pos] = (h1[pos * 2] + h1[2 * pos + 1]) % mod1;
        mnx[pos] = min(mnx[pos * 2], mnx[pos * 2 + 1]);
        mny[pos] = min(mny[pos * 2], mny[pos * 2 + 1]);
    }
}


int rev(int a, int m)
{
    if (a == 1) return 1;
    return (1 - rev(m % a, a) * (ll)m) / a + m;
}



int nxt[N];
int X[N], Y[N];
unordered_map<ll, int> M;

ll f(int x, int y)
{
    return x * pw(30) + y;
}

int main() {
    pn[0] = qn[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        pn[i] = pn[i - 1] * (ll)P % mod1;
        qn[i] = qn[i - 1] * (ll)Q % mod1;
    }

    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    ios::sync_with_stdio(0);
    int len;
    cin >> len;
    string s;
    //cin >> s;
    getline(cin, s);
    getline(cin, s);

    int n, m;
    cin >> n >> m;
    vector<string> v;
    forn(i, n)
    {
        string ss;
        cin >> ss;
        v.push_back(ss);
    }

    forn(i, 2 * N)
    {
        mnx[i] = inf;
        mny[i] = inf;
    }
    
    int x = len, y = len;
    X[0] = x;
    Y[0] = y;
    M[f(x, y)] = 0;

    memset(nxt, -1, sizeof nxt);

    forn(i, len)
    {
        if (s[i] == 'u')
        {
            x--;
        }
        if (s[i] == 'd')
        {
            x++;
        }
        if (s[i] == 'l')
        {
            y--;
        }
        if (s[i] == 'r')
        {
            y++;
        }
        X[i + 1] = x;
        Y[i + 1] = y;
        ll vv = f(x, y);
        if (M.find(vv) != M.end()) nxt[M[vv]] = i + 1;
        else upd(i + 1, x, y);
        M[vv] = i + 1;
    }

    
    
    int hash = 0;

    int want = 0;
    int xx = inf;
    int yy = inf;
    forn(i, n) forn(j, m) if (v[i][j] == 'X')
    {
        xx = min(xx, i);
        yy = min(yy, j);
    }

    forn(i, n) forn(j, m) if (v[i][j] == 'X')
    {
        hash = (hash + pn[i - xx] * (ll)qn[j - yy]) % mod1;
        want++;
    }


    upd(0, len, len);
    int r = 1;
    for (int i = 1; i <= len; ++i)
    {
        while (r < i) ++r;
        while (r <= len && getcnt(0, r) < want) ++r;
        if (r == len + 1) break;
        int h = gethash(0, r);
        x = getmnx(0, r);
        y = getmny(0, r);
        h = h * (ll)rev(pn[x], mod1) % mod1 * (ll)rev(qn[y], mod1) % mod1;

        if (hash == h)
        {
            printf("YES\n");
            printf("%d %d\n", i, r);
            epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
            return 0;
        }

        if (nxt[i - 1] != -1)
        {
            upd(nxt[i - 1], X[i - 1], Y[i - 1]);
        }
        upd2(i - 1);
    }
    printf("NO\n");

    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    return 0;
}

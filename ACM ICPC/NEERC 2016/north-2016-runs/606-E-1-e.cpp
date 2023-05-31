#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int) (x).size())
#define bend(x) (x).begin(), (x).end()
#define puba push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll P = 239;

ll arrp[4][MAXN];
char s[MAXN], buf[MAXN];
multiset<int> arrx, arry;

ll nh;
int nsz = 0;

ll mpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll tmp = mpow(a, b / 2);
    tmp = tmp * tmp % MOD;
    if (b & 1) {
        tmp = tmp * a % MOD;
    }
    return tmp;
}

ll inv(ll num) {
    return mpow(num, MOD - 2);
}

int add(int x, int y) {
    ll tmp = 1;
    if (x < 0) {
        tmp = ((ll) tmp * arrp[1][-x]) % MOD;
    } else {
        tmp = ((ll) tmp * arrp[0][x]) % MOD;
    }
    if (y < 0) {
        tmp = ((ll) tmp * arrp[3][-y]) % MOD;
    } else {
        tmp = ((ll) tmp * arrp[2][y]) % MOD;
    }
    
    nh = (nh + tmp) % MOD;
    arrx.insert(x);
    arry.insert(y);
    ++nsz;
    return 0;
}

int rem(int x, int y) {
    ll tmp = 1;
    if (x < 0) {
        tmp = ((ll) tmp * arrp[1][-x]) % MOD;
    } else {
        tmp = ((ll) tmp * arrp[0][x]) % MOD;
    }
    if (y < 0) {
        tmp = ((ll) tmp * arrp[3][-y]) % MOD;
    } else {
        tmp = ((ll) tmp * arrp[2][y]) % MOD;
    }
    
    nh = (nh - tmp) % MOD;
    if (nh < 0) {
        nh += MOD;
    }
    arrx.erase(arrx.find(x));
    arry.erase(arry.find(y));
    --nsz;
    return 0;
}

ll get_hash() {
    ll tmp = 1;
    int x = -*arrx.begin();
    int y = -*arry.begin();
    //cerr << x << " " << y << endl;
    if (x < 0) {
        tmp = (tmp * arrp[1][-x]) % MOD;
    } else {
        tmp = (tmp * arrp[0][x]) % MOD;
    }
    if (y < 0) {
        tmp = (tmp * arrp[3][-y]) % MOD;
    } else {
        tmp = (tmp * arrp[2][y]) % MOD;
    }
    //cerr << nh << " " << tmp << endl;
    return (nh * tmp) % MOD;
}

map<pii, int> have;

int main() {
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);

    arrp[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        arrp[0][i] = ((ll) arrp[0][i - 1] * P) % MOD;
    }
    
    arrp[1][MAXN - 1] = inv(arrp[0][MAXN - 1]);
    
    for (int i = MAXN - 2; i >= 0; --i) {
        arrp[1][i] = ((ll) arrp[1][i + 1] * P) % MOD;
    }
    
    arrp[2][0] = 1;
    
    for (int i = 1; i < MAXN; ++i) {
        arrp[2][i] = ((ll) arrp[2][i - 1] * arrp[0][MAXN - 1]) % MOD;
    }
    
    arrp[3][MAXN - 1] = inv(arrp[2][MAXN - 1]);
    
    for (int i = MAXN - 2; i >= 0; --i) {
        arrp[3][i] = ((ll) arrp[3][i + 1] * arrp[0][MAXN - 1]) % MOD;
    }
    
    //assert(arrp[3][0] == 1 && arrp[1][0] == 1);
    
    int l;
    scanf("%d", &l);
    gets(s);
    gets(s);
    
    int n, m;
    scanf("%d%d", &n, &m);
    
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        for (int j = 0; j < m; ++j) {
            if (buf[j] == 'X') {
                add(i, j);
                ++sz;
            }
        }
    }
    
    //cerr << nh << endl;
    ll h = get_hash();
    //cerr << "h: " << h << endl;
    
    nh = 0;
    arrx.clear();
    arry.clear();
    nsz = 0;
    
    vector<pii> path = {{0, 0}};
    int c = 0;
    have[{0, 0}] = 1;
    add(0, 0);
    
    int from = 0;
    for (int i = 0; i < l; ++i) {
        pii now = path.back();
        if (s[i] == 'l') {
            now.ss--;
        } else if (s[i] == 'r') {
            ++now.ss;
        } else if (s[i] == 'u') {
            --now.ff;
        } else if (s[i] == 'd') {
            ++now.ff;
        }
        if (now == path.back()) {
            continue;
        }
        //cerr << "i: " << i << " " << s[i] << endl;
        if (have[now] == 0) {
            add(now.ff, now.ss);
        }
        have[now]++;
        path.puba(now);
        //cerr << from << " " << i << " " << nsz << endl;
        if (nsz == sz) {
            //cerr << h << " " << get_hash() << endl;
            if (get_hash() == h) {
                cout << "YES\n";
                cout << from + 1 << " " << i + 1 << "\n";
                return 0;
            }
            while (from < i && nsz == sz) {
                if (s[from] == 'l' || s[from] == 'r' || s[from] == 'u' || s[from] == 'd') {
                    have[path[c]]--;
                    if (have[path[c]] == 0) {
                        rem(path[c].ff, path[c].ss);
                        //cerr << "rem" << endl;
                    }
                    ++c;
                }
                ++from;
            }
        }
    }
    
    cout << "NO\n";

    return 0;
}
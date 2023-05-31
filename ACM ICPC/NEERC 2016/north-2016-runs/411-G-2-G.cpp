#define FNAME "gangsters"
#include <bits/stdc++.h>

#define left wrefioherofuiwherf
#define right opijoriweoifopewirfj

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

const int MAXN = 1e6;

int t[MAXN], childCnt[MAXN], size[MAXN], left[MAXN], child[MAXN], right[MAXN];
vi a[MAXN], euler;
int n, q;
set <int> rightMost[100001], leftMost[100001];

int dfs(int v, int childNum) {
    size[v] = 0;
    if (a[v].size() == 0)
        size[v] = 1;

    left[v] = (int) euler.size();
    child[v] = childNum;
    euler.pb(v);
    for (int to: a[v]) {
        size[v] += dfs(to, childNum);        
        if (!v) childNum++;
        euler.pb(v);
    }
    right[v] = (int) euler.size() - 1;
    return size[v];
}

void build(int vl, int vr, int v) {
    if (vl + 1 == vr) {
        t[v] = left[euler[vl]];
        return;
    }
    int vm = (vl + vr) / 2;
    build(vl, vm, 2 * v), build(vm, vr, 2 * v + 1);
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get(int vl, int vr, int l, int r, int v) {
    if (vl >= l && vr <= r) return t[v];
    if (vl >= r || vr <= l) return 1e9;
    int vm = (vl + vr) / 2;
    return min(get(vl, vm, l, r, 2 * v), get(vm, vr, l, r, 2 * v + 1));    
}

inline int getMin(int c) {
    if (leftMost[c].size() == 0)
        return 0;
    int l = *leftMost[c].begin(), r = *(--rightMost[c].end());
    int leftPos = get(0, (int) euler.size(), l, r + 1, 1);
 //   printf("c=%d l=%d r=%d euler[leftPos]=%d size=%d child=%d\n", c, l, r, euler[leftPos], size[euler[leftPos]], childCnt[c]);
    return size[euler[leftPos]] - childCnt[c];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);

    scanf("%d%d", &n, &q);
    forn(i, n - 1) {
        int x;
        scanf("%d", &x);
        a[x - 1].pb(i + 1);
    }
    dfs(0, 0);
    build(0, (int) euler.size(), 1);
       
    int ans = 0, res = 0;
//    for (int x: euler) printf("(v=%d left=%d) ", x + 1, left[x]);
    forn(qqq, q) {
        char c;
        int v;
        scanf(" %c%d", &c, &v);
        v--;
        if (c == '+') {
            res -= getMin(child[v]);
            childCnt[child[v]]++;
            if (childCnt[child[v]] == 1) ans++;
            leftMost[child[v]].insert(left[v]);
            rightMost[child[v]].insert(right[v]);
            res += getMin(child[v]);
        } else if (c == '-') {
            res -= getMin(child[v]);
            childCnt[child[v]]--;
            if (childCnt[child[v]] == 0) ans--;
            leftMost[child[v]].erase(left[v]);
            rightMost[child[v]].erase(right[v]);
            res += getMin(child[v]);
        } else assert(0);
        printf("%d %d\n", ans, res);
    }


    return 0;
}
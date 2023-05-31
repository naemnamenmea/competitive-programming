#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "codecoder"

void precalc() {
}

const int maxn = (int) 1e5 + 10;

int a[maxn], b[maxn];

int n;
int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", a + i, b + i);
  }
  return 1;
}

pair<int, int> tosort[maxn];

int inva[maxn];

int mx[maxn];

int ans[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    tosort[i] = mp(a[i], i);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; ++i) {
    a[tosort[i].second] = i;
    inva[i] = tosort[i].second;
  }
  
  for (int i = 0; i < n; ++i) {
    tosort[i] = mp(b[i], i);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; ++i) {
    b[tosort[i].second] = i;
  }
  
  for (int i = 0; i < n; ++i) {
    mx[i] = i;
  }
  
  for (int i = 0; i < n - 1; ++i) {
    int l = a[tosort[i].second], r = a[tosort[i + 1].second];
    if (l > r) {
      mx[r] = max(mx[r], l);
    }
  }
  
  for (int i = 0; i < n;) {
    int r = i;
    int i0 = i;
    for (; i <= r; ++i) {
      r = max(r, mx[i]);
    }
    
    for (int j = i0; j < i; ++j) {
      ans[inva[j]] = i - 1;
    }
  }
  
  for (int i = 0; i < n; ++i) {
    printf("%d\n", ans[i]);
  }
}

int main() {
  precalc();  
  freopen(TASK ".out", "w", stdout);
  freopen(TASK ".in", "r", stdin);
  
  while (read()) {
    solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}
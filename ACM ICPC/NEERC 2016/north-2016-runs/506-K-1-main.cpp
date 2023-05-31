#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "king"

void precalc() {
}

const int maxn = 105;
int n;
pair<int, pair<int, int> > today, a[maxn];

int read() {
  if (scanf("%d%d%d", &today.second.second, &today.second.first, &today.first) < 3) {
    return 0;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a[i].second.second, &a[i].second.first, &a[i].first);
  }
  return 1;
}

void solve() {
  int res = -1;
  for (int i = 0; i < n; i++) {
    a[i].first += 18;
    if (a[i] <= today && (res == -1 || a[res] < a[i])) {
      res = i;
    }
  }
  if (res >= 0) {
    res++;
  }
  printf("%d\n", res);
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
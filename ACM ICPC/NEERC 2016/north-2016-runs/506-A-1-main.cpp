#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "anniversary"

void precalc() {
}

int w, h, ax, ay, bx, by;
int read() {
  if (scanf("%d%d%d%d%d%d", &w, &h, &ax, &ay, &bx, &by) < 6) {
    return 0;
  }
  return 1;
}

void solve() {
  if (ax != bx) {
    printf("%d %d %d %d\n", min(ax, bx), 0, min(ax, bx) + 1, h);
    return;
  }
  printf("%d %d %d %d\n", 0, min(ay, by), w, min(ay, by) + 1);
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
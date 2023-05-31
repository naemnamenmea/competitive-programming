#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "folding"

const int inf = (int) 1e9 + 5;

void precalc() {
}

int W, H, w, h;
int read() {
  if (scanf("%d%d%d%d", &W, &H, &w, &h) < 4) {
    return 0;
  }
  return 1;
}

int get(int a, int b) {
  if (b > a) {
    return inf;
  }
  int res = 0;
  while (a != b) {
    a = max(b, (a + 1) / 2);
    res++;
  }
  return res;
}

void solve() {
  int res = min(get(W, w) + get(H, h), get(W, h) + get(H, w));
  if (res >= inf) {
    res = -1;
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
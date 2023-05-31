#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define TASK "java2016"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;

void precalc() {
}

int n;
int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  return 1;
}

void solve() {
  if (n == 0) {
    printf("? / ? / ?\n");
    return;
  }
  printf("%c = %c max %c\n", 'a', '?', '?');
  for (int i = 1; i <= 25 - 8; i++) {
    printf("%c = %c max %c\n", 'a' + (char) i, 'a' + (char) (i - 1), 'a' + (char) (i - 1));
  }
  printf("%c = %c / %c\n", 'a' + (char) (25 - 7), 'a' + (char) (25 - 8), 'a' + (char) (25 - 8));
  for (int i = 25 - 6; i <= 25; i++) {
    printf("%c = %c + %c\n", 'a' + (char) i, 'a' + (char) (i - 1), 'a' + (char) (i - 1));
  }
  vector<char> want;
  for (int i = 0; i < 8; i++) {
    if (n & (1 << i)) {
      want.pb('a' + (char) (25 - 7 + i));
    }
  }
  for (int i = 0; i < sz(want); i++) {
    printf("%c", want[i]);
    if (i != sz(want) - 1) {
      printf(" + ");
    }
  }
  printf("\n");
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
#include <iostream>
#include <cstdlib>
using namespace std;


struct score {
  int ind;
  int sc;
  };

int cmp(const void *a, const void *b) {
  score *a1, *b1;
  a1 = (score*)a;
  b1 = (score*)b;
  return b1->sc - a1->sc;
}

int cmpWin(const void *a, const void *b) {
  score *a1, *b1;
  a1 = (score*)a;
  b1 = (score*)b;
  return b1->ind - a1->ind;
}

int main() {
  freopen("codecoder.in", "r", stdin);
  freopen("codecoder.out", "w", stdout);

  int n, w;
  score *cc, *tf;
  score *ccW, *tfW;

  cin >> n;
  cc = new score[n];
  tf = new score[n];
  ccW = new score[n];
  tfW = new score[n];

  for (int i = 0; i < n; i++) {
    cin >> cc[i].sc >> tf[i].sc;
    cc[i].ind = tf[i].ind = i;
    }

  qsort(cc, n, sizeof(score), cmp);
  qsort(tf, n, sizeof(score), cmp);

  for (int i = 0; i < n; i++) {
    ccW[cc[i].ind].sc = n - 1 - i;
    ccW[cc[i].ind].ind = cc[i].ind;
    tfW[tf[i].ind].sc = n - 1 - i;
    tfW[tf[i].ind].ind = tf[i].ind;
    }
  for (int i = 0; i < n; i++) {
    if (ccW[i].sc > tfW[i].sc)
      w = ccW[i].sc;
    else
      w = tfW[i].sc;

    cout<< w << endl;
    }

  return 0;
  }

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

  cin >> n;
  cc = new score[n];
  tf = new score[n];

  for (int i = 0; i < n; i++) {
    cin >> cc[i].sc >> tf[i].sc;
    cc[i].ind = tf[i].ind = i;
    }

  int a;
  for (int i = 0; i < n; i++) {
    a = 0;
    for (int j = 0; j < n; j++) {
      if (cc[i].sc > cc[j].sc ||
          tf[i].sc > tf[j].sc)
        a++;
      }
    cout << a << endl;
    }

  return 0;
  }

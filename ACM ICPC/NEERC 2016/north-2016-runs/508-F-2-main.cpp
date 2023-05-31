#include <iostream>
#include <cstdio>

using namespace std;

int folds (int w, int h, int wt, int ht) {
    int folds_number = 0;
    while (w > 2 * wt) {
        w = (int) (w / 2) + w % 2;
        folds_number++;
        // cout << w << " " << h << endl;
    }
    if (w != wt) folds_number++;
    while (h > 2 * ht) {
        h = (int) (h / 2) + h % 2;
        folds_number++;
        // cout << w << " " << h << endl;
    }
    if (h != ht) folds_number++;
    return folds_number;
}

int main()
{
    FILE * fin = fopen("folding.in", "r");
    FILE * fout = fopen("folding.out", "w");

    int w, h, wt, ht, ans;
    fscanf(fin, "%d %d", &w, &h);
    fscanf(fin, "%d %d", &wt, &ht);

    if (w < h) swap(w, h);
    if (wt < ht) swap(wt, ht);

    if ((w < wt) || (h < ht)) {
        fprintf(fout, "-1");
    } else {
        ans = folds(w, h, wt, ht);
        if (h >= wt) {
            swap(wt, ht);
            if (folds(w, h, wt, ht) < ans) {
                ans = folds(w, h, wt, ht);
            }
        }
        fprintf(fout, "%d", ans);
    }

    return 0;
}

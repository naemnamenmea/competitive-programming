#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    FILE * fin = fopen("folding.in", "r");
    FILE * fout = fopen("folding.out", "w");

    int w, h, wt, ht, folds = 0;
    fscanf(fin, "%d %d", &w, &h);
    fscanf(fin, "%d %d", &wt, &ht);

    if (w < h) swap(w, h);
    if (wt < ht) swap(wt, ht);

    if ((w < wt) || (h < ht)) {
        fprintf(fout, "-1");
    } else {
        while (w > 2 * wt) {
            w = (w >> 1) + 1;
            folds++;
            // cout << w << " " << h << endl;
        }
        if (w != wt) folds++;
        while (h > 2 * ht) {
            h = (h >> 1) + 1;
            folds++;
            // cout << w << " " << h << endl;
        }
        if (h != ht) folds++;
        fprintf(fout, "%d", folds);
    }

    return 0;
}

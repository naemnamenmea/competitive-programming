#include <iostream>
#include <cstdlib>

using namespace std;

bool is_integer (double x) {
    if (x - (int) x < 1e-6) {
        return true;
    }
    return false;
}

int main()
{
    FILE * fin = fopen("integral.in", "r");
    FILE * fout = fopen("integral.out", "w");

    int n;
    long long lines = 0;
    fscanf(fin, "%d", &n);
    pair <int, int> points[n];
    double squares[n-1], prefix[n];
    double left = 1.0e9, right = -1.0e9, top = -1.0e9, bottom = 1.0e9;

    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d %d", &points[i].first, &points[i].second);
        if (points[i].first > right)   right = points[i].first;
        if (points[i].first < left)    left = points[i].first;
        if (points[i].second > top)    top = points[i].second;
        if (points[i].second < bottom) bottom = points[i].second;
    }

    // cout << left << " " << top << " " << right << " " << bottom << endl;

    double square = 0.0;
    for (int i = 0; i < n - 1; i++) {
        square += (double) (points[i].first - points[i+1].first) * (points[i+1].second + points[i].second) / 2.0;
    }

    if (is_integer(square)) {
        prefix[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            squares[i] = (double) abs(points[i].first - points[i+1].first) *
                                  abs(points[i].second - points[i+1].second) / 2.0;
            // cout << squares[i] << " ";
            prefix[i + 1] = prefix[i] + squares[i];
        }
        // cout << endl;

        double big_square;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 2; j < ((i > 0) ? n : n - 1); j++) {
                if (points[i].first > points[j].first) {
                    if (points[i].second > points[j].second) {
                        big_square = (double) (points[i].first - left) * (top - points[j].second) - (double) abs(points[i].first - points[j].first) * abs(points[i].second - points[j].second) / 2.0;
                    } else if (points[i].second < points[j].second) {
                        big_square = (double) (points[i].first - left) * (points[j].second - bottom) - (double) abs(points[i].first - points[j].first) * abs(points[i].second - points[j].second) / 2.0;
                    } else {
                        big_square = (double) (points[i].first - points[j].first) * (top - points[i].second);
                    }
                } else if (points[i].first < points[j].first) {
                    if (points[i].second > points[j].second) {
                        big_square = (double) (right - points[i].first) * (top - points[j].second) - (double) abs(points[i].first - points[j].first) * abs(points[i].second - points[j].second) / 2.0;
                    } else if (points[i].second < points[j].second) {
                        big_square = (double) (right - points[i].first) * (points[j].second - bottom) - (double) abs(points[i].first - points[j].first) * abs(points[i].second - points[j].second) / 2.0;
                    } else {
                        big_square = (double) (points[i].first - points[j].first) * (points[i].second - bottom);
                    }
                } else {
                    if (points[i].second < points[j].second) {
                        big_square = (double) (points[j].second - points[i].second) * (right - points[i].first);
                    } else {
                        big_square = (double) (points[i].second - points[j].second) * (points[i].first - left);
                    }
                }

                // cout << i << " " << j << " " << big_square << endl;
                lines += is_integer(big_square - prefix[j] + prefix[i]);
            }
        }

        fprintf(fout, "%lld", lines);
    } else {
        fprintf(fout, "0");
    }
}

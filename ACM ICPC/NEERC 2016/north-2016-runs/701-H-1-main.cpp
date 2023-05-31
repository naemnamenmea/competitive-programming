#include <fstream>
#include <utility>

using std::pair;
using std::make_pair;

const int maxW = 60;
pair<int, pair<int, int> > results[maxW][maxW];

void output(std::ofstream &out, int shiftR, int shiftB, int x, int y)
{
    //out << "Step: " << x << " " << y << std::endl;
    if (results[x - 1][y - 1].second.second == 0)
    {
        out << shiftR << " " << shiftB << " " << x << std::endl;
        return;
    }

    int delta = results[x - 1][y - 1].second.first;
    if (results[x - 1][y - 1].second.second == -1)
    {
        output(out, shiftR, shiftB, delta, y);
        output(out, shiftR + delta, shiftB, x - delta, y);
        return;
    }
    output(out, shiftR, shiftB, x, delta);
    output(out, shiftR, shiftB + delta, x, y - delta);

}

int main()
{
    std::ifstream in("hard.in");
    std::ofstream out("hard.out");

    int n = 0;
    in >> n;
    for (int i = 0; i < maxW; ++i)
    {
        for (int j = 0; j < maxW; ++j)
        {
            if (i == j)
            {
                results[i][j] = make_pair(1, make_pair(1, 0));
                continue;
            }
            if (i == 0)
            {
                results[i][j] = make_pair(j + 1, make_pair(1, 1));
                continue;
            }
            if (j == 0)
            {
                results[i][j] = make_pair(i + 1, make_pair(1, -1));
                continue;
            }
            results[i][j] = make_pair((i + 1) * (j + 1), make_pair(1, -1));
        }
    }

    for (int i = 1; i < 60; ++i)
        for (int j = 1; j < 60; ++j)
        {
            for (int k = 1; k < i; ++k)
            {
                if (results[i - k][j].first + results[k - 1][j].first < results[i][j].first)
                {
                    results[i][j].first = results[i - k][j].first + results[k - 1][j].first;
                    results[i][j].second.second = -1;
                    results[i][j].second.first = k;
                }
            }

            for (int k = 1; k < j; ++k)
            {
                if (results[i][j - k].first + results[i][k - 1].first < results[i][j].first)
                {
                    results[i][j].first = results[i][j - k].first + results[i][k - 1].first;
                    results[i][j].second.second = 1;
                    results[i][j].second.first = k;
                }
            }
        }

    /*for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
            out << results[i][j].first << " ";
        out << std::endl;
    }/**/

    for (int i = 0; i < n; ++i)
    {
        int x, y;
        in >> x >> y;
        out << results[x - 1][y - 1].first << std::endl;

        output(out, 0, 0, x, y);
    }

    in.close();
    out.close();
    return 0;
}

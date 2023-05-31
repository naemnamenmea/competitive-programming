#include <fstream>

int main()
{
    std::ifstream in("folding.in");
    std::ofstream out("folding.out");

    int a = 0, b = 0;
    int w = 0, h = 0;

    in >> a >> b;
    in >> w >> h;

    if (w > std::min(a, b) && h > std::min(a, b))
    {
        out << "-1";
        return 0;
    }

    if (w > std::max(a, b) || h > std::max(a, b))
    {
        out << "-1";
        return 0;
    }

    int res1 = 0;

    int h1 = a;
    int w1 = b;

    while (h1 > h)
    {
        h1 = h1 / 2;
        res1++;
    }

    while(w1 > w)
    {
        w1 = w1 / 2;
        res1++;
    }

    int res2 = 0;

    int h2 = b;
    int w2 = a;

    while (h2 > h)
    {
        h2 = h2 / 2;
        res2++;
    }

    while(w2 > w)
    {
        w2 = w2 / 2;
        res2++;
    }

    if (h > b || w > a)
        out << res1;
    else if (h > a || w > b)
        out << res2;
    else
        out << std::min(res1, res2);

    in.close();
    out.close();
    return 0;
}

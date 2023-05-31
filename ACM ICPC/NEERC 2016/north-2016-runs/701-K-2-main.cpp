#include <fstream>

int toNumber(int y, int m = 0, int d = 0)
{
    return (y * 12 + m) * 50 + d;
}

int main()
{
    std::ifstream in("king.in");
    std::ofstream out("king.out");

    int num = -1;
    int current = 0;
    int king = 0;
    {
        int d, m, y;
        in >> d >> m >> y;
        king = toNumber(y, m, d);
    }

    int n = 0;
    in >> n;

    for (int i = 0; i < n; ++i)
    {
        int next = 0;
        {
            int d, m, y;
            in >> d >> m >> y;
            next = toNumber(y, m, d);
        }

        if (next + toNumber(18) > king)
            continue;

        if (num == -1 || current < next)
        {
            current = next;
            num = i + 1;
        }
    }

    /*int d, m, y;
    int num = -1;
    in >> d >> m >> y;
    int n = 0;
    in >> n;
    int da, ma, ya;

    for (int i = 0; i < n; ++i)
    {
        int dd, mm, yy;
        in >> dd >> mm >> yy;

        if (y < yy + 18)
            continue;
        if (y == yy)
        {
            if (m < mm)
                continue;
            if (m == mm && )
        }












        /*if (y - yy < 18)
            continue;
        if (y - yy == 18)
        {
            if (m < mm)
            {
                continue;
            }
            if (m == mm && d < dd)
            {
                continue;
            }
        }

        if (num == -1)
        {
            da = dd;
            ma = mm;
            ya = yy;
            num = i + 1;
            continue;
        }

        if (yy < ya)
            continue;
        if (yy == ya)
        {
            if (mm < ma)
                continue;
            if (mm == ma && dd <= da)
                continue;
        }
        ya = yy;
        ma = mm;
        da = d;
        num = i + 1;
    }*/

    out << num;
    in.close();
    out.close();
    return 0;
}

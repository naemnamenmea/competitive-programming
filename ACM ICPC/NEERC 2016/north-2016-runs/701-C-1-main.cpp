#include <fstream>
#include <algorithm>
#include <vector>

struct vertexInfo
{
    int x;
    int y;

    int i;
    int j;
    int maxX;
    int maxY;

    int ans = 0;
};

struct Rect
{
    int x1;
    int y1;
    int x2;
    int y2;

    int num = 0;
};

vertexInfo *ratings = 0;

bool compX(int left, int right)
{
    return ratings[left].x < ratings[right].x;
}

bool compY(int left, int right)
{
    return ratings[left].y < ratings[right].y;
}

int main()
{
    std::ifstream in("codecoder.in");
    std::ofstream out("codecoder.out");

    int n;
    in >> n;

    ratings = new vertexInfo[n];

    int *xCoor = new int[n];
    int *yCoor = new int[n];
    for (int i = 0; i < n; ++i)
    {
        in >> ratings[i].x >> ratings[i].y;
        xCoor[i] = yCoor[i] = i;
    }
    in.close();

    std::sort(xCoor, xCoor + n, compX);
    std::sort(yCoor, yCoor + n, compY);

    int *maxX = new int[n];
    int *maxY = new int[n];

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            maxX[i] = ratings[xCoor[i]].y;
            maxY[i] = ratings[yCoor[i]].x;
        }
        else
        {
            maxX[i] = std::max(ratings[xCoor[i]].y, maxX[i - 1]);
            maxY[i] = std::max(ratings[yCoor[i]].x, maxY[i - 1]);
        }
        ratings[xCoor[i]].x = i;
        ratings[yCoor[i]].y = i;
        ratings[xCoor[i]].maxX = maxX[i];
        ratings[yCoor[i]].maxY = maxY[i];
    }

    std::vector<Rect> rects;
    int shift = 0;
    while (shift < n)
    {
        Rect newRect;
        if (rects.size())
        {
            newRect.x1 = rects[rects.size() - 1].x2;
            newRect.y1 = rects[rects.size() - 1].y2;
        }
        else
        {
            newRect.x1 = newRect.y1 = 0;
        }

        int move = 1;
        int j = shift;
        while (move != 0)
        {
            if (move)
            {
                int y = ratings[xCoor[j]].maxY;
                int l = j;
                int r = n - 1;
                while (l < r)
                {
                    int m = (l + r + 1) / 2;
                    if (maxY[m] > y)
                    {
                        r = m - 1;
                    }
                    else
                    {
                        l = m;
                    }
                }

                if (l == j)
                {
                    move = 0;
                    break;
                }
                j = l;
                move = -1;
                continue;
            }

            int x = ratings[yCoor[j]].maxX;
            int l = j;
            int r = n - 1;
            while (l < r)
            {
                int m = (l + r + 1) / 2;
                if (maxX[m] > x)
                {
                    r = m - 1;
                }
                else
                {
                    l = m;
                }
            }

            if (l == j)
            {
                move = 0;
                break;
            }
            j = l;
            move = 1;
        }

        newRect.x2 = maxX[j];
        newRect.y2 = maxY[j];
        rects.push_back(newRect);
        shift = j + 1;
    }

    /*for (int i = 0; i < n; ++i)
        out << xCoor[i] << " " << yCoor[i] << " " << maxX[i] << " " << maxY[i] << std::endl;*/

    for (int i = 0, shift = 0; i < n; ++i)
    {
        if (rects[shift].x2 <= maxX[i] && rects[shift].y2 <= maxY[i])
        {
            int delta = rects[shift++].num;
            rects[shift].num = delta;
        }
        ++rects[shift].num;
    }

    for (int i = 0, shift = 0; i < n; ++i)
    {
        if (rects[shift].x2 <= maxX[i] && rects[shift].y2 <= maxY[i])
        {
            ++shift;
        }
        ratings[xCoor[i]].ans = rects[shift].num - 1;
    }

    for (int i = 0; i < n; ++i)
        out << ratings[i].ans << std::endl;

    out.close();
    return 0;
}

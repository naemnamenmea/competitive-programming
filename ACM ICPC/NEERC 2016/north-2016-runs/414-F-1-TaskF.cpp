#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long H, W, h, w;
    long count = 0;
    fstream fileStream;
    fileStream.open("folding.in", ios::in);
    fileStream >> W >> H >> w >> h;

    fileStream.close();
    fileStream.open("folding.out", ios::out);
    if (w > W && w > H || h > W && h > H) fileStream << -1;
    else
    {
        if (w > W || h > H)
            swap(W, H);
        while (W != w || H != h)
        {
            if (W != w)
            {
                if (W - w >= W / 2 + W % 2)
                {
                    ++count;
                    W -= W / 2;
                }
                else
                {
                    W -= W - w;
                    ++count;
                }
            }
            if (H != h)
            {
                if (H - h >= H / 2 + H % 2)
                {
                    ++count;
                    H -= H / 2;
                }
                else
                {
                    H -= H - h;
                    ++count;
                }
            }
        }
        fileStream << count;
    }

    fileStream.close();
    return 0;
}

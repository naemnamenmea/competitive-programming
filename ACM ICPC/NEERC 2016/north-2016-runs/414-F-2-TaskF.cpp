#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long H, W, h, w;
    long H1, W1;
    long count = 0;
    long count1 = 0;
    bool flag = false;
    fstream fileStream;
    fileStream.open("folding.in", ios::in);
    fileStream >> W >> H >> w >> h;
    fileStream.close();
    fileStream.open("folding.out", ios::out);
    if (w > W && w > H || h > W && h > H) fileStream << -1;
    else
    {
        if (w > W || h > H)
        {
            flag = true;
            swap(W, H);
        }
        if (!flag)
        {
            H1=H;
            W1=W;
            swap(H1, W1);
            while (W1 != w || H1 != h)
            {
                if (W1 != w)
                {
                    if (W1 - w >= W1 / 2 + W1 % 2)
                    {
                        ++count1;
                        W1 -= W1 / 2;
                    }
                    else
                    {
                        W1 -= W1 - w;
                        ++count1;
                    }

                }
                if (H1 != h)
                {
                    if (H1 - h >= H1 / 2 + H1 % 2)
                    {
                        ++count1;
                        H1 -= H1 / 2;
                    }
                    else
                    {
                        H1 -= H1 - h;
                        ++count1;
                    }
                }
            }
        }
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
        if (!flag) {
            if (count < count1) fileStream << count;
            else fileStream << count1;
        }
        else fileStream << count;
    }

    fileStream.close();
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long h, w;
    long x0, y0, x1, y1;
    long yRes0=0, yRes1=0, xRes0=0, xRes1=0;
    fstream fileStream;
    fileStream.open("anniversary.in", ios::in);

    fileStream >> w >> h >> x0 >> y0 >> x1 >> y1;
 fileStream.close();
    fileStream.open("anniversary.out", ios::out);

    // x0 - ������
    if (x0 >= x1)
    {
        // � ����
        if (y0 >= y1)
            if (x0 > h - y0)
            {
                yRes0 = h;
                xRes0 = x0 - (h - y0);
            }
            else
            {
                xRes0 = 0;
                yRes0 = y0 + x0;
            }
        // ����
        else
        {
            if (x0 >= y0)
            {
                yRes0 = 0;
                xRes0 = x0 - y0;
            }
            else
            {
                xRes0 = 0;
                yRes0 = y0 - x0;
            }
        }
    }
    //�����
    else
    {
        //����
        if (y0 >= y1)
            if (w - x0 > h - y0)
            {
                yRes0 = h;
                xRes0 = x0 + (h - y0);
            }
            else
            {
                xRes0 = w;
                yRes0 = y0 + w - x0;
            }
        // ����
        else
        {
            if (w - x0 >= y0)
            {
                yRes0 = 0;
                xRes0 = x0 + y0;
            }
            else
            {
                xRes0 = w;
                yRes0 = y0 - w + x0;
            }
        }
    }

    if (x1 > x0)
    {
        // � ����
        if (y1 > y0)
            if (x1 >= h - y1)
            {
                yRes1 = h;
                xRes1 = x1 - (h - y1);
            }
            else
            {
                xRes1 = 0;
                yRes1 = y1 + x1;
            }
        // ����
        else
        {
            if (x1 >= y1)
            {
                yRes1 = 0;
                xRes1 = x1 - y1;
            }
            else
            {
                xRes1 = 0;
                yRes1 = y1 - x1;
            }
        }
    }
    //�����
    else
    {
        //����
        if (y1 > y0)
            if (w - x1 >= h - y1)
            {
                yRes1 = h;
                xRes1 = x1 + (h - y1);
            }
            else
            {
                xRes1 = w;
                yRes1 = y1 + w - x1;
            }
        // ����
        else
        {
            if (w - x1 >= y1)
            {
                yRes1 = 0;
                xRes1 = x1 + y1;
            }
            else
            {
                xRes1 = w;
                yRes1 = y1 - w + x1;
            }
        }
    }
    fileStream << xRes0 << " " << yRes0 << " " << xRes1 << " " << yRes1;
    fileStream.close();
    return 0;
}

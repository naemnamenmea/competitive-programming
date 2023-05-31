#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int N, x, y, i;
    fstream fileStream;
    fileStream.open("boysgirls.in", ios::in);
    fileStream >> N >> x >> y;
    fileStream.close();
    fileStream.open("boysgirls.out", ios::out);
    if (x + y != N + 2) fileStream << "Impossible";
    else {
        if (x <= y) {
            for (i = 1; i < x; ++i) fileStream << "BG";
            for (i = 0; i < y - x; ++i) fileStream << "G";
        }
        else {
            for (i = 1; i < y; ++i) fileStream << "GB";
            for (i = 0; i < x - y; ++i) fileStream << "B";
        }
    }
    fileStream.close();
    return 0;
}

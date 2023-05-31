#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("anniversary.in");
    int w,h;
    int ax,ay;
    int bx,by;
    fin >> w >> h >> ax >> ay >> bx >> by;
    fin.close();

    ofstream fout("anniversary.out");

    if(ax!=bx)
    {
        fout << ax << " " << "0" << " " << bx <<  " " << h;
    }
    else
    {
        fout << "0" << " " << ay << " " << by << " " << w;
    }
    fout.close();

    return 0;
}


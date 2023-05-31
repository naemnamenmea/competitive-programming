#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("anniversary.in");
    float w,h;
    float ax,ay;
    float bx,by;
    char space=' ';
    fin >> w >> h >> ax >> ay >> bx >> by;
    fin.close();

    ofstream fout("anniversary.out");

    if(ax!=bx)
    {
        fout << ax << space << "0" << " " << bx <<  " " << h;
    }
    else
    {
        fout << "0" << " " << ay << " " << by << " " << w;
    }
    fout.close();

    return 0;
}


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("anniversary.in");
    int w,h;
    int ax,ay;
    int bx,by;
    int k1, k2;
    int buf;
    fin >> w >> h >> ax >> ay >> bx >> by;
    fin.close();

    ofstream fout("anniversary.out");
    if((ax-bx)%2==0){
        buf=(ax+bx)/2;

        fout << buf << " " << "0" << " " << buf << " " << h;
        fout.close();
        return 0;
    }
    if(ay==by)
    {
        fout << ax << " " << "0" << " " << bx <<  " " << h;
        fout.close();
        return 0;
    }
    if(ax==bx){
        fout << "0" << " " << ay << " " << w <<  " " << by;
        fout.close();
        return 0;
    }
    if(ax!=bx){
        fout << ax << " " << "0" << " " << bx <<  " " << h;
        fout.close();
        return 0;
    }
    return 0;
}


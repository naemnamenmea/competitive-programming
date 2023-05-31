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
    float tga,tgb,tgc;
    float i;
    fin >> w >> h >> ax >> ay >> bx >> by;
    fin.close();
    tga = ax/ay;
    tgb = bx/by;
    i=0;
    while(true)
    {
        tgc = i/h;
        if(((tga>tgc) && (tgb<tgc)) || ((tga<tgc) && (tgb>tgc)))
        {
            ofstream fout("anniversary.out");
            fout << "0 0" << space << i << space << h;
            fout.close();
            return 0;
        }
        i++;
        if(i>w) break;
    }
    i=h;
    while(true)
    {
        tgc = w/i;
        if(((tga>tgc) && (tgb<tgc)) || ((tga<tgc) && (tgb>tgc)))
        {
            ofstream fout("anniversary.out");
            fout << "0 0" << space << w << space << i;
            fout.close();
            return 0;
        }
        i--;
        if(i<=0) break;
    }
    return 0;
}









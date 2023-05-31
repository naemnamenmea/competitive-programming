#include <fstream>

using namespace std;

int main()
{

    ifstream in("anniversary.in");
    ofstream out ("anniversary.out");
    long long w,h,x1,x2,y1,y2,x3,y3,x4,y4;
    in>>w>>h>>x1>>y1>>x2>>y2;
    if (x1!=x2)
    {
              x3=min(x1,x2); y3=0;
              x4=min(x1,x2)+1; y4=h;

    } else {
        x3=0; y3=min(y1,y2);
        x4=w; y4=min(y1,y2)+1;
    }
    out<<x3<<' '<<y3<<' '<<x4<<' '<<y4;
    return 0;
}

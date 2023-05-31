#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream in("anniversary.in");
    int w, h;
    int ax, ay, bx, by;
    in>>w>>h>>ax>>ay>>bx>>by;
    in.close();

    int sx, sy;
    int ex, ey;

    int distX = abs(ax - bx);
    int distY = abs(ay - by);

    int lineKoeff = 0;

    if(distX > 1){
        ex = sx = min(ax, bx) + 1;
        sy = 0;
        ey = h;
    }
    else
    if(distY > 1){
        ey = sy = min(ay, by) + 1;
        sx = 0;
        ex = w;
    }
    else{
        if(ax > bx){
            int h = ax;
            ax = bx;
            bx = h;

            h = ay;
            ay = by;
            by = h;
        }

        if((distX == 1) && (distY == 1)){
            if(ay > by){
                int toUp = h - ay;
                int toRight = w - bx;
                int minDist = min(toUp, toRight);
                ex = bx + minDist;
                ey = ay + minDist;

                int toDown = by;
                int toLeft = ax;
                minDist = min(toDown, toLeft);
                sx = ax - minDist;
                sy = by - minDist;
            }
            else{
                int toUp = h - by;
                int toLeft = ax;
                int minDist = min(toUp, toLeft);
                sx = ax - minDist;
                sy = by + minDist;

                int toDown = ay;
                int toRight = w - bx;
                minDist = min(toDown, toRight);
                ex = bx + minDist;
                ey = ay - minDist;
            }
        }
        else{
            if(distY == 0){
                sx = ax;
                sy = 0;

                ex = bx;
                ey = h;
            }
            else{
                sx = 0;
                sy = ay;

                ex = w;
                ey = by;
            }
        }
    }


    ofstream out("anniversary.out");
    out<<sx<<" "<<sy<<" "<<ex<<" "<<ey;
    out.close();
}

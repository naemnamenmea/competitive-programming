#include <fstream>
#include <vector>

using namespace std;

struct date{
    int d;
    int m;
    int y;
    int numb;
};

int main()
{
    ifstream in ("king.in");
    ofstream out("king.out");

    date k;
    in>>k.d>>k.m>>k.y;
    int n;
    in>>n;
    vector <date> sons(n);
    for (int i = 0; i<n; i++)
    {
        in>>sons[i].d>>sons[i].m>>sons[i].y;
        sons[i].numb = i+1;
    }

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<i-1; j++)
        {
            if (sons[j].y<sons[j+1].y)
            {
                swap(sons[j],sons[j+1]);
            }else if (sons[j].y==sons[j+1].y && sons[j].m<sons[j+1].m)
            {
                swap(sons[j],sons[j+1]);
            } else if (sons[j].y==sons[j+1].y && sons[j].m==sons[j+1].m && sons[j].d<sons[j+1].d)
            {
                swap(sons[j],sons[j+1]);
            }
        }
    }

    for (int i = 0; i<n; i++)
    {
        if (k.y-sons[i].y==18&&k.m-sons[i].m==0&&k.d-sons[i].d>=0)
        {
            out<<sons[i].numb<<endl;
            break;
        }else if (k.y-sons[i].y==18&&k.m-sons[i].m>0)
        {

            out<<sons[i].numb<<endl;
            break;
        }else if (k.y-sons[i].y>18)
        {
            out<<sons[i].numb<<endl;
            break;
        }

        if (i==n-1)
        {
            out<<-1;
        }
    }

    return 0;
}

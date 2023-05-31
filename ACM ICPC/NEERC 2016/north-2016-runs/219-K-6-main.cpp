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

    int d1, m1, y1, numb1;

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
        for (int j = 0; j<n-1; j++)
        {
            if (sons[j].y<sons[j+1].y)
            {
                d1 = sons[j].d;
                m1 = sons[j].m;
                y1 = sons[j].y;
                numb1 = sons[j].numb;
                sons[j].d = sons[j+1].d;
                sons[j].m = sons[j+1].m;
                sons[j].y = sons[j+1].y;
                sons[j].numb = sons[j+1].numb;
                sons[j+1].d = d1;
                sons[j+1].m = m1;
                sons[j+1].y = y1;
                sons[j+1].numb = numb1;



            }else if (sons[j].y==sons[j+1].y && sons[j].m<sons[j+1].m)
            {
                d1 = sons[j].d;
                m1 = sons[j].m;
                y1 = sons[j].y;
                numb1 = sons[j].numb;
                sons[j].d = sons[j+1].d;
                sons[j].m = sons[j+1].m;
                sons[j].y = sons[j+1].y;
                sons[j].numb = sons[j+1].numb;
                sons[j+1].d = d1;
                sons[j+1].m = m1;
                sons[j+1].y = y1;
                sons[j+1].numb = numb1;



            } else if (sons[j].y==sons[j+1].y && sons[j].m==sons[j+1].m && sons[j].d<sons[j+1].d)
            {
                d1 = sons[j].d;
                m1 = sons[j].m;
                y1 = sons[j].y;
                numb1 = sons[j].numb;
                sons[j].d = sons[j+1].d;
                sons[j].m = sons[j+1].m;
                sons[j].y = sons[j+1].y;
                sons[j].numb = sons[j+1].numb;
                sons[j+1].d = d1;
                sons[j+1].m = m1;
                sons[j+1].y = y1;
                sons[j+1].numb = numb1;


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

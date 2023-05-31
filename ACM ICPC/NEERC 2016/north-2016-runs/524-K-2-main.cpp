#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("king.in");
    ofstream fout("king.out");
    int kd,km,ky;
    int n,k,j;
    int dmin, mmin, ymin;
    fin >> kd >> km >> ky >> n;
    int sd[n],sm[n],sy[n];
    int gd[n],gm[n],gy[n];

    for(int i=0;i<n;i++)
    {
        fin >> sd[i] >> sm[i] >> sy[i];
    }
    fin.close();
    k=0;
    for(int i=0;i<n;i++)
    {
        if((sy[i]+18)<ky){
            gd[k] = sd[i];
            gm[k] = sm[i];
            gy[k] = sy[i];
            k++;
        }
        if((sy[i]+18)==ky){
            if(sm[i]<km)
            {
                gd[k] = sd[i];
                gm[k] = sm[i];
                gy[k] = sy[i];
                k++;
            }
            if(sm[i]==km)
            {
                if(sd[i]<=kd)
                {
                     gd[k] = sd[i];
                     gm[k] = sm[i];
                     gy[k] = sy[i];
                     k++;
                }
            }
        }
    }

    if(k==0)
    {
        fout << -1;
        fout.close();
        return 0;
    }

    dmin=gd[0];
    mmin=gm[0];
    ymin=gy[0];

    for(int i=0; i<k; i++){
        if(ymin<gy[i]){
            dmin=gd[i];
            mmin=gm[i];
            ymin=gy[i];
            continue;
        }
        if(ymin==gy[i]){
            if(mmin<gm[i])
            {
                dmin=gd[i];
                mmin=gm[i];
                ymin=gy[i];
                continue;
            }
            if(mmin==gm[i])
            {
                if(dmin<=gd[i])
                {
                    dmin=gd[i];
                    mmin=gm[i];
                    ymin=gy[i];
                    continue;
                }
            }
        }
    }
    char a;
    for(int i=0;i<n;i++)
    {
        if((dmin ==sd[i]) && (mmin==sm[i]) && (ymin == sy[i]))
        {
            itoa(i+1,&a,10);
            fout << a;
            fout.close();
            return 0;
        }
    }
    return 0;
}

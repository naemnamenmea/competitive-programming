#include <bits/stdc++.h>

using namespace std;

#define taskname "java2016"
#define taski taskname".in"
#define tasko taskname".out"

#define inp freopen(taski, "r", stdin)
#define outp freopen(tasko, "w", stdout)

#define mp make_pair
#define fi first
#define se second

int c;

/*int main()
{
    inp;outp;
    cin >> c;
    if(c==0)
    {
        cout << "? /?/ ?" << endl;
        return 0;
    }
    cout << "a = ? max ?" << endl;
    cout << "c = (a / a)" << endl;
    cout << "b = (c + c)" << endl;
    bool have=false;
    for(int i=0;i<8;i++)
    {
        if(c%2==1)
        {
            if(have)cout << " + ";
            have=true;
            if(i==0)cout << "c";
            for(int j=0;j<i;j++)
                if(i!=0&&j==0)cout << "b"; else  cout << " * b";
        }
        c/=2;
    }
    return 0;
}*/

int main()
{
    inp;outp;
    cin >> c;
    if(c==0)
    {
        cout << "? /?/ ?" << endl;
        return 0;
    }
    cout << "a = (? max ?) max (? max ?)" << endl;
    cout << "c = (a / a) max (a / a)" << endl;
    //cout << "b = (c + c) max (c + c)" << endl;
    bool have=false;
    for(int i=0;i<8;i++)
    {
        if(c%2==1)
        {
            if(have)cout << " + ";
            have=true;
            if(i==0)cout << "c";
            for(int j=0;j<i;j++)
                if(i!=0&&j==0)cout << "( c + c )"; else  cout << " * ( c + c )";
        }
        c/=2;
    }
    return 0;
}

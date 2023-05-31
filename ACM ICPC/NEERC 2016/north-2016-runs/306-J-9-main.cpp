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
    cout << "a = ( ? max ? )" << endl;
    cout << "k = ( a max a )" << endl;
    cout << "e = ( k max k )" << endl;
    cout << "f = ( e max e )" << endl;
    cout << "g = ( f max f )" << endl;
    cout << "h = ( g max g )" << endl;
    cout << "q = ( h max h )" << endl;
    cout << "t = ( q max q )" << endl;
    cout << "y = ( t max t )" << endl;
    cout << "x = ( y max y )" << endl;
    cout << "c = (x / x) max (x / x)" << endl;
    cout << "b = (c + c) max (c + c)" << endl;
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
}

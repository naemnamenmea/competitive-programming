#include <bits/stdc++.h>
using namespace std;

int main() {
 freopen("java2016.in","r",stdin);
freopen("java2016.out","w",stdout);
    int n;
    cin >> n;
    if (n == 0) {
        cout << "? /?/ ?";
        return 0;
    }
    cout << "a = ? max ?" << endl;
    cout << "b = ((? max ?) max (? max ?)) / (? max ?) + ((? max ?) max (? max ?)) / (? max ?)" << endl;
    string s = "";
    if ( n % 2)
     s += "((? max ?) max (? max ?)) / (? max ?)";
    for (int i = 1;i < 8;i++)
    {
        if ((n >> i) & 1)
        {
            string s2 = "+(b)";
            for (int j =0;j < i;j++)
            {
               s2 += "*b";
               s += s2;
            }
        }
    }

   cout << s;



    return 0;
}

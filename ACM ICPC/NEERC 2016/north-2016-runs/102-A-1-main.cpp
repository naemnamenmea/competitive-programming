#include <bits/stdc++.h>

using namespace std;

typedef long long lol;

#define foi freopen("anniversary.in", "r", stdin);
#define foi freopen("anniversary.out", "w", stdout);

int main()
{
    foi;
    foo;
    lol w, h, a_x, a_y, b_x, b_y;
    cin>>w>>h>>a_x>>a_y>>b_x>>b_y;
    if (a_x == b_x)
    {
        cout<<0<<' '<<min(a_y, b_y)<<' '<<w<<' '<<max(a_y, b_y)<<endl;
        return 0;
    }
    cout<<min(a_x, b_x)<<' '<<0<<' '<<max(a_x, b_x)<<' '<<h<<endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long lol;

#define foi freopen("folding.in", "r", stdin);
#define foo freopen("folding.out", "w", stdout);

int main()
{
    foi;
    foo;
    lol W, H, w, h;
    cin>>W>>H>>w>>h;
    if (w>h)
        swap(w, h);
    if (W>H)
        swap(W, H);
    if (w>W || h>H)
    {
        printf("-1\n");
        return 0;
    }
    lol ans = 0;
    while (W>w)
    {
        if (W%2)
        {
            W/=2;
            W++;
        }
        else
            W/=2;
        ans++;
    }
    while (H>h)
    {
        if (H%2)
        {
            H/=2;
            H++;
        }
        else
            H/=2;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

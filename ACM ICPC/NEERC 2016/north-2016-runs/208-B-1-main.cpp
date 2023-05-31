#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("boysgirls.in");
    ofstream fout("boysgirls.out");

    long long n, x, y;
    string c, c1;
    fin >> n >> x >> y;
    long long min_val = min(x, y), max_val = max(x, y);

    if(min_val == x)
    {
        c = "B";
        c1 = "G";
    }
    else
    {
        c = "G";
        c1 = "B";
    }

    string ans = "";

    for(int i = 0; i < min_val-1; i++)
        ans += c+c1;

    for(int i = 0; i < max_val-min_val; i++)
        ans += c1;

    if(ans.size() == n)
        fout << ans;
    else fout << "Impossible";


    return 0;
}

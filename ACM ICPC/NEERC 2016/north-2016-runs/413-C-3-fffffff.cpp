#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main ()
{
    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);
    int n;
    cin >> n;
    int a[2][n+1];
    pair<int,int> m1[n+1];
    pair<int,int> m2[n+1];
    for (int i = 1; i < n+1; i++)
    {
        cin >> a[0][i] >> a[1][i];
        m1[i].second = i;
        m1[i].first = a[0][i];
        m2[i].second = i;
        m2[i].first = a[1][i];
    }
    pair <int,int> m11[n+1] = m1;
    sort(m1+1, m1 + n+1);
    for(int i = 1; i < n+1; i++)
        cout << m1[i].second << " " << m1[i].first << '\n';
    cout << '\n';
    sort(m2+1, m2 + n+1);
    int v1[n+1];
    int v2[n+1];
    int a1[n+1];
    int a2[n+1];
    for(int i = 1; i < n+1 ; i++)
    {
        v1[i] = m1[i].second;
        v2[i] = m2[i].second;
        a1[m1[i].second] = i;
        a2[m2[i].second] =i;
    }
    int p1 = n;
    int p2 = n;
    int s[n+1];
    int l = p2-1;


    while (p1 > 0 && p2 > 0 )
    {
        int nu = a1[p1];
        s[nu] = l;
        int mu = v2[nu];
        if (mu <= p2)
        {


        for(int i = mu; i < p2+1; i++)
            {
                s[a2[i]]= l;
                p2 = mu - 1;
                l = p2 - 1;
            }
        }
        p1--;
    }

for(int i = 1;i < n+1; i++ )
{
        cout << s[i] << '\n';
}
}



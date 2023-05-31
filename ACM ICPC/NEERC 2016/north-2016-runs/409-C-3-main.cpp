#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("codecoder.in","r",stdin);
    freopen("codecoder.out","w",stdout);
    unsigned long long n, i, j;
    cin >> n;
    unsigned long long a[n][2];
    for(i=0;i<n;i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    for(i=0;i<n;i++)
    {
        unsigned long long k = 0;
        for(j=0;j<n;j++)
        {
            if((a[i][0] > a[j][0]) || (a[i][1] > a[j][1]))
            k++;
        }
        cout << k << "\n";
    }
    return 0;
}

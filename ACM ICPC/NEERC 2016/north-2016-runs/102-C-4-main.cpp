#include <bits/stdc++.h>

using namespace std;

typedef long long lol;

#define foi freopen("codecoder.in", "r", stdin);
#define foo freopen("codecoder.out", "w", stdout);

const int Max_N = 100001;

vector <pair <int, int> > a;
vector <pair <int, int> > b;
vector <pair <int, int> > data;

int ans [Max_N];

bool comp(pair<int, int> x, pair <int, int> y)
{
    if (x.second > y.second)
        return false;
    return true;
}

bool ok(int i, int j)
{
    if (data[i].first > data[j].first || data[i].second > data[j].second)
        return true;
    return false;
}

int main()
{
    foi;
    foo;
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a.push_back(make_pair(i, x));
        b.push_back(make_pair(i, y));
        data.push_back(make_pair(x, y));
    }
    /*sort(a.begin(), a.end(), comp);
    sort(b.begin(), b.end(), comp);
    for (int i = 0; i<n; i++)
    {
        ans[a[i].first] += i;
    }
    for (int i = 0; i<n; i++)
    {
        ans[b[i].first]+=i;
        for (int j = 0; j<i; j++)
        {
            if (data[b[i].first].first > data[b[j].first].first)
            {
                ans[b[i].first]--;
            }
        }
    }*/
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            if (ok(i, j))
                ans[i]++;
        }
    for (int i = 0; i<n; i++)
        printf("%d\n", ans[i]);
    return 0;
}

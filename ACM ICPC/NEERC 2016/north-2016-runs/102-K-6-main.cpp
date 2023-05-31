#include <bits/stdc++.h>

using namespace std;

typedef long long lol;

#define foi freopen("king.in", "r", stdin);
#define foo freopen("king.out", "w", stdout);


struct son
{
    int day;
    int month;
    int year;
    int id;
};

vector <son> s;
int dayk, monthk, yeark; //DMY of kings deadh

bool comp(son x, son y)
{
    if (x.year > y.year)
        return false;
    if (x.year == y.year)
    {
        if (x.month > y.month)
            return false;
        if (x.month == y.month)
        {
            if (x.day > y.day)
                return false;
            return true;
        }
        return true;
    }
    return true;
}

bool ok(int i)
{
    if (yeark - s[i].year > 18)
        return true;
    if (yeark - s[i].year == 18)
    {
        if (monthk > s[i].month)
            return true;
        if (monthk == s[i].month)
        {
            if (dayk >= s[i].day)
                return true;
            return false;
        }
        return false;
    }
    return false;
}

/*22 10 2016
7
28 2 1999
22 7 1995
21 10 1998
23 10 1998
3 9 2000
1 4 2013
17 12 2004*/


int main()
{
    foi;
    foo;
    cin >> dayk >> monthk >> yeark;
    int n;
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        int d, m, y;
        scanf("%d%d%d", &d, &m, &y);
        s.push_back({d, m, y, i});
    }
    sort(s.begin(), s.end(), comp);
    reverse(s.begin(), s.end());
    for (int i = 0; i<n; i++)
    {
        if (ok(i))
        {
            printf("%d", s[i].id+1);
            return 0;
        }

    }
    printf("-1\n");
    return 0;
}


/*
int main()
{

    lol dayk, monthk, yeark; //DMY of kings deadh
    cin >> dayk >> monthk >> yeark;
    vector <lol> d, m , y;
    lol n; cin >> n;
    lol ans = -1;
    for (lol i = 0; i < n; ++i) {
        lol di, mi, yi;
        cin >> di >> mi >> yi;
        d.push_back(di);
        m.push_back(mi);
        y.push_back(yi);
    }
    // readed input
    lol day = dayk, month = monthk, year = yeark; // DMKof candidates born
    for (lol i = 0 ; i < n ; ++i) {
            //if prince younger thn 18 he is not revelated
        if (yeark - y[i] < 18) {goto shame;}
        if ( yeark - y[i] == 18) {
            if ((monthk - m[i] <= 0) && (year - y[i] >= 0)) {
                if (month - m[i] > 0) {
                    ans = i + 1;
                    day = d[i];
                    month = m[i];
                    year = y[i];
                    goto shame;
                }
                if ((month - m[i] == 0) && (year - y[i] >= 0)) {
                    if (dayk - d[i]>= 0) {
                        if (day - d[i] > 0) {
                            ans = i + 1;
                            day = d[i];
                            month = m[i];
                            year = y[i];
                            goto shame;
                        }
                    }
                }
            }
            else goto shame;
        }
        if (yeark - y[i] > 18) {
            if (month - m[i] > 0 && (year - y[i] >= 0)) {
                    ans = i + 1;
                    day = d[i];
                    month = m[i];
                    year = y[i];
                    goto shame;
            }
            if (month - m[i] < 0 && (year - y[i] >= 0)) {
                goto shame;
            }
            if (month - m[i] == 0) {
                if (day - d[i] > 0) {
                    ans = i + 1;
                    day = d[i];
                    month = m[i];
                    year = y[i];
                    goto shame;
                }
            }
        }
        shame:;
    }
    cout << ans;
    return 0;
}
*/


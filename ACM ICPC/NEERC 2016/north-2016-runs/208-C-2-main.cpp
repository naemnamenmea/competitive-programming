#include <bits/stdc++.h>

using namespace std;

struct node
{
    int l, r, id;
    node(int a, int b, int c)
    {
        l = a;
        r = b;
        id = c;
    }
};

bool cmpl(node a, node b)
{
    return a.l < b.l;
}
bool cmpr(node a, node b)
{
    return a.r < b.r;
}

int n, q, z;
int il[100100], ir[100100], w[100100], rl[1001000], rr[1001000];
vector<node> a, b;


int main()
{
//##################################
#ifndef DEBUG
    #define prob "codecoder"
    freopen(prob ".in",  "r", stdin);
    freopen(prob ".out",  "w", stdout);
#endif
//##################################
//##################################
#ifdef DEBUG
    freopen("../input.txt",  "r", stdin);
    freopen("../output.txt",  "w", stdout);
    //freopen("../debug.txt",  "w", stderr);
#endif
//##################################
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(node(x, y, i));
        b.push_back(node(x, y, i));
        rl[x]++;
        rr[y]++;
    }
    sort(a.begin(), a.end(), cmpl);
    sort(b.begin(), b.end(), cmpr);

    for (int i = 1; i < n; i++)
    {
        if (a[i].l > a[i - 1].l)
            q++;
        if (b[i].r > b[i - 1].r)
            z++;
        il[a[i].id] = q;
        ir[b[i].id] = z;
    }
    for (int i = 0; i < n; i++)
    {
        node t = a[i];
        w[t.id] = i - rl[t.l] + 1;

        for (int j = ir[t.id] - 1; j >= 0; j--)
            if (b[j].r < t.r && il[b[j].id] > i)
                w[t.id]++;

    }

    for (int i = 0; i < n; i++)
        cout << w[i] << endl;
    return 0;
}

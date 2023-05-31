#include <bits/stdc++.h>

using namespace std;

#define TASK "hard"
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 65;
const int inf = 1.01e9;


int mem[N * N];

int get(int w, int h)
{
    int v = w * N + h;
    if (mem[v] != -1) return mem[v];
    int &res = mem[v];
    res = inf;

    if (w == h)
    {
        res = 1;
        return res;
    }
    
    for (int x = 1; x <= w - 1; ++x)
    {
        res = min(res, get(x, h) + get(w - x, h));
    }
    for (int y = 1; y <= h - 1; ++y)
    {
        res = min(res, get(w, y) + get(w, h - y));
    }
    for (int x1 = 1; x1 <= w - 1; ++x1) for (int x2 = x1 + 1; x2 <= w - 1; ++x2)
    {
        for (int y1 = 1; y1 <= h - 1; ++y1) for (int y2 = y1 + 1; y2 <= h - 1; ++y2)
        {
            res = min(res, get(x2, y1) + get(w - x2, y2)  + get(w - x1, h - y2) + get(x1, h - y1) + get(x2 - x1, y2 - y1));
        }
    }
    return res;
}

tuple<int, int, int, int> res[N * N];
int resc = 0;


void solve(int stx, int sty, int w, int h)
{
    if (w == h)
    {
        res[resc++] = make_tuple(stx, sty, stx + w, sty + h);
        return;
    }

    int want = get(w, h);

    for (int x = 1; x <= w - 1; ++x)
    {
        if (want == get(x, h) + get(w - x, h))
        {
            solve(stx, sty, x, h);
            solve(stx + x, sty, w - x, h);
            return;
        }
    }

    for (int y = 1; y <= h - 1; ++y)
    {
        if (want == get(w, y) + get(w, h - y))
        {
            solve(stx, sty, w, y);
            solve(stx, sty + y, w, h - y);
            return;
        }
    }
    /*
        for (int x1 = 1; x1 <= w - 1; ++x1) for (int x2 = x1 + 1; x2 <= w - 1; ++x2)
    {
        for (int y1 = 1; y1 <= h - 1; ++y1) for (int y2 = y1 + 1; y2 <= h - 1; ++y2)
        {
            res = min(res, get(x2, y1) + get(w - x2, y2)  + get(w - x1, h - y2) + get(x1, h - y1) + get(x2 - x1, y2 - y1));
        }
    }
    */
    for (int x1 = 1; x1 <= w - 1; ++x1) for (int x2 = x1 + 1; x2 <= w - 1; ++x2)
    {
        for (int y1 = 1; y1 <= h - 1; ++y1) for (int y2 = y1 + 1; y2 <= h - 1; ++y2)
        {
            int val = get(x2, y1) + get(w - x2, y2)  + get(w - x1, h - y2) + get(x1, h - y1) + get(x2 - x1, y2 - y1);
            if (want == val)
            {
                solve(stx, sty, x2, y1);
                solve(stx + x2, sty, w - x2, y2);
                solve(stx + x1, sty + y2, w - x1, h - y2);
                solve(stx, sty + y1, x1, h - y1);
                solve(stx + x1, sty + y1, x2 - x1, y2 - y1);
                return;
            }
        }
    }

    assert(false);
}


int main() {
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    
    memset(mem, -1, sizeof mem);

    int tn;
    scanf("%d", &tn);
    forn(tt, tn)
    {
        int w, h;
        scanf("%d%d", &w, &h);

        eprintf("get = %d\n", get(w, h));
        resc = 0;
        solve(0, 0, w, h);
        printf("%d\n", resc);
        forn(i, resc)
        {
            int x1, y1, x2, y2;
            tie(x1, y1, x2, y2) = res[i];
            assert(x2 - x1 == y2 - y1);
            printf("%d %d %d\n", x1, y1, x2 - x1);
        }
    }


    return 0;
}

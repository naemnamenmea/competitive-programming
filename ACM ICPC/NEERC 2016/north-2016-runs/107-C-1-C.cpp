#include <bits/stdc++.h>

using namespace std;

#define FILENAME "codecoder"

#define fori(n) for (int i = 0; i < n; ++i)
#define forj(n) for (int j = 0; j < n; ++j)
#define fori1(n) for (int i = 1; i < n; ++i)
#define forj1(n) for (int j = 1; j < n; ++j)
#define pii pair<int, int>
#define pb push_back
#define x first
#define y second

void readln() {}
void readln(auto& a, auto&... b)
{
    cin >> a;
    readln(b...);
}

void writeln() {cout << "\n";}
void writeln(auto a, auto... b)
{
    cout << a << " ";
    writeln(b...);
}

struct point
{
    int x;
    int y;
    int i;

    point(){}

    point(int x, int y, int i) : x(x), y(y), i(i) {}

};


vector<int> order;
int color[100001];

void dfsComp(int v, int c, vector<vector<int>> &g){
    if (color[v] >= 0) {
        return;
    }
    color[v] = c;
    for (int u : g[v]) {
        dfsComp(u, c, g);
    }
}

void dfsOrder(int v, vector<vector<int>> &g){
    if (color[v] != -1) {
        return;
    }
    color[v] = -2;

    for (int u : g[v]) {
        dfsOrder(u, g);
    }

    order.push_back(v);
}

int index(int n, vector<point> &a, point &p, auto cmp) {
    int l = 0, r = n - 1;
    if (!cmp(a[l], p)){
        return -1;
    }

    if (cmp(a[r], p)){
        return r;
    }


    while(r - l > 1) {
        int m = (r + l) /2;
        if (cmp(a[m], p)) {
            l = m;
        } else {
            r = m;
        }
    }

    return l;
}


void fillG(int n, vector<point> &a, vector<vector<int>> &g, auto cmp)
{
   sort(a.begin(), a.end(), cmp);

   for (int r = 0; r < n; r++) {
        int l = index(n, a, a[r], cmp);
        if (0 <= l && l < r) {
              g[a[r].i].push_back(a[l].i);
        }
   }
}


int main()
{
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    int n;
    readln(n);

    vector<point> a;
    fori(n)
    {
        color[i] = -1;
        int x, y;
        cin >> x >> y;
        a.push_back(point(x,y,i));
    }


    vector<vector<int>> g(n);
    vector<vector<int>> h(n);



    auto cmpX = [](point a, point b) {
         return a.x == b.x ? a.y < b.y : a.x < b.x;
    };

    auto cmpY = [](point a, point b) {
         return a.y == b.y ? a.x < b.x : a.y < b.y;
    };

    fillG(n, a, g, cmpX);
    fillG(n, a, g, cmpY);


    for (int i = n - 1; i >= 0; i--) {
        dfsOrder(a[i].i, g);
    }

    for (int v = 0; v < n; v++) {
        for(int u : g[v]) {
            h[u].push_back(v);
        }
    }

    int k = 0;
    for (int i = n - 1; i >= 0; i--) {
        int v = order[i];
        if (color[v] < 0) {
            dfsComp(order[i], k , h);
            ++k;
        }
    }
    vector<int> ans(n);


    vector<vector<int>> comp(k);
    for (int i = 0; i < n; i++) {
        comp[color[i]].push_back(i);
    }

    int s = 0;

    for (int i = k - 1; i >= 0; i--) {
        s += comp[i].size();
        for (int v : comp[i]){
            ans[v] = s - 1;
        }
    }


    for (int i = 0; i < n; i++) {
        cout << (ans[i]) << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second

const int maxn = (1e5) + 100;

bool was1[maxn], was2[maxn];
int ans[maxn];
int d[maxn];
pii a[maxn], b[maxn];
int pos1[maxn], pos2[maxn];

queue <pii> q1, q2;

int main()
{
    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);


    int n;
    cin >> n;
    rep(i, n){
        cin >> a[i].fi >> b[i].fi;
        a[i].se = i;
        b[i].se = i;
    }

    sort(a, a + n);
    sort(b, b + n);

    rep(i, n){
        pos1[a[i].se] = i;
        pos2[b[i].se] = i;
    }

    for (int i = n - 1; i >= 0; i--){
        q2.push(mp(a[i].se, i));
        while (1){
            bool f = 1;
            while (!q2.empty()){
                f = 0;
                pii w = q2.front();
                q2.pop();

                for (int j = pos2[w.fi]; j < n; j++){
                    if (was2[b[j].se])
                        break;
                    was2[b[j].se] = 1;
                    d[b[j].se] = w.se;
                    q1.push(mp(b[j].se, w.se));
                }
            }

            while (!q1.empty()){
                f = 0;
                pii w = q1.front();
                q1.pop();

                for (int j = pos1[w.fi]; j < n; j++){
                    if (was1[a[j].se])
                        break;
                    was1[a[j].se] = 1;
                    d[a[j].se] = w.se;
                    q2.push(mp(a[j].se, w.se));
                }
            }
            if (f)
                break;
        }
    }


    rep(i, n){
        cout << d[i] << endl;
    }

    return 0;
}
/*

7
7 6
6 7
5 5
4 4
3 1
2 2
1 3

4
4 2
2 3
3 1
1 4

4
4 4
2 3
3 2
1 1

3
1 1
2 2
3 3

3
1 3
2 2
3 1

4
2 3
3 2
1 1
4 5

5
1 2
2 3
3 4
4 5
5 1

*/

#include <bits/stdc++.h>

using namespace std;

#define taskname "codecoder"
#define taski taskname".in"
#define tasko taskname".out"

#define inp freopen(taski, "r", stdin)
#define outp freopen(tasko, "w", stdout)

#define mp make_pair
#define fi first
#define se second

const int N = (int)1e5 + 10;
const int M = (int)1e6 + 10;

class segments_tree
{
private:
    int l, r, mx, sz, upd;
    segments_tree *left, *right;
public:
    segments_tree(int l, int r) : l(l), r(r){
        mx = 0;
        sz = 0;
        upd = -1;
        left = right = NULL;
        if (l == r) sz = 1;
        if (l < r){
            left = new segments_tree(l, (l + r) / 2);
            right = new segments_tree((l + r) / 2 + 1, r);
            sz = left->sz + right->sz;
        }
    }

    void push(segments_tree *t){
        if (t == NULL) return ;
        if (upd == -1) return ;
        if (t->sz != 1){
            t->left->upd = max(t->upd, t->left->upd);
            t->right->upd = max(t->upd, t->right->upd);
        }
        t->mx = max(t->mx, t->upd);
        t->upd = -1;
    }

    void modify(int _l, int _r, int d){
        push(this);
        if (_l == l && r == _r){
            upd = d;
            push(this);
        } else {
            if (_l <= left->r){
                left->modify(_l, min(left->r, _r), d);
            }
            if (_r >= right->l){
                right->modify(max(right->l, _l), _r, d);
            }
            push(left);
            push(right);
            mx = max(left->mx, right->mx);
        }
    }

    int get_max(int _l, int _r){
        push(this);
        if (_l == l && r == _r) return mx;
        int res = 0;
        if (_l <= left->r){
            res = max(res, left->get_max(_l, min(left->r, _r)));
        }
        if (_r >= right->l){
            res = max(res, right->get_max(max(right->l, _l), _r));
        }
        return res;
    }

};

segments_tree *pCode;
int up[N], n, ansInSort[N], ans[N], mxp[N];
pair<pair<int, int>, int> p[N];

int main()
{
    inp;outp;
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        p[i]=mp(mp(a,b),i);
    }
    sort(p,p + n);
    pCode = new segments_tree(0, M);

    for (int i = n - 1; i >= 0; --i){
        int x = p[i].first.second;
        pCode->modify(x + 1, M, i);
    }

    for (int i = 0; i < n; ++i){
        int x = p[i].first.second;
        up[i] = max(pCode->get_max(x, x), i);
    }

    for (int i = 0; i < n; ++i){
        mxp[i] = max((i == 0 ? 0 : mxp[i - 1]), p[i].first.second);
    }

    for (int i = n - 1; i >= 0; --i){
        ansInSort[i] = max(i, ansInSort[max(pCode->get_max(mxp[i], mxp[i]), i)]);
    }


    for (int i = 0; i < n; ++i){
        ans[p[i].second] = ansInSort[i];
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << endl;
    return 0;
}

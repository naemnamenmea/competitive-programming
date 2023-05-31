#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin v.end
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int inf = 1e9;
const int N = (int)1e6 + 5;

bool lesss(int a, int b, int c, int x, int y, int z){
    if (a < x){
        return 1;
    }
    if (a > x){
        return 0;
    }
    if (b < y){
        return 1;
    }
    if (b > y){
        return 0;
    }
    return c <= z;
}

struct TNode{
    int a, b, num;
    int y;
    int aa, ab, anum;
    TNode *ls = NULL, *rs = NULL;
    int ans;
    TNode(int _a, int _b, int _num){
        a = aa = _a;
        b = ab = ans = _b;
        num = anum = _num;
        y = rand();
    }
    TNode(){};
};

struct DD{
    int sz = 0;
    TNode *root = NULL;
    int getans(TNode *node){
        if (!node){
            return inf;
        }
        return node -> ans;
    }
    pair <pair <int, int>,  pair <int, int> > getans2(TNode *node)
    {
        if (!node)
        {
            return {{0, 0}, {0, inf}};
        }
        return {{node -> aa, node -> ab}, {node -> anum, node -> ans}};
    }
    void upd(TNode *node){
        if (!node){
            return;
        }
        if (getans(node -> ls) < getans(node -> rs))
        {
            pair <pair <int, int>,  pair <int, int> > t = getans2(node -> ls);
            node -> aa = t.F.F;
            node -> ab = t.F.S;
            node -> anum = t.S.F;
            node -> ans = t.S.S;
        }
        if (getans(node -> ls) >= getans(node -> rs))
        {
            pair <pair <int, int>,  pair <int, int> > t = getans2(node -> rs);
            node -> aa = t.F.F;
            node -> ab = t.F.S;
            node -> anum = t.S.F;
            node -> ans = t.S.S;
        }
        if (node -> b < node -> ans)
        {
            node -> aa = node -> a;
            node -> ab = node -> b;
            node -> anum = node -> num;
            node -> ans = node -> b;
        }
    }
    TNode* merge(TNode *l, TNode *r){
        if (!l){
            return r;
        }
        if (!r){
            return l;
        }
        if ((l -> y) > (r -> y)){
            l -> rs = merge(l -> rs, r);
            upd(l);
            return l;
        } else {
            r -> ls = merge(l, r -> ls);
            upd(r);
            return r;
        }
    }
    pair<TNode*, TNode*> split(TNode *node, int x, int y, int z){
        if (!node){
            return {NULL, NULL};
        }
        if (lesss(node -> a, node -> b, node -> num, x, y, z)){
            pair<TNode*, TNode*> t = split(node -> rs, x, y, z);
            upd(t.first);
            upd(t.second);
            node -> rs = t.first;
            upd(node);
            return {node, t.second};
        } else {
            pair<TNode*, TNode*> t = split(node -> ls, x, y, z);
            upd(t.first);
            upd(t.second);
            node -> ls = t.second;
            upd(node);
            return {t.first, node};
        }
    }
    void ins(int a, int b, int num){
        TNode *t = new TNode(a, b, num);
        pair<TNode*, TNode*> tmp = split(root, a, b, num);
        root = merge(tmp.first, t);
        root = merge(root, tmp.second);
        sz++;
    }
    void del(int a, int b, int num){
        sz--;
        int ta = a, tb = b, tn = num;
        if (tn > 0){
            tn--;
        } else {
            if (tb > 0){
                tb--;
            } else {
                ta--;
            }
        }
        pair<TNode*, TNode*> t = split(root, a, b, num);
        root = t.second;
        t = split(t.first, ta, tb, tn);
        root = merge(t.first, root);
    }
    pair< pair<int, int>, pair<int, int> > getmin(int a){
        pair<TNode*, TNode*> t = split(root, a, inf, inf);
        pair< pair<int, int>, pair<int, int> > ans = getans2(t.second);
        root = merge(t.first, t.second);
        return ans;
    }
    pair<pair<int, int>, int> getf(TNode *node){
        if (!(node -> ls)){
            return {{node -> a, node -> b}, node -> num};
        }
        return getf(node -> ls);
    }
    void print(TNode *node){
        if (!node){
            return;
        }
        print(node -> ls);
        cout << "(" << node -> a << " " << node -> b << " " << node -> num << ") ";
        print(node -> rs);
    }
};

DD X, Y;
vector<ll> cans;
vector<int> comp;
vector<ll> csz;
vector<pair<int, int> > gr;

int main(){
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);
    int n;
    scanf("%d", &n);
    comp.assign(n, -1);
    cans.assign(n, 0);
    csz.assign(n, 0);
    int c = -1;
    for (int i = 0; i < n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        X.ins(x, y, i);
        Y.ins(y, x, i);
    }
    int tx, ty, tn;
    //pair< pair<int, int>, pair<int, int> > tt = X.getans2(X.root);
    //cout << tt.F.F << " " << tt.F.S << " " << tt.S.F << " " << tt.S.S << " zaza\n";
    while (X.sz > 0){
        pair<pair<int, int>, int> tmp = X.getf(X.root);
        tx = tmp.F.F;
        ty = tmp.F.S;
        tn = tmp.S;
        X.del(tx, ty, tn);
        Y.del(ty, tx, tn);
        //cout << X.sz << endl;
        //cout << tx << " " << ty << " " << tn << ":\n";
        c++;
        csz[c]++;
        comp[tn] = c;
        bool f = 1;
        while(f){
            f = 0;
            pair< pair<int, int>, pair<int, int> > t = X.getmin(tx);
            //cout << t.F.F << " " << t.F.S << " " << t.S.F << " " << t.S.S << " zaza\n";
            if (t.S.S < ty){
                f = 1;
                csz[c]++;
                comp[t.S.F] = c;
                tx = t.F.F;
                X.del(t.F.F, t.F.S, t.S.F);
                Y.del(t.F.S, t.F.F, t.S.F);
                continue;
            }
            t = Y.getmin(ty);
            if (t.S.S < tx){
                f = 1;
                csz[c]++;
                comp[t.S.F] = c;
                ty = t.F.F;
                Y.del(t.F.F, t.F.S, t.S.F);
                X.del(t.F.S, t.F.F, t.S.F);
                continue;
            }
        }
        gr.push_back({tx, ty});
    }
    ll ts = 0;
    for (int i = 0; i <= c; i++){
        cans[i] = (csz[i] - 1LL);
        if (i > 0){
            cans[i] += ts * (gr[i] != gr[i - 1]);
        }
        ts += csz[i];
    }
    for (int i = 0; i < n; i++){
        printf("%I64d\n", cans[comp[i]]);
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

// @author: pashka

struct segtree {
    struct node
    {
        long long set;
        long long min;
    }

    long long NO_OPERATION = LLONG_MIN;
    long long NEUTRAL_ELEMENT = 0;

    vector<node> tree;
    int size;

    long long op_modify(long long a, long long b, long long len)
    {
        if (b == NO_OPERATION) return a;
        return b * len;
    }

    long long op_sum(long long a, long long b)
    {
        return a + b;
    }

    void init(int n)
    {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size - 1);
    }

    void propagate(int x, int lx, int rx)
    {
        if(tree[x].set == NO_OPERATION || rx - lx == 1) return;
        int m = (lx + rx) / 2;
        tree[2 * x + 1].set = op_modify(tree[2 * x + 1].set, tree[x].set, 1);
        tree[2 * x + 1].sum = op_modify(tree[2 * x + 1].sum, tree[x].set, m - lx);
        tree[2 * x + 2].set = op_modify(tree[2 * x + 2].set, tree[x].set, 1);
        tree[2 * x + 2].sum = op_modify(tree[2 * x + 2].sum, tree[x].set, rx - m);
        tree[x].set = NO_OPERATION;
    }

    void mult(int l, int r, int v, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if(l >= rx || lx >= r)
            return;

        if(lx >= l && rx <= r)
        {
            tree[x].set = op_modify(tree[x].set, v, 1);
            tree[x].sum = op_modify(tree[x].sum, v, rx - lx);
            return;
        }
        int m = (lx + rx) / 2;
        mult(l, r, v, 2 * x + 1, lx, m);
        mult(l, r, v, 2 * x + 2, m, rx);
        tree[x].sum = op_sum(tree[2 * x + 1].sum, tree[2 * x + 2].sum);
    }

    void mult(int l, int r, int v)
    {
        mult(l, r, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if(l >= rx || lx >= r)
            return NEUTRAL_ELEMENT;

        if(lx >= l && rx <= r)
            return tree[x].sum;
        
        int m = (lx + rx) / 2;
        long long m1 = sum(l, r, 2 * x + 1, lx, m);
        long long m2 = sum(l, r, 2 * x + 2, m, rx);
        return op_sum(m1, m2);
    }

    long long sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }
};

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    for(int t = 0; t < m; ++t)
    {
        int c;
        cin >> c;
        if(c == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            st.mult(l, r, v);
        } else
        {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << endl;
        }
    }

    return 0;
}
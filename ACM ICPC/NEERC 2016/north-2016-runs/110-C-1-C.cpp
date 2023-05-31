#include <bits/stdc++.h>

using namespace std;

#define filename "codecoder"

int a[100001];
int b[100001];
int p[100001];
int q[100001];
int c[100001];
int ct;
int ans[1000001];
bool used[100001];
vector<int> edge[100001];
vector<int> redge[100001];

bool cmp1(int i, int j){
    return a[i] < a[j];
}

bool cmp2(int i, int j){
    return b[i] < b[j];
}

vector<int> top;
void dfs(int u){
    used[u] = true;
    for (auto v: edge[u])
        if (!used[v]) dfs(v);
    top.push_back(u);
}

void rdfs(int u, int cl){
    used[u] = true;
    c[u] = cl;
    for (auto v: redge[u])
        if (!used[v]) rdfs(v, cl);
    ct++;
}

int main(){
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        p[i] = q[i] = i;
    }
    sort(p, p + n, cmp1);
    sort(q, q + n, cmp2);
    for (int i = 1; i < n; i++){
        redge[p[i]].push_back(p[i - 1]);
        edge[p[i - 1]].push_back(p[i]);
        redge[q[i]].push_back(q[i - 1]);
        edge[q[i - 1]].push_back(q[i]);
    }
    for (int i = 0; i < n; i++){
        if (!used[i])
            dfs(i);
    }
    reverse(top.begin(), top.end());
    for (int i = 0; i < n; i++) used[i] = 0;
    ct = 0;
    for (auto v: top){
        if (!used[v]){
            rdfs(v, v);
            ans[v] = ct;
        }
    }
    for (int i = 0; i < n; i++){
        ans[i] = ans[c[i]];
        cout << ans[i] - 1 << "\n";
    }
	return 0;
}

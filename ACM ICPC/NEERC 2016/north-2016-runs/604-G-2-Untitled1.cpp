#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int n,q;
int g[200000];
int p[200000];
int c[200000];
const int INF=10000000;
map<int,set<int>> m;
int mark[200000];

/*void calc(int k){
    if (m[k].size()==0){
        if (mark[k]==1){
            g[k]=1;
        }else{
            g[k]=0;
        }
    }else{
        int res = 0;
        for (auto l: m[k]){
            calc(l);
            res+=g[l];
        }
        g[k]=res;
    }
    return;
}*/

void num(int k){
    if (m[k].size()==0){
        c[k]=1;
    }else{
        int r=1;
        for (auto l: m[k]){
            num(l);
            r+=c[l];
        }
        c[k]=r;
    }
    return;
}

int check(int k){
    for (auto i: m[k]){
        if ((g[i]<g[k])&&(g[i]>0)){
            return(-1);
        }
        if (g[i]==g[k]){
            return(i);
        }
    }
}

pair<int,int> cofnl(int k){
    int res=0;
    int cofp=0;
    if (mark[k]==0){
        for (auto i: m[k]){
            if (g[i]>0){
                cofp++;
                int cur=i;
                int d=check(cur);
                while ((mark[cur]==0)&&(d>0)){
                    cur=d;
                    d=check(cur);
                }
                res+=c[cur]-g[cur];
            }
        }
    }else{
        if (g[k]>0){
            res+=c[k]-g[k]-1;
            for (auto i: m[k]){
                if (g[i]>0){
                    cofp++;
                }
            }
        }
    }
    pair<int,int> t;
    t.first=cofp;
    t.second=res;
    return(t);
}

int main(){
    freopen("gangsters.in","rt",stdin);
    freopen("gangsters.out","wt",stdout);
    for (int i=1;i<=n;i++){
        g[i]=0;
        c[i]=0;
        mark[i]=0;
    }
    cin >> n >> q;
    for (int i=2;i<=n;i++){
        int u;
        cin >> u;
        m[u].insert(i);
        p[i]=u;
    }
    num(1);
    for (int i=1;i<=q;i++){
        int u;
        string s;
        cin >> s >> u;
        if (s[0]=='+'){
            mark[u]=1;
            int cur=u;
            while(cur!=0){
                g[cur]++;
                cur=p[cur];
            }
        }else{
            mark[u]=0;
            int cur=u;
            while(cur!=0){
                g[cur]--;
                cur=p[cur];
            }
        }
        pair<int,int> z;
        z=cofnl(1);
        cout << z.first << ' ' << z.second << endl;
    }

    return 0;
}

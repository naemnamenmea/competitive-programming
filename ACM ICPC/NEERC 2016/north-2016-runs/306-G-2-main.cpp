#include <bits/stdc++.h>

using namespace std;

#define taskname "gangsters"
#define taski taskname".in"
#define tasko taskname".out"
#define pb push_back
#define inp freopen(taski, "r", stdin)
#define outp freopen(tasko, "w", stdout)
#define si size()
#define MP make_pair
#define fi first
#define se second

int n,m,i,j,k,x,y,a,b,p[100010][20],d[100010],pp[100010],ans,cnt,fl;
int tl[100010],tr[100010],num[100010],nm,t[110010],normal[100010],ans2;
vector<int>g[100010];
set<int>st[100010];
pair<int,int> dfs( int v,int pv )
{
    if( p[v][0]==1 )pv=v;
    for( int i=1;i<=19;i++ )
    {
        p[v][i]=p[ p[v][i-1] ][ i-1 ];
    }
    if( g[v].si==0 )
    {
        pp[v]=pv;
        nm++;
        num[v]=nm;
        tl[v]=tr[v]=nm;
        return MP(nm,nm);
    }
    int a=1000000,b=-1;
    pair<int,int>P;
    for( int i=0;i<g[v].si;i++ )
    {
        P=dfs(g[v][i],pv);
        a=min(a,P.fi);
        b=max(b,P.se);
    }
    tl[v]=a;
    tr[v]=b;
    return MP(a,b);
}
char ch;
void update( int idx,int val )
{
    while(idx<=nm)
    {
        t[idx]+=val;
        idx+=(idx&-idx);
    }
}
int take( int idx )
{
    int sm=0;
    while(idx>0)
    {
        sm+=t[idx];
        idx-=(idx&-idx);
    }
    return sm;
}
int solve( int v )
{
    for( int i=19;i>=0;i-- )
    {
        if( p[v][i]==0 )continue;
        int k=p[v][i];
        if( take( tr[k] )-take( tl[k]-1 )>=fl )continue;
        v=k;
    }
//    cout<<"-> "<<v<<endl;
    if( !(take( tr[v] )-take( tl[v]-1 )>=fl) )v=p[v][0];
    return v;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
    inp;outp;
    cin>>n>>m;
    for( i=2;i<=n;i++ )
    {
        cin>>p[i][0];
        g[p[i][0]].pb(i);
    }
    dfs(1,1);
    for( i=0;i<m;i++ )
    {
        cin>>ch>>a;
        if( ch=='+' )
        {
            update(num[a],1);
//        cerr<<i<<endl;
//            cout<<pp[a]<<endl;
            if( d[ pp[a] ]==0 )
            {
                d[ pp[a] ]=1;
                normal[pp[a]]=0;
                st[ pp[a] ].insert(a);
//                cout<<a<<endl;
                ans++;
            }
            else
            {
                st[ pp[a] ].insert(a);
//                cout<<a<<endl;
                fl=take( tr[pp[a]] )-take( tl[pp[a]]-1 );
                k=solve(a);
//                cout<<fl<<endl;
//                cout<<k<<"->"<<endl;
                ans2-=normal[ pp[a] ];
                normal[ pp[a] ]=tr[k]-tl[k]+1-(take( tr[k] )-take( tl[k]-1 ));
                ans2+=normal[ pp[a] ];
            }
        }
        else
        {
            update(num[a],-1);
            st[ pp[a] ].erase(a);
            if( take( tr[pp[a]] )-take( tl[pp[a]]-1 )==0 )
            {
                d[ pp[a] ]=0;
                ans2-=normal[pp[a]];
                normal[pp[a]]=0;
                ans--;
            }
            else
            {
//                cerr<<"HERE\n";
                a=*(st[ pp[a] ].begin());
//                cout<<a<<endl;
                fl=take( tr[pp[a]] )-take( tl[pp[a]]-1 );
//                cout<<fl<<endl;
                k=solve(a);
//                cout<<k<<endl;
                ans2-=normal[ pp[a] ];
                normal[ pp[a] ]=tr[k]-tl[k]+1-(take( tr[k] )-take( tl[k]-1 ));
                ans2+=normal[ pp[a] ];
            }
        }
        cout<<ans<<" "<<ans2<<endl;
    }
    return 0;
}

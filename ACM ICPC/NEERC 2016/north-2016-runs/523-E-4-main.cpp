#define FNAME "easy"

#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);++i)
#define forit(i,V) for(__typeof(V.begin()) i=V.begin();i!=V.end();++i)
#define fornr(i,N) for(int i=int(N)-1;i>=0;--i)
#define forab(i,a,b) for(int i=(a);i<int(b);++i)
#define all(V) (V).begin(),(V).end()
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define sz(V) (int)((V).size())

typedef pair<int,int> pii;
typedef long double LD;
typedef vector<int> vi;

const int MAX_H=1e5+100;
string G[MAX_H];
map<pii, int> Field;
multiset<int> SetX, SetY;
pii Pos[MAX_H];

const int M1=1e9+7, M2=1e9+9;

inline int mod(int a,int m){
	if(a>=m)
		a-=m;
	return a;
}

struct LL{
	int x,y;
	LL():x(0),y(0){}
	LL(int _x,int _y):x(_x),y(_y){}
	LL(int _x):x(_x),y(_x){}
	inline LL operator+(const LL &B) const{
		return LL(mod(x+B.x, M1), mod(y+B.y, M2));
	}
	inline LL operator*(const int k) const{
		return LL(x*1ll*k%M1, y*1ll*k%M2);
	}
	inline LL operator*(const LL &B) const{
		return LL(x*1ll*B.x%M1, y*1ll*B.y%M2);
	}
	inline bool operator==(const LL &B) const{
		return x==B.x && y==B.y;
	}
	inline void operator+=(const LL &B){
		*this=*this+B;
	}
	inline void operator-=(const LL &B){
		x=mod(x+M1-B.x, M1);
		y=mod(y+M2-B.y, M2);
	}
};

const char dirs[]="udlr";
string S;
const int P=239017, Q=17239;
LL DegP[MAX_H], DegQ[MAX_H];
const int INF=1e9;
const int MOVE[][2]={{0,-1},{0,1},{-1,0},{1,0}};
int cnt[4];


int main(){
	assert(freopen(FNAME".in","r",stdin));
	assert(freopen(FNAME".out","w",stdout));
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int L,H,W;
	cin >> L;
	getline(cin, S);
	getline(cin, S);
	cin >> H >> W;
	
	DegP[0]=DegQ[0]=1;
	forn(i,MAX_H-1){
		DegP[i+1]=DegP[i]*P;
		DegQ[i+1]=DegQ[i]*Q;
	}
		
	int NeedSq=0, mx=INF, my=INF;
	forn(i,H){
		cin>>G[i];
		forn(j,W){
			if(G[i][j]=='X'){
				++NeedSq;
				my=min(my,i);
				mx=min(mx,j);
			}
		}
	}
	if(NeedSq==1){
		puts("YES");
		assert(0);
		return 0;
	}
	
	LL Hash=0;
	if(mx!=INF){
		for(int i=my;i<H;++i)
			for(int j=mx;j<W;++j)
				Hash+=DegP[j-mx]*DegQ[i-my]*(G[i][j]=='X');
	}
//	printf("%lld\n",Hash);
	
	vector<pii> v;
	forn(i,L){
		char* t=strchr(dirs,S[i]);
		if(t){
			int k=t-dirs;
			++cnt[k];
			v.pb(mp(k,i));
		}
	}
	int curx=cnt[2], cury=cnt[0], Sq=1;
	++Field[mp(curx,cury)];
	SetX.insert(curx), SetY.insert(cury);
	Pos[0]=mp(curx,cury);
	LL curhash = DegP[curx]*DegQ[cury];
	
	int lt=0;
	forn(i,sz(v)){
			int k=v[i].fst;
			curx+=MOVE[k][0], cury+=MOVE[k][1];
			int &f=Field[mp(curx,cury)];
			++f;
			if(f==1){
				++Sq;
				curhash+=DegP[curx]*DegQ[cury];
				SetX.insert(curx), SetY.insert(cury);
//				printf("add new cell %d %d\n",curx,cury);
//				printf("%lld\n",curhash);
			}
			Pos[i+1]=mp(curx,cury);
			
			while(Sq==NeedSq){
//				printf("%d %d\n",*SetX.begin(),*SetY.begin());
//				printf("%lld %lld\n",Hash*DegP[*SetX.begin()]*DegQ[*SetY.begin()],curhash);
				if(Hash*DegP[*SetX.begin()]*DegQ[*SetY.begin()]==curhash){
//					puts("YES");
					printf("YES\n%d %d\n",v[lt].snd+1,v[i].snd+1);
					return 0;
				}
				pii p=Pos[lt];
				++lt;

				int &fl=Field[mp(p.fst,p.snd)];
//				printf("see cell %d %d\n",p.fst,p.snd);
				assert(fl>0);
				--fl;
				if(!fl){
					SetX.erase(SetX.find(p.fst)), SetY.erase(SetY.find(p.snd)), --Sq;
					curhash-=DegP[p.fst]*DegQ[p.snd];
				}
			}
	}
	puts("NO");
	
	return 0;
}
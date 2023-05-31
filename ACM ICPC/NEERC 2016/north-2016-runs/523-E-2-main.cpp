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

typedef unsigned long long LL;
typedef pair<int,int> pii;
typedef long double LD;
typedef vector<int> vi;

const int MAX_H=1e5+100;
string G[MAX_H];
map<pii, int> Field;
multiset<int> SetX, SetY;
pii Pos[MAX_H];

const char dirs[]="udlr";
string S;
const int P=1e9+7, Q=1e9+9;
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
		return 0;
	}
	
	LL Hash=0;
	if(mx!=INF){
		for(int i=my;i<H;++i)
			for(int j=mx;j<W;++j)
				Hash+=(G[i][j]=='X')*DegP[j-mx]*DegQ[i-my];
	}
//	printf("%lld\n",Hash);
	
	vi v;
	forn(i,L){
		char* t=strchr(dirs,S[i]);
		if(t){
			int k=t-dirs;
			++cnt[k];
		}
	}
	int curx=cnt[2], cury=cnt[0], Sq=1;
	++Field[mp(curx,cury)];
	SetX.insert(curx), SetY.insert(cury);
	Pos[0]=mp(curx,cury);
	bool flag = 0,flag2=0;
	LL curhash = DegP[curx]*DegQ[cury];
	
//	printf("start at %d %d\n",curx,cury);
	int lt=0;
	forn(i,L){
		char* t=strchr(dirs,S[i]);
		if(t){
			int k=t-dirs;
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
					if (flag && !flag2) {
						printf("YES\n%d %d\n",lt+2,i+1);
					} else {
						printf("YES\n%d %d\n",lt+1,i+1);					
					}
					return 0;
				}
				
				pii p;
				if(flag){
					if(flag2)
						lt++;
					while(lt<=i && !strchr(dirs, S[lt]))
						++lt;
					if(lt>i)
						break;
					p=Pos[lt+1];
//					printf("lt+1=%d\n",lt+1);
					flag2=1;
				}else{
//					printf("lt=%d\n",lt);
					p=Pos[lt], flag=1;
				}
					
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
	}
	puts("NO");
	
	return 0;
}
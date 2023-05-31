#define FNAME "digital"

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

typedef long long LL;
typedef pair<int,int> pii;
typedef long double LD;
typedef vector<int> vi;

const int MAX_N=1000, CNT=7;

const int DIGITS[10][CNT]={
{1,0,1,1,1,1,1},
{0,0,0,0,0,1,1},
{1,1,1,0,1,1,0},
{1,1,1,0,0,1,1},
{0,1,0,1,0,1,1},
{1,1,1,1,0,0,1},
{1,1,1,1,1,0,1},
{1,0,0,0,0,1,1},
{1,1,1,1,1,1,1},
{1,1,1,1,0,1,1}
};

struct t{
	int a,b,c,mask;
	bool carry;
	t(){a=0, b=0, c=0, mask=0, carry=0;}
	t(int _a,int _b,int _c,int _mask,bool _carry){
		a=_a, b=_b, c=_c, mask=_mask, carry=_carry;
	}
};

const int MAX_MASK=(1<<4)+2;
bool D[MAX_N][MAX_MASK][2];
t P[MAX_N][MAX_MASK][2];
bool tmp[10][10];
bool Z[10][MAX_N];
int ans[3][MAX_N];

void print(int k,int x){
	for(int i=0;i<=2;++i)
		tmp[2*(k+i)][0]|=DIGITS[x][i];
	for(int i=0;i<=1;++i){
		tmp[2*(k+i)+1][0]|=DIGITS[x][3+i];
		tmp[2*(k+i)+1][1]|=DIGITS[x][5+i];
	}
}

inline void clear(int mask){
	forn(i,9)
		forn(j,1+(i%2))
			tmp[i][j]=0;
	forn(i,4)
		tmp[2*i+1][1]=(mask>>i)&1;
}

int check(int a,int b,int c,int col,int mask){
	clear(mask);
	print(0, a);
	print(1, b);
	print(2, c);
	forn(i,9)
		forn(j,1+(i%2))
			if(i%2==1 && j==0){
				if(tmp[i][j] && !Z[i][j+col])
					return -1;
			}else{
				if(tmp[i][j]!=Z[i][j+col])
					return -1;
			}
	int newmask=0;
/*	if(col==0 && a==8 && b==0 && c==9){
		forn(i,9){
		forn(j,1+(i%2))
		printf("%d ",tmp[i][j]);
		puts("");
		}
	}*/
	
	forn(i,4)
		newmask|=(tmp[2*i+1][0]<<i);
	return newmask;
}


int main(){
	assert(freopen(FNAME".in","r",stdin));
	assert(freopen(FNAME".out","w",stdout));
	
	int N;
	scanf("%d",&N);
	forn(i,9){
		int l=N+(i%2);
		forn(j,l)
			scanf("%d",&Z[i][j]);
	}
	
	D[N][0][0]=1;
	for(int i=N;i>0;--i)
		for(int mask=0;mask<(1<<4);++mask)
			forn(carry,2){
				if(!D[i][mask][carry])
					continue;
				forn(a,10)
					forn(b,10){
						int c=(a+b+carry)%10;
						int newmask=check(a,b,c,i-1,mask);
						if(newmask!=-1){
							bool newcarry=(a+b+carry>=10);
							
/*							if(i==1 && a==8 && b==0){
								printf("%d %d %d: %d %d\n",i,a,b,newmask,newcarry);
							}*/
						
							D[i-1][newmask][newcarry]=1;
							P[i-1][newmask][newcarry]=t(a,b,c,mask,carry);
						}
					}
			}
//	printf("!!!%d\n",D[1][2][1]);
	int mask=0, carry=0;
	forn(i,4)
		mask|=(Z[2*i+1][0]<<i);
	if(D[0][mask][carry]){
		forn(i,N){
			auto &qq=P[i][mask][carry];
			ans[0][i]=qq.a;
			ans[1][i]=qq.b;
			ans[2][i]=qq.c;
			mask=qq.mask, carry=qq.carry;
		}
		assert(!carry && !mask);
		forn(j,3){
			forn(i,N)
				printf("%d",ans[j][i]);
			puts("");
		}
		
	}else
		puts("NO");
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main() {
    int w;
    cin >> w;
    int l=(w+1)+w+1;
    bool tmpl[10][7];
    bool N[3][10];
    char **A = new char* [w];
    char **B = new char* [w];
    char **C = new char* [w];
    char *p = new char [w]; //храним перенос 0/1 для вычисления i-ого разряда числа C
    char *input = new char [l];
    
    for(int i=0; i<w; i++) {
        A[i] = new char [13];
        B[i] = new char [13];
        C[i] = new char [13];
        //*[i][10] - кол-во возможных цифр в i-ом разряде числа
        //*[i][11] - текущий индекс цифры в i-ом разрядре числа
        //*[i][12] - запись истории
        for(int j=0; j<12; j++) {
            A[i][j]=0;
            B[i][j]=0;
            C[i][j]=0;
        }
        p[i]=0;
    }
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<10; j++) {
            N[i][j]=0;
        }
    }
    
    tmpl[0][0]=1;
    tmpl[0][1]=1;
    tmpl[0][2]=1;
    tmpl[0][3]=0;
    tmpl[0][4]=1;
    tmpl[0][5]=1;
    tmpl[0][6]=1;
    
    tmpl[1][0]=0;
    tmpl[1][1]=0;
    tmpl[1][2]=1;
    tmpl[1][3]=0;
    tmpl[1][4]=0;
    tmpl[1][5]=1;
    tmpl[1][6]=0;
    
    tmpl[2][0]=1;
    tmpl[2][1]=0;
    tmpl[2][2]=1;
    tmpl[2][3]=1;
    tmpl[2][4]=1;
    tmpl[2][5]=0;
    tmpl[2][6]=1;
    
    tmpl[3][0]=1;
    tmpl[3][1]=0;
    tmpl[3][2]=1;
    tmpl[3][3]=1;
    tmpl[3][4]=0;
    tmpl[3][5]=1;
    tmpl[3][6]=1;
    
    tmpl[4][0]=0;
    tmpl[4][1]=1;
    tmpl[4][2]=1;
    tmpl[4][3]=1;
    tmpl[4][4]=0;
    tmpl[4][5]=1;
    tmpl[4][6]=0;
    
    tmpl[5][0]=1;
    tmpl[5][1]=1;
    tmpl[5][2]=0;
    tmpl[5][3]=1;
    tmpl[5][4]=0;
    tmpl[5][5]=1;
    tmpl[5][6]=1;
    
    tmpl[6][0]=1;
    tmpl[6][1]=1;
    tmpl[6][2]=0;
    tmpl[6][3]=1;
    tmpl[6][4]=1;
    tmpl[6][5]=1;
    tmpl[6][6]=1;
    
    tmpl[7][0]=1;
    tmpl[7][1]=0;
    tmpl[7][2]=1;
    tmpl[7][3]=0;
    tmpl[7][4]=0;
    tmpl[7][5]=1;
    tmpl[7][6]=0;
    
    tmpl[8][0]=1;
    tmpl[8][1]=1;
    tmpl[8][2]=1;
    tmpl[8][3]=1;
    tmpl[8][4]=1;
    tmpl[8][5]=1;
    tmpl[8][6]=1;
    
    tmpl[9][0]=1;
    tmpl[9][1]=1;
    tmpl[9][2]=1;
    tmpl[9][3]=1;
    tmpl[9][4]=0;
    tmpl[9][5]=1;
    tmpl[9][6]=1;
    
    gets(input);
    for(int i=0; i<9; i++) {
        gets(input);
        if(i%2==0) {
            for(int j=0; j<w; j++) {
                if(input[l-j*2-3]=='1') {
                    if(i<5) A[j][int(i*1.5)]=1;
                    if(i>1&&i<7) B[j][int((i-2)*1.5)]=1;
                    if(i>3) C[j][int((i-4)*1.5)]=1;
                }
            }
        }
        else {
            for(int j=0; j<w; j++) {
                if(input[l-j*2-4]=='1') {
                    if(i<5) A[j][int(i*1.5-0.5)]=1;
                    if(i>1&&i<7) B[j][int((i-2)*1.5-0.5)]=1;
                    if(i>3) C[j][int((i-4)*1.5-0.5)]=1;
                }
                if(input[l-j*2-2]=='1') {
                    if(i<5) A[j][int(i*1.5+0.5)]=1;
                    if(i>1&&i<7) B[j][int((i-2)*1.5+0.5)]=1;
                    if(i>3) C[j][int((i-4)*1.5+0.5)]=1;
                }
            }
        }
    }
    
    for(int i=0; i<w; i++) {
        for(int j=0; j<10; j++) {
            int tA=0;
            int tB=0;
            int tC=0;
            for(int g=0; g<7; g++) {
                if(!tmpl[j][g]||A[i][g]) tA++;
                if(!tmpl[j][g]||B[i][g]) tB++;
                if(!tmpl[j][g]||C[i][g]) tC++;
            }
            if(tA==7) N[0][j]=1;
            if(tB==7) N[1][j]=1;
            if(tC==7) N[2][j]=1;
        }
        for(int j=0; j<10; j++) {
            if(N[0][j]) {
                A[i][A[i][10]]=j;
                A[i][10]++;
                N[0][j]=0;
            }
            if(N[1][j]) {
                B[i][B[i][10]]=j;
                B[i][10]++;
                N[1][j]=0;
            }
            if(N[2][j]) {
                C[i][C[i][10]]=j;
                C[i][10]++;
                N[2][j]=0;
            }
        }
		if(A[i][10]==0||B[i][10]==0||C[i][10]==0) {
			cout << "NO\n";
			goto end;
		}
    }
    
    char tmp;
	int shift=0;
	check:
    for(int i=shift; i<w; i++) {
        for(int a=A[i][11]; a<A[i][10]; a++) {
            for(int b=B[i][11]; b<B[i][10]; b++) {
                for(int c=C[i][11]; c<C[i][10]; c++) {
					tmp= A[i][a]+B[i][b]+p[i];
					if(tmp==C[i][c] || (tmp==C[i][c]+10&&i!=w-1)) {
						A[i][12]=A[i][a];
						B[i][12]=B[i][b];
						C[i][12]=C[i][c];
						if(i!=w-1) {
							if(tmp>=10) p[i+1]=1;
							A[i][11]=a;
							B[i][11]=b;
							C[i][11]=c+1;
							shift++;
							goto check;
						}
						else {
							for(int v=w-1; v>=0; v--) cout << (int)A[v][12];
							cout << endl;
							for(int v=w-1; v>=0; v--) cout << (int)B[v][12];
							cout << endl;
							for(int v=w-1; v>=0; v--) cout << (int)C[v][12];
							cout << endl;
							goto end;
						}
					}
					else if(a==A[i][10]-1&&b==B[i][10]-1&&c==C[i][10]-1) {
						if(i!=0) {
							p[i]=0;
							A[i][11]=0;
							B[i][11]=0;
							C[i][11]=0;
							shift--;
							goto check;
						}
						else {
							cout << "NO\n";
							goto end;
						}
					}
                }
				C[i][11]=0;
            }
			B[i][11]=0;
        }
    }
    end:
    
    delete[]input; input=NULL;
    delete[]p; p=NULL;
    for(int i=0; i<w; i++) {
        delete[]A[i]; A[i]=NULL;
        delete[]B[i]; B[i]=NULL;
        delete[]C[i]; C[i]=NULL;
    }
    delete[]A; A=NULL;
    delete[]B; B=NULL;
    delete[]C; C=NULL;
    return 0;
}
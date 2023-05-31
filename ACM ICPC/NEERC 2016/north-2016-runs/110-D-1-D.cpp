#include <bits/stdc++.h>

using namespace std;

#define filename "digital"

bool c[9][105];
bool x[13], z[13];
bool dig[10][5][2];
vector<int> v[(1 << 13)];
bool d[10][7];

void hard(){
    dig[0][0][0] = 1;
    dig[0][1][0] = 1;
    dig[0][1][1] = 1;
    dig[0][2][0] = 0;
    dig[0][3][0] = 1;
    dig[0][3][1] = 1;
    dig[0][4][0] = 1;

    dig[1][0][0] = 0;
    dig[1][1][0] = 0;
    dig[1][1][1] = 1;
    dig[1][2][0] = 0;
    dig[1][3][0] = 0;
    dig[1][3][1] = 1;
    dig[1][4][0] = 0;

    dig[2][0][0] = 1;
    dig[2][1][0] = 0;
    dig[2][1][1] = 1;
    dig[2][2][0] = 1;
    dig[2][3][0] = 1;
    dig[2][3][1] = 0;
    dig[2][4][0] = 1;

    dig[3][0][0] = 1;
    dig[3][1][0] = 0;
    dig[3][1][1] = 1;
    dig[3][2][0] = 1;
    dig[3][3][0] = 0;
    dig[3][3][1] = 1;
    dig[3][4][0] = 1;

    dig[4][0][0] = 0;
    dig[4][1][0] = 1;
    dig[4][1][1] = 1;
    dig[4][2][0] = 1;
    dig[4][3][0] = 0;
    dig[4][3][1] = 1;
    dig[4][4][0] = 0;

    dig[5][0][0] = 1;
    dig[5][1][0] = 1;
    dig[5][1][1] = 0;
    dig[5][2][0] = 1;
    dig[5][3][0] = 0;
    dig[5][3][1] = 1;
    dig[5][4][0] = 1;

    dig[6][0][0] = 1;
    dig[6][1][0] = 1;
    dig[6][1][1] = 0;
    dig[6][2][0] = 1;
    dig[6][3][0] = 1;
    dig[6][3][1] = 1;
    dig[6][4][0] = 1;

    dig[7][0][0] = 1;
    dig[7][1][0] = 0;
    dig[7][1][1] = 1;
    dig[7][2][0] = 0;
    dig[7][3][0] = 0;
    dig[7][3][1] = 1;
    dig[7][4][0] = 0;

    dig[8][0][0] = 1;
    dig[8][1][0] = 1;
    dig[8][1][1] = 1;
    dig[8][2][0] = 1;
    dig[8][3][0] = 1;
    dig[8][3][1] = 1;
    dig[8][4][0] = 1;

    dig[9][0][0] = 1;
    dig[9][1][0] = 1;
    dig[9][1][1] = 1;
    dig[9][2][0] = 1;
    dig[9][3][0] = 0;
    dig[9][3][1] = 1;
    dig[9][4][0] = 1;
}

bool y[13];
int sup[5] = {0, 3, 6, 9, 12};
bool dp[105][1005];
int par[105][1005];

int main()
{
    hard();
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
    int w;
    cin >> w;
    for (int a = 0; a < 10; a++)
        for (int i = 0, pos = 0; i < 5; i++)
            for (int j = 0; j < 1 + (i & 1); j++)
                d[a][pos++] = dig[a][i][j];
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 2 + (i & 1); j++)
            cin >> c[i][j];
    }
    for (int i = 0; i < 9; i++)
        reverse(c[i], c[i] + w + (i & 1));
    /*for (int i = 0; i < 9; i++, cout << endl)
        for (int j = 0; j < 2 + (i & 1); j++)
            cout << c[i][j] << " ";*/
    for (int l = 0; l < w; l++){
        for (int i = 0, pos = 0; i < 9; i++)
            for (int j = (i & 1); j >= 0; j--)
                x[pos++] = c[i][j + l];
        for (int i = 0; i < 1000; i++)
            if ((l == 0 && i == 0) || (l != 0 && dp[l - 1][i])){
                int f = i / 100, s = (i / 10) % 10, sum = i % 10;
                for (int i = 0; i < 7; i++)
                    z[i] = d[f][i];
                for (int i = 0; i < 7; i++)
                    z[i + 3] |= d[s][i];
                for (int i = 0; i < 7; i++)
                    z[i + 6] |= d[sum][i];

                bool bb = f + s > 9;
                for (int j = 0; j < 1000; j++){
                    int f = j / 100, s = (j / 10) % 10, sum = j % 10;
                    if ((f + s + bb) % 10 != sum)
                        continue;
                    for (int i = 0; i < 13; i++)
                        y[i] = 0;
                    for (int i = 0; i < 7; i++){
                        y[i] = d[f][i];
                    }
                    for (int i = 0; i < 7; i++)
                        y[i + 3] |= d[s][i];
                    //if (j == 337)
                    //    cout << y[4] << endl;
                    for (int i = 0; i < 7; i++)
                        y[i + 6] |= d[sum][i];
                    y[2] |= z[1];
                    y[5] |= z[4];
                    y[8] |= z[7];
                    y[11] |= z[10];
                    bool bad = false;
                    for (int i = 0; i < 13; i++)
                        if ((l == w - 1 || (i != 1 && i != 4 && i != 7 && i != 10)) && x[i] != y[i]){
                            //if (l == 1 && j == 337)
                            //    cout << i << " " << x[i] << " " << y[i] << endl;
                            bad = true;
                            break;
                        }
                    //cout << i << " " << j << " " << bad << endl;
                    if (!bad){
                        dp[l][j] = 1;
                        par[l][j] = i;
                    }
                }
            }
    }
    int res = -1;
    /*for (int i = 0; i < 1000; i++)
        if (dp[0][i])
            cout << i << endl;*/
    for (int i = 0; i < 1000; i++)
        if (dp[w - 1][i] && (i / 100) + ((i / 10) % 10) < 10)
            res = i;
            //cout << i << endl;
    if (res == -1){
        cout << "NO";
    }
    vector<int> a1, a2, a3;
    int p = w - 1;
    while (p != -1){
        a1.push_back(res / 100);
        a2.push_back((res / 10) % 10);
        a3.push_back(res % 10);
        res = par[p][res];
        p--;
    }
    for (int i = 0; i < a1.size(); i++)
        cout << a1[i];
    cout << endl;
    for (int i = 0; i < a1.size(); i++)
        cout << a2[i];
    cout << endl;
    for (int i = 0; i < a1.size(); i++)
        cout << a3[i];
    //cout << dp[w-1][]
    return 0;
}

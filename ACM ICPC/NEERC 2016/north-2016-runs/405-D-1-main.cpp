#include <bits/stdc++.h>

using namespace std;
                   
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

string mas[9];
int w;
int dp[333][1 << 4][2];
int masks[333];
pii go[333][1 << 4][2];
string digits[10][5];
int ml[10], mr[10];

void init () {        
	digits[0][0] = "010";
	digits[0][1] = "101";
	digits[0][2] = "000";
	digits[0][3] = "101";
	digits[0][4] = "010";

	digits[1][0] = "000";
	digits[1][1] = "001";
	digits[1][2] = "000";
	digits[1][3] = "001";
	digits[1][4] = "000";

	digits[2][0] = "010";
	digits[2][1] = "001";
	digits[2][2] = "010";
	digits[2][3] = "100";
	digits[2][4] = "010";

	digits[3][0] = "010";
	digits[3][1] = "001";
	digits[3][2] = "010";
	digits[3][3] = "001";
	digits[3][4] = "010";

	digits[4][0] = "000";
	digits[4][1] = "101";
	digits[4][2] = "010";
	digits[4][3] = "001";
	digits[4][4] = "000";

	digits[5][0] = "010";
	digits[5][1] = "100";
	digits[5][2] = "010";
	digits[5][3] = "001";
	digits[5][4] = "010";

	digits[6][0] = "010";
	digits[6][1] = "100";
	digits[6][2] = "010";
	digits[6][3] = "101";
	digits[6][4] = "010";

	digits[7][0] = "010";
	digits[7][1] = "001";
	digits[7][2] = "000";
	digits[7][3] = "001";
	digits[7][4] = "000";

	digits[8][0] = "010";
	digits[8][1] = "101";
	digits[8][2] = "010";
	digits[8][3] = "101";
	digits[8][4] = "010";

	digits[9][0] = "010";
	digits[9][1] = "101";
	digits[9][2] = "010";
	digits[9][3] = "001";
	digits[9][4] = "010";
             
	ml[0] = 3;
	mr[0] = 3;

	ml[1] = 0;
	mr[1] = 3;

	ml[2] = 2;
	mr[2] = 1;

	ml[3] = 0;
	mr[3] = 3;

	ml[4] = 1;
	mr[4] = 3;

	ml[5] = 1;
	mr[5] = 2;

	ml[6] = 3;
	mr[6] = 2;

	ml[7] = 0;
	mr[7] = 3;

	ml[8] = 3;
	mr[8] = 3;

	ml[9] = 1;
	mr[9] = 3;
}

bool comp (int d, int si, int sj) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (digits[d][i][j] == '1') {
				if (mas[si + i][sj + j] != '1') return false;
			}
		}
	}
	return true;
}

char was[9];

bool check (int a, int b, int c, int pos) {
	for (int i = 0; i < 9; i++)
		was[i] = 0;          
	for (int i = 0; i < 3; i++) {
		if (digits[a][i * 2][1] == '1') was[i * 2] = 1;
	}

	for (int i = 0; i < 3; i++) {
		if (digits[b][i * 2][1] == '1') was[2 * (i + 1)] = 1;
	}

	for (int i = 0; i < 3; i++) {
		if (digits[c][i * 2][1] == '1') was[2 * (i + 2)] = 1;
	}

	for (int i = 0; i < 9; i++) {
		if (mas[i][pos] == '1' && !was[i]) return false;
	}
	return true;
}

int get (int pos, int mask, int add) { 
	if (pos < 0) {
		if (add) return 0;
		if (mask != masks[0])
			return 0;
		return 1;
	}
	auto &res = dp[pos][mask][add];
	auto &tmp = go[pos][mask][add];
	if (-1 != res) return res;
	res = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int val = i + j + add;
			int nxt = val / 10;
			val %= 10;
			if (!comp (i, 0, pos) || !comp (j, 2, pos) || !comp (val, 4, pos)) continue;
			if (!check (i, j, val, pos + 1)) continue;
			int rmsk = mr[i] | (mr[j] << 1) | (mr[val] << 2) | mask;
			if ((masks[pos + 2] & rmsk) != masks[pos + 2]) continue;
			int lmsk = ml[i] | (ml[j] << 1) | (ml[val] << 2);
			if (get (pos - 2, lmsk, nxt)) {
				tmp = mp (i, j);
				return res = 1;
			}
		}
	}
	return res;
}

deque<int> ANS[3];

void rec (int pos, int mask, int add) {
	if (pos < 0) return;
	auto tmp = go[pos][mask][add];
	int a = tmp.first;
	int b = tmp.second;
	int c = a + b + add;
	add = c / 10;
	c %= 10;              
	ANS[0].push_front (a);
	ANS[1].push_front (b);
	ANS[2].push_front (c);
	int lmsk = ml[a] | (ml[b] << 1) | (ml[c] << 2);
	rec (pos - 2, lmsk, add); 
}

int main () {                   
	freopen ("digital.in", "r", stdin);
	freopen ("digital.out", "w", stdout);

	init ();
	memset (dp, 0xff, sizeof (dp));

	cin >> w;

	for (int i = 0; i < 9; i++) {
		mas[i] = string (w + w + 1, '0');
		for (int j = 1 - (i & 1), a; j < (int) mas[i].size (); j += 2) {
	    	cin >> a;
	    	mas[i][j] = a + '0';
		} 
	}                                                                 

	/*for (int i = 0; i < 9; i++) {
		cout << mas[i] << endl;
	}  */

	for (int i = 0; i < (int) mas[0].size (); i += 2) {
		for (int j = 0; j < 4; j++) {
			int val = mas[j * 2 + 1][i] - '0';
			masks[i] |= val << j;		
		}
	}

	if (!get ((int) mas[0].size () - 3, 0, 0)) {
		cout << "NO" << endl;
		return 0; 
	}

	rec ((int) mas[0].size () - 3, 0, 0);

	for (int i = 0; i < 3; i++) {
		for (auto it : ANS[i]) {
			cout << it;
		}
		cout << endl;
	}

	return 0;
}
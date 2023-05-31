#include <bits/stdc++.h>

using namespace std;

#define TASK "boysgirls"
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define mp make_pair
#define fr first
#define sc second
const int N = 1e5 + 10;

int n, x, y;
vector<int> answer;

void read() {
    cin >> n >> x >> y;
}

// x 0 
// y 1
pair<int, int> calc(const vector<int> & b) {
    int c0 = 0;
    int c1 = 0;
    assert((int)b.size() == n);
    for (int i = 0; i < (int)b.size(); i++) {
        int next = b[(i + 1) % b.size()];
        int prev = b[(i - 1 + b.size()) % b.size()];
        c0 += next == 0 || prev == 0;
        c1 += next == 1 || prev == 1;
    }
    return mp(c1, c0);
}
int stupid();

int solve() {
    if (n <= 4) {
        return stupid();
    }
    bool revFlag = 0;
    if (x < y) {
        swap(x, y);
        revFlag = 1;
    }

    if (x + y < n) return 0;
    if ((x + y - n) % 2 != 0) return 0;

    answer.assign(n, 1);

    if (x == n) {
        assert(y % 2 == 0);
        int need = y / 2;
        for (int i = 0; i < n; i++) {
            if (need > 0 && (i % 4 == 0 || i % 4 == 1)) {
                answer[i] = 0;
                need--;
            }
        }
    }
    else {
        if (x + y == n) {
            int need = y;
            for (int i = 0; i < n; i += 2) {
                if (need > 0) {
                    answer[i] = 0;
                    need--;
                }
            }
            //for (int i = 0; i < n; i++)
                //cerr << answer[i] << " ";
            //cerr << endl;
        }
        else if (x + y == n + 2) {
            int need = y - 1;
            for (int i = 0; i < n; i += 2) {
                if (need > 0) {
                    answer[i] = 0;
                    need--;
                }
            }
            //for (int i = 0; i < n; i++)
                //cerr << answer[i] << " ";
            //cerr << endl;
        }
        else {
            int cc = n - x;
            if (cc + 2 > (int)answer.size())
                return 0;
            for (int i = 0; i < cc + 2; i++) {
                answer[i] = 0;
            }
            int hasY = cc + 4;
            int needY = (y - hasY) / 2;
            int cur = 0;
            for (int i = cc + 2; i < n; i++) {
                if ((cur % 4 == 2 || cur % 4 == 3) && needY > 0) {
                    needY--; 
                    answer[i] = 0;
                } 
                cur++;
            }
        }
    }
    auto res = calc(answer);
    //db2(res.fr, res.sc);
    //db2(x, y);
    if (res.fr != x || res.sc != y)
        return 0;


    if (revFlag) {
        for (int i = 0; i < n; i++)
            answer[i] ^= 1;
    }
    return 1;
}

int stupid() {
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> tmp(n);
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                tmp[i] = 1;
        auto res = calc(tmp);
        if (res.fr == x && res.sc == y) {
            answer = tmp;
            return 1;
        }
    }
    return 0;
}

void printAns(int res) {
    if (res == 0) {
        puts("Impossible");
    }
    else {
        for (int i = 0; i < n; i++)
            if (answer[i] == 1)
                printf("B");
            else
                printf("G");
        puts("");
    }
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        int T = 14;
        n = rand() % T + 2;
        x = rand() % n + 1;
        y = rand() % n + 1;
        cerr << "n x y: " << n << " " << x << " " << y << endl;
        auto r1 = solve();
        auto r2 = stupid();
        db2(r1, r2);
        assert(r1 == r2);
    }
}


int main() {
#ifdef home
    freopen("in", "r", stdin);
#else
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    if (1) {
        read();
        printAns(solve());
        //printAns(stupid());
    }
    else {
        stress();
    }

    return 0;
}


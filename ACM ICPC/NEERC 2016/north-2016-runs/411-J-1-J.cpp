#define FNAME "java2016"

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (n); i++)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin() v.end()

using namespace std;

typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;

int cnt[300];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n == 0) {
        puts("?/?/?");
        return 0;
    }    
    //1024 / 64
    printf("a=? max ?\n");
    forab(i, 1, 10) {
        printf("%c=%c max %c\n", i + 'a', i - 1 + 'a', i - 1 + 'a');
    }
    
    char ONE = 'a' + 10;
    printf("%c=%c/%c\n", ONE, 'a' + 9, 'a' + 5);
    printf("%c=%c+%c\n", ONE + 1, ONE, ONE);
    forab(i, 2, 8) {
        int x = i / 2, y = (i + 1) / 2;
        printf("%c=%c*%c\n", ONE + i, ONE + x, ONE + y);
    }
    vi pows;
    forn(i, 8)
        if (n &(1<<i))
            pows.pb(i); 
    forn(i, (int) pows.size() - 1)
        printf("%c+", pows[i] + ONE);
    printf("%c\n", pows.back() + ONE);
    return 0;
}
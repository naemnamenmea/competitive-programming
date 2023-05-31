#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("folding.in","r",stdin);
    freopen("folding.out","w",stdout);
    long w, h, a, b, s1, s2, i;
    cin >> w >> h >> a >> b;
    if (((a > w )&& (a > h))|| ((b> w) &&(b > h))) cout << -1;
    else{
    long k = 0;
    for(i = 1; i < (double)w / a; i *= 2){k++;}
    s1 = k; k = 0;
    for(i = 1; i < (double)h / b; i *= 2){k++;}
    s1 = s1 + k; k = 0;
    for(i = 1; i < (double)w / b; i *= 2){k++;}
    s2 = k; k = 0;
    for(i = 1; i < (double)h / a; i *= 2){k++;}
    s2 = s2 + k;
    if (s1 < s2){ cout << s1;}
    else {cout<< s2;}}
    return 0;
}

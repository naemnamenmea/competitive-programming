#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("codecoder.in" , "r", stdin);
    freopen("codecoder.out" , "w", stdout);

   int n, k(0);
   scanf("%d", &n);

   int *a = new int[100000];
   int *b = new int[100000];
   int *c = new int[100000];
   int *d = new int[100000];

   int *flag = new int[n];
   int ia, ib;

   for (int i = 0; i < n; i++) {
    scanf ("%d %d", &a[i], &b[i]);
    flag[i] = 0;
   }

   for (int i = 0; i < n; i++) {
    c[a[i]-1] = i+1;
    d[b[i]-1] = i+1;

   }/*
for (int i = 0; i < n; i++) {
cout << c[i] << " ";

}
cout << endl;


for (int i = 0; i <= n; i++) {

cout << d[i] << " ";
}
cout << endl;
*/

   for (int j = 0; j < n; j++) {
    int i = 0;

   while (c[i] != j+1) {
        if (c[i] != 0) {
        k++;
        flag[i] =1;
        }
        i++;

   }

   i = 0;

   while (d[i] != j+1) {
        if (d[i] != 0) {
    if (flag[i] != 1)
        k++;
        }
    i++;

   }

   for (int i = 0; i < n; i++) {
        flag[i] = 0;
   }
   cout << k << endl;
   k = 0;
   }
    return 0;
}

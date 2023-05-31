#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main() {
    freopen("java2016.in","r",stdin);
    freopen("java2016.out","w",stdout);
    int n;
    cin >> n;
    if (n == 0) {
    	cout << "?/?/?" << endl;
    	return 0;
    }
    cout << "a=?max?" << endl;
    cout << "b=(a max a) / a" << endl;	 // 1
   	cout << "c=b+b" << endl;                 // 2   
   	cout << "d=c+c" << endl;                     //4
   	cout << "e=d+d" << endl;                     //8 
   	cout << "f=d*d" << endl;                     //16 
   	cout << "g=d*e" << endl;                     //32
                                                       
   	cout << "h=e*e" << endl;                     //64

   	cout << "i=e*f" << endl;                     //128
   	vector<char> ans;
   	for (int i = 0; i < 10; i++) {
   		if ((n & (1 << i)) != 0) {
   			ans.pb((char)('b' + i));	
   		}
   	}
   	for (int i = 0; i + 1 < (int)ans.size(); i++) {
   		cout << ans[i] << "+";
   	}
   	cout << ans.back();
   	cout << endl;
	return 0;
}
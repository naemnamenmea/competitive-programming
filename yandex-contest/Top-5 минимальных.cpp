#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	multiset<int> mset;
	multiset<int>::reverse_iterator rit;
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		mset.insert(tmp);
		if (i >= 5) {
			mset.erase(prev(mset.end()));
		}		
		rit = mset.rbegin();
		for (int j = min(i,4); j > 0; j--) {
			cout << (*rit) << " ";
			rit++;
		}
		cout << (*rit) << endl;
	}
    return 0;
}
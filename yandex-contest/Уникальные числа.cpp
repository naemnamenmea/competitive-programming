#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	set<int> s;
	cin >> n;
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		s.insert(input);
	}
	cout << s.size() << endl;
    return 0;
}
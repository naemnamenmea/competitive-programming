#include<iostream>
#include<math.h>
#include <vector>
#include<algorithm>
using namespace std;

pair<int, int> A[100001], B[100001],C[100001];
int n,ans[100001];

int func(int pos, int type,int pa=-1){
	int ans1 = 0;
	if (type == 1){
		int i = upper_bound(B, B + n, make_pair(pos, 0)) - B;
		while (i >= 0 && B[i].first > pos)
			i--;
		if (pa==-1 || pa<i)
			i = func(B[i].second, 2,i);
		return i;
	}
	else{
		int i = upper_bound(C, C + n, make_pair(pos, 0)) - C;
		while (i >= 0 && C[i].first > pos)
			i--;
		if (pa == -1 || pa<i)
			i = func(C[i].second, 1, i);
		return i;
	}
}

int main()
{
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> A[i].first >> A[i].second;
	for (int i = 0; i < n; i++)
		B[i] = A[i];
	sort(B, B + n);
	for (int i = 1; i < n; i++)
		B[i].second = max(B[i - 1].second, B[i].second);
	for (int i = 0; i < n; i++){
		C[i].first = A[i].second;
		C[i].second = A[i].first;
	}
	sort(C, C + n);
	for (int i = 1; i < n; i++)
		C[i].second = max(C[i - 1].second, C[i].second);
	for (int i = 0; i < n; i++){
		if (A[i].second >= A[i].first)
			ans[i] = max(ans[i],func(A[i].second, 2));
		if(A[i].second <= A[i].first)
			ans[i] = max(ans[i], func(A[i].first, 1));
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
	return 0;
}
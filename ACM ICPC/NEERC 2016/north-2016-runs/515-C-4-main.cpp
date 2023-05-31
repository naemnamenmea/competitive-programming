#include "bits/stdc++.h"
using namespace std;

int n;

void f(vector<pair<int,int>> &nums, int ii, vector<bool> &check, int* arr, int* answ)
{
  check[ii] = true;
  int maxind = arr[ii];
  int countt = 0;

  vector<bool> wasornot(n);

  for (int i = arr[ii]; i > -1; --i)
  {
    if (arr[nums[i].second] > maxind) maxind = arr[nums[i].second];
    if (!wasornot[nums[i].second]) wasornot[nums[i].second] = true;
    else countt++;
  }
  if (maxind > arr[ii])
  {
    if (check[nums[maxind].second]) answ[ii] = answ[nums[maxind].second];
    else {
        f(nums,nums[maxind].second,check,arr,answ);
        answ[ii] = answ[nums[maxind].second];
    }
  }
  else
  {
    answ[ii] = countt;
  }
}

int main()
{
  freopen("codecoder.in","r",stdin);
  freopen("codecoder.out","w",stdout);
  int x,y;
  vector<pair<int,int>> nums;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    nums.push_back(make_pair(x,i));
    nums.push_back(make_pair(y,i));
  }
  sort(nums.begin(),nums.end());
  vector<bool> check;
  for (int i = 0; i < n; ++i)
    check.push_back(false);

  /*for (int i = 0; i < 2*n; ++i)
  {
    cout << nums[i].first << " " << nums[i].second <<endl;
  }*/

  int* indexes;
  indexes = new int[n];
  for (int i = 0; i < 2*n; ++i)
  {
    if (!check[nums[i].second]) check[nums[i].second] = true;
    else indexes[nums[i].second] = i;
  }
  for (int i = 0; i < n; ++i)
    check[i] = false;

  int* answ;
  answ = new int[n];

  for (int i = 0; i < 2*n; ++i)
    if (!check[nums[i].second]) f(nums,nums[i].second,check,indexes,answ);


  for (int i = 0; i < n; ++i) cout << answ[i] - 1 << " ";
  delete [] indexes;
  delete [] answ;
  return 0;
}

#include <iostream>
#include <stdio.h>

using namespace std;

int main (void)
{
  freopen("folding.in","r",stdin);
  freopen("folding.out","w",stdout);

  long int a,b,A,B,result=0, A1, B1;

  long int i=0;

  cin>>A>>B>>a>>b;
  A1=A; B1=B;
  if((a>A && a>B) || (b>A && b>B))
  {
    cout<<-1;
    return 0;
  }
  i=0;

  while(a!=A)
  {
    if(A/2>=a)
    {
      A=A-A/2;
      i++;
    }
    else
    {
      i++;
      break;

    }
  }
  while(b!=B)
  {
    if(B/2>=b)
    {
      B=B-B/2;
      i++;
    }
    else
    {
      i++;
      break;

    }
  }
  result = i;
    A=B1;
    B=A1;
 i = 0;
    while(a!=A)
  {
    if(A/2>=a)
    {
      A=A-A/2;
      i++;
    }
    else
    {
      i++;
      break;

    }
  }
  while(b!=B)
  {
    if(B/2>=b)
    {
      B=B-B/2;
      i++;
    }
    else
    {
      i++;
      break;

    }
  }
  if (result<i) cout << result;
  else cout<<i;

  fclose(stdin);
  fclose(stdout);

  return 0;
}

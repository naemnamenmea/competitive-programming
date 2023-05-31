#include <iostream>
#include <stdio.h>

using namespace std;

int main (void)
{
  freopen("folding.in","r",stdin);
  freopen("folding.out","w",stdout);

  long int a,b,A,B,result=0;

  long int i=0;

  cin>>A>>B>>a>>b;
  if((a>A && a>B) || (b>A && b>B))
  {
    cout<<-1;
    return 0;
  }

  if(a>b)
  {
    i=a;
    a=b;
    b=i;
  }

  if(A>B)
  {
    i=A;
    A=B;
    B=i;
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

  cout<<i;

  fclose(stdin);
  fclose(stdout);

  return 0;
}

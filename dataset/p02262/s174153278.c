#include <stdio.h>

int cnt = 0;

void Insert(int A[],int n,int g)
{
  int i,j,v;

  for(i = g;i < n;i++)
  {
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v)
    {
      A[j + g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void Shell(int A[],int n)
{
  int i,m,h,G[100];

  for(i = 0,h = 1;i < n;i++)
  {
    if(h > n) break;
    G[i] = h;
    h = 3 * h + 1;
  }
  m = i;

  printf("%d\n",m);
  for(i = m - 1;i >= 0;i--)
  {
    printf("%d",G[i]);
    if(i) printf(" ");
  }
  printf("\n");

  for(i = m - 1;i >= 0;i--) Insert(A,n,G[i]);
}

int main()
{
  int i,n,A[1000000];

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&A[i]);

  Shell(A,n);

  printf("%d\n",cnt);
  for(i = 0;i < n;i++)
  {
    printf("%d\n",A[i]);
  }

  return 0;
}


#include <stdio.h>
#define N 1000000
void insertionSort(int *, int,int);
void shellSort(int *,int);
int cnt = 0;
int main()
{
  int i,n;
  int A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
    shellSort(A,n);
    for(i=0;i<n;i++)
    {
      printf("%d\n",A[i]);
    }
    return 0;
}

void insertionSort(int A[],int n,int g)
{
  int i,j,k;
  for(i=g;i<=n-1;i++)
  {
    k=A[i];
    j=i-g;
    while((j >= 0) && (A[j] > k))
    {
      A[j+g] = A[j];
      j-=g;
      cnt++;
      A[j+g] = k;
    }
  }
}

void shellSort(int A[],int n)
{
  int h=1,i,G[N];
  G[0]=1;
  while(1)
  {
    G[i+1] = 3*G[i] + 1;
    if(G[i+1] > n)
      {
        break;
      }
        h++;
        i++;
  }
  for(i = h-1; i >= 0; i--)
  {
    insertionSort(A,n,G[i]);
  }

  printf("%d\n",h);
  for(i = h-1; i > 0; i--)
  {
    printf("%d ",G[i]);
  }

  printf("%d\n",G[i]);
  printf("%d\n",cnt);
}


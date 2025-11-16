#include<stdio.h>

int cnt = 0;

void insertionSort(int [],int, int);
void shellSort(int [],int);

int main()
{
  int n,i,A[1000000];

  scanf("%d",&n);

  for(i = 0;i < n;i++)
    scanf("%d",&A[i]);

  shellSort(A,n);

  printf("%d\n",cnt);

  for(i = 0;i < n;i++)
    printf("%d\n",A[i]);

  return 0;
}

void insertionSort(int A[],int n,int g)
{
  int i,j,v;

  for(i = g;i <= n - 1;i++)
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

void shellSort(int A[],int n)
{
  int i = 0,m = 0,G[n];
  
  cnt = 0;
  G[0] = 0;
  
  while(1)
    {
      if(n < 3 * G[m] + 1) break;
      G[m + 1] = 3 * G[m] + 1;
      m++;
    }

  printf("%d\n",m);

  for(i = m;i >= 1;i--)
    printf("%d ",G[i]);
  printf("\n");

  for(i = m;i > 0;i--)
    insertionSort(A,n,G[i]);
}
  
  


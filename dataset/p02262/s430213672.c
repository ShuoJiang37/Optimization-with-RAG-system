#include<stdio.h>
#include<stdlib.h>

int A[1000000], *G;

void insertionSort(int n, int g, int *cnt)
{
  int i, v, j;
  for(i = g; i < n; i++)
    {
      v = A[i];
      j = i - g;
      while(j > -1 && A[j] > v)
	{
	  A[j+g] = A[j];
	  j = j - g;
	  ++*cnt;
	}
      A[j+g] = v;
    }
}

void shellSort(int n)
{
  int cnt = 0, m, i, j = 0;
  G = malloc(n * sizeof(int));
  for(i = 1;;)
    {
      if(i > n)
	{
	  break;
	}
      G[j] = i;
      j++;
      i = 3 * i + 1;
    }
  m = j;
  for(i = m - 1; i >= 0; i--)
    {
      insertionSort(n, G[i], &cnt);
    }
  printf("%d\n", m);
  for(i = m - 1; i >= 0; i--)
    {
      printf("%d", G[i]);
      if(i) printf(" ");
    }
  printf("\n%d\n", cnt);
  for(i = 0; i < n; i++)
    {
      printf("%d\n", A[i]);
    }
}

int main()
{
  int n, i;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      scanf("%d", &A[i]);
    }
  shellSort(n);
  return 0;
}


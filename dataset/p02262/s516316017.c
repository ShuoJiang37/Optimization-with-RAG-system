#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count;

void insertionSort(int *, int, int);
void shellSort(int *, int);

int main(void)
{
  int n, *A, i;
  scanf(" %d", &n);
  A = (int *) malloc(sizeof(int[n]));
  for (i = 0; i < n; i++)
    scanf(" %d", A + i);
  shellSort(A, n);
  printf("%d\n", count);
  for (i = 0; i < n; i++)
    printf("%d\n", A[i]);
  return 0;
}

void insertionSort(int *A, int n, int g)
{
  int i;
  for (i = g; i < n; i++)
    {
      int value = A[i];
      int j = i - g;
      while (j >= 0 && A[j] > value)
	{
	  A[j+g] = A[j];
	  j = j - g;
	  count++;
	}
      A[j+g] = value;
    }
}

void shellSort(int *A, int n)
{
  count = 0;
  int m = (int) log((double) n);
  if (m == 0)
    m = 1;
  printf("%d\n", m);
  int i;
  int *G = (int *) malloc(sizeof(int[m]));
  for (i = m - 1; i >= 0; i--)
    G[i] = pow(2, m - i - 1);
  for (i = 0; i < m; i++)
    printf("%d%s", G[i], i != m - 1 ? " " : "\n");
  for (i = 0; i < m; i++)
    insertionSort(A, n, G[i]);
}


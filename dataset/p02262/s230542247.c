#include <stdio.h>

#define MAX 1000000

int cnt=0, count = 0, n;
int A[MAX], G[MAX];

void shellSort(int*, int);
void insertionSort(int*, int, int);

int main()
{
  int i, len;
  
  scanf("%d", &n);

  for( i = 0 ; i < n ; i++ ) scanf("%d", &A[i]);

  shellSort(A, n);

  printf("%d\n", count);

  for( i = count-1 ; i >= 0 ; i-- ){
    printf("%d", G[i]);
    if( i ) printf(" ");
  }
  printf("\n");
  printf("%d\n", cnt);
  for( i = 0 ; i < n ; i++ ) printf("%d\n", A[i]);

  return 0;
}

void shellSort(int A[], int n)
{
  int i, k;
  
  for( k = 1 ; ; ){
    if( k > n ) break;
    G[count] = k;
    k = 3 * k + 1;
    count++;
  }
  
  for( i = count ; i >= 0 ; i-- ) insertionSort(A, n, G[i]);
}

void insertionSort(int A[], int n, int g)
{
  int i, j, v;

  for( i = g ; i < n ; i++ ){
    v = A[i];
    j = i - g;
    while( j >= 0 && A[j] > v ){
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }
    A[j + g] = v;
  }
}
#include <stdio.h>
#include <stdlib.h>
#define M 2000001
#define k 10001

int main(){
  int *A, *B;
  int C[k];
  int n, i, j;
  scanf("%d", &n);

  A = malloc(sizeof(int) * n + 1);
  B = malloc(sizeof(int) * n + 1);

  for ( i = 0; i <= k; i++ ) C[i] = 0;

  for ( i = 0; i < n; i++ ){
    scanf("%d", &A[i + 1]);
    C[A[i + 1]]++;
  }

  for ( i = 1; i <= k; i++ ) C[i] = C[i] + C[i - 1];

  for ( j = 1; j <= n; j++ ){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

  return 0;
}
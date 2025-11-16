#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define MAX1 10000

int main(){
  unsigned short *A, *B;

  int C[MAX1+1],n,m,i, j;


  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for ( i = 0; i <= MAX1; i++ ) {
    C[i] = 0;
  }

  for ( i = 0; i < n; i++ ){
    scanf("%d", &A[i + 1]);
    m = A[i + 1];
    C[m]++;
  }

  for ( i = 1; i <= MAX1; i++ ){
    C[i] = C[i] + C[i - 1];
  }

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
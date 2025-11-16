#include <stdio.h>
#include <stdlib.h>
#define MAX 2000000
#define MAX2 10000

int main(){
  int *A, *B;

  int C[MAX2+1];
  int num, i, j;
  scanf("%d", &num);

  A = malloc(sizeof(int)*num);
  B = malloc(sizeof(int)*num);

  for ( i = 0; i <= MAX2; i++ ) C[i] = 0;

  for ( i = 0; i < num; i++ ){
    scanf("%d", &A[i + 1]);

    C[A[i + 1]]++;
  }

  for ( i = 1; i <= MAX2; i++ ) C[i] = C[i] + C[i - 1];

  for ( j = 1; j <= num; j++ ){

    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for ( i = 1; i <= num; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

  return 0;
}
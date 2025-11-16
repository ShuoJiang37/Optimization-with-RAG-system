#include <stdio.h>
#include <stdlib.h>
#define K 10000

int main(){
  int i,j,n,C[K+1];
  int *A,*B;

  scanf("%d",&n);

  A = malloc(sizeof(int)*(n+1));
  B = malloc(sizeof(int)*(n+1));

  for(i=0; i<= K; i++)
    C[i] = 0;

  for(j=1; j<=n; j++){
    scanf("%d", &A[j]);
    C[A[j]]++;
  }

  for(i=1; i<=K; i++)
    C[i] += C[i-1];

  for(j=n; j>=1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1; i<=n; i++){
    if ( i > 1 ) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

  return 0;
}
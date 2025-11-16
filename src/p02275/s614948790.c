#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int main(){
  int n, i, j, C[MAX + 1] = {0};
  unsigned short *A, *B;

  scanf("%d", &n);

  A = malloc(sizeof(short) *n+1);
  B = malloc(sizeof(short) *n+1);

  for(i = 0; i < n; i++)
    scanf("%hu", &A[i]);

  for(i = 0; i < n; i++)
    C[A[i]]++;

  for(i = 1; i <= MAX; i++)
    C[i] = C[i] + C[i - 1];

  for(j = n - 1; j >= 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  
  for(i = 1; i < n; i++)
    printf("%d ", B[i]);
  printf("%d\n", B[n]);
  
  return 0;
}
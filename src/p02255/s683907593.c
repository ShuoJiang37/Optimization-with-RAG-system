#include <stdio.h>
#include <stdlib.h>

int main(){
  int N, i, j, v, k;
  int A[100];

  scanf("%d", &N);
  if(N < 0 || 100 < N)
    exit(1);
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
    if(A[i] < 0 || 1000 < A[i])
      exit(2);
  }
  for(k = 0; k < N-1; k++)
    printf("%d ", A[k]);
  printf("%d\n", A[k]);
  
  for(i = 1; i < N; i++){
    v = A[i];
    j = i - 1;
    while(0 <= j && v < A[j]){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k = 0; k < N-1; k++)
      printf("%d ", A[k]);
    printf("%d\n", A[k]);
  }

  return 0;
}
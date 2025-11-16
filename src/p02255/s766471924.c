#include<stdio.h>

int main(){
  int N, i, j, k, l, key, A[100];
  
  scanf("%d", &N);

  for (i = 0; i < N; i++) scanf("%d", &A[i]);
  
  for(i = 0; i < N; i++){
    if(i != 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");

  for(j = 1; j <= N - 1; j++){
    key = A[j];
    k = j - 1;
    while(k >= 0 && A[k] > key){
      A[k + 1] = A[k];
      k--;
    }
    A[k + 1] = key;

    for(i = 0; i < N; i++){
      if(i != 0) printf(" ");
      printf("%d", A[i]);
    }
    printf("\n");

  }

  return 0;
}
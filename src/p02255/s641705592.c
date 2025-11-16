#include <stdio.h>
#include <stdlib.h>

void insertionSort(int A[], int N){
  int i, v, j, k;
  for(i = 1; i < N; i++){
    for(k = 0; k < N; k++){
      printf("%d",A[k]);
      if(k <= N-2) {printf(" ");}
      else{printf("\n");}
    }
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
}


int main(void){
  int i, n;
  scanf("%d", &n);
  int *a;
  a = malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  insertionSort(a, n);
  for(i = 0; i < n; i++){
    printf("%d",a[i]);
    if(i <= n-2) {printf(" ");}
    else{printf("\n");}
  }
  return 0;
}
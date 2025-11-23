#include <stdio.h>

#define MAX_N 2000001
#define MAX_K 10001

void countingSort(int,int*);

int main(){
  int n,i;
  static int A[MAX_N];
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }
  countingSort(n,A);
  return 0;
}

void countingSort(int n,int *A){
  int i,C[MAX_K] = {0};
  static int B[MAX_N];
  for(i = 0 ; i < n ; i++){ C[A[i]]++; }
  for(i = 1 ; i < MAX_K ; i++){ C[i] += C[i-1]; }
  for(i = n-1 ; i >= 0 ; i--){
    B[C[A[i]]] = A[i]; C[A[i]]--;
  }
  for(i = 0 ; i < n ; i++){
    printf("%d%c",B[i+1],i != n-1 ? ' ' : '\n');
  }
}
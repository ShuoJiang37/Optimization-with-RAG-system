#include<stdio.h>
#include<stdlib.h>

void CountingSort(int);
int n;
int A[2000001], B[2000001];

int main(){
  int i;
  int Amax=0;

  scanf("%d", &n);
  if(n < 1 || 2000000 < n)
    exit(0);

  for(i = 1; i <= n; i++){
    scanf("%d", &A[i]);
    if(A[i] < 0 || 10000 < A[i])
      exit(1);
    if(Amax < A[i])
      Amax = A[i];
  }

  CountingSort(Amax);

  for(i = 1; i <= n; i++){
    if(i == n)
      printf("%d\n", B[i]);
    else
      printf("%d ", B[i]);
  }

  return 0;
}

void CountingSort(int k){
  int i, j;
  int C[2000001];

  for(i = 0; i <= k; i++)
    C[i] = 0;
  
  for(j = 1; j <= n; j++)
    C[A[j]]++;

  for(i = 1; i <= k; i++)
    C[i] += C[i-1];

  for(j = n; 1 <= j; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

}
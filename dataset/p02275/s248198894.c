#include <stdio.h>
#include <stdlib.h>
void CountingSort(int *,int *,int);
int C[10001]={0},i;
int main(void){
  int n,*A,*B;
  scanf("%d",&n);
  A=(int *)malloc(sizeof(int)*n);
  B=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  
  CountingSort(A,B,n);
  for(i=0;i<n;i++){
    printf("%d",B[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  return 0;
}
void CountingSort(int *A,int *B,int k){
  /*C[i]にiの出現数を記録する */
  i=0;
  while(i<k){
    C[A[i++]]++;
  }

  /*C[i]にi以下の数の出現数を記録する*/
  i=0;
  while(i<10001){
    C[i]=C[i]+C[i-1];
    i++;
  }

  for(i=k-1;i>=0;i--){
    B[C[A[i]]-1]=A[i];
    C[A[i]]--;
  }
}

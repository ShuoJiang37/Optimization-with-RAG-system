#include<stdio.h>
#include<stdlib.h>


int main(){
  int i,n;
  int *A,*B,C[10001]={};
  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  B=malloc((n+1)*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    C[A[i]]++;
  }
  for(i=1;i<=10000;i++) C[i]+=C[i-1];
  for(i=0;i<n;i++){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
  for(i=1;i<n;i++) printf("%d ",B[i]);
  printf("%d\n",B[n]);
  return 0;
}
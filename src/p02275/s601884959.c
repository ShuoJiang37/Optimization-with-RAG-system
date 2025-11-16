#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000


int main(){
  int *A,*B;
  int C[VMAX+1];
  int n,i,j;
  int k=0;

  scanf("%d",&n);

  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i]>k)k=A[i];
  }
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=0;j<n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n-1;j>=0;j--){
    B[C[A[j]] - 1]=A[j];
    C[A[j]]--;
  }
  for(i=0;i<n;i++){
  printf("%d",B[i]);
  if(i<n-1)printf(" ");
  }
  printf("\n");
  return 0;
}


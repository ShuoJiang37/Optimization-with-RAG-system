#include<stdio.h>
#define X 10000
int A[2000001],C[X],B[2000001];
int main()
{
  int j,n;
  
  scanf("%d",&n);
  for(j=1;j<n+1;j++){
    scanf("%d",&A[j]);
  }
 
  for(j=0;j<X;j++){
    C[j]=0;
  }
  
  for(j=1;j<n+1;j++){
    C[A[j]]+=1;
  }
  
  for(j=0;j<X;j++){
    C[j]+=C[j-1];
  }
  
  for(j=n+1;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]-=1;
  }
 
  for(j=1;j<n;j++){
    printf("%d ",B[j]);
  }
  
  printf("%d",B[j]);
  printf("\n");
  return 0;
}
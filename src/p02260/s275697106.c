#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
  int n;
  int i,j;
  int *A;
  int mini;
  int count=0;
  int swap;
  
  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(A[j] < A[mini]) mini=j;
    }
    if(i!=mini){
      swap=A[i];
      A[i]=A[mini];
      A[mini]=swap;
      count+=1;
    }
  }
  
  printf("%d",A[0]);
  for(i=1;i<n;i++) printf(" %d",A[i]);
  printf("\n%d\n",count);
  return 0;
}
